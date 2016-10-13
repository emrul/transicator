package common

import (
	"encoding/json"

	"github.com/golang/protobuf/proto"
)

const (
	indentPrefix = ""
	indent       = "  "
)

/*
UnmarshalSnapshot turns a set of JSON into an entire snapshot.
*/
func UnmarshalSnapshot(data []byte) (*Snapshot, error) {
	var s Snapshot
	err := json.Unmarshal(data, &s)
	if err == nil {
		return &s, nil
	}
	return nil, err
}

/*
Marshal turns a snapshot into formatted, indented JSON. It will panic
on a marshaling error.
*/
func (s *Snapshot) Marshal() []byte {
	data, err := json.MarshalIndent(s, indentPrefix, indent)
	if err == nil {
		return data
	}
	panic(err.Error())
}

/*
UnmarshalChangeList turns a set of JSON into an entire change list.
*/
func UnmarshalChangeList(data []byte) (*ChangeList, error) {
	var l ChangeList
	err := json.Unmarshal(data, &l)
	if err == nil {
		return &l, nil
	}
	return nil, err
}

/*
UnmarshalChangeListProto does the same unmarshaling but from a protobuf.
*/
func UnmarshalChangeListProto(data []byte) (*ChangeList, error) {
	var clpb ChangeListPb
	err := proto.Unmarshal(data, &clpb)
	if err != nil {
		return nil, err
	}

	cl := ChangeList{
		FirstSequence: clpb.GetFirstSequence(),
		LastSequence:  clpb.GetLastSequence(),
	}

	for _, cpb := range clpb.GetChanges() {
		c := unconvertChangeProto(cpb)
		cl.Changes = append(cl.Changes, *c)
	}

	return &cl, nil
}

/*
Marshal turns a change list into formatted, indented JSON. It will panic
on a marshaling error.
*/
func (l *ChangeList) Marshal() []byte {
	data, err := json.MarshalIndent(l, indentPrefix, indent)
	if err == nil {
		return data
	}
	panic(err.Error())
}

/*
MarshalProto does the same as Marshal but it makes a protobf.
*/
func (l *ChangeList) MarshalProto() []byte {
	pb := &ChangeListPb{
		FirstSequence: proto.String(l.FirstSequence),
		LastSequence:  proto.String(l.LastSequence),
	}

	for _, c := range l.Changes {
		cpb := c.convertProto()
		pb.Changes = append(pb.Changes, cpb)
	}

	buf, err := proto.Marshal(pb)
	if err != nil {
		panic(err.Error())
	}
	return buf
}

/*
UnmarshalChange just handles a single "Change." This is what we get from the
Postgres replication stream.
*/
func UnmarshalChange(data []byte) (*Change, error) {
	var c Change
	err := json.Unmarshal(data, &c)
	if err == nil {
		return &c, nil
	}
	return nil, err
}

/*
UnmarshalChangeProto turns a protobuf version of a Change into a Change.
*/
func UnmarshalChangeProto(data []byte) (*Change, error) {
	var cp ChangePb
	err := proto.Unmarshal(data, &cp)
	if err != nil {
		return nil, err
	}

	return unconvertChangeProto(&cp), nil
}

func unconvertChangeProto(cp *ChangePb) *Change {
	c := &Change{
		Operation:      Operation(cp.GetOperation()),
		Table:          cp.GetTable(),
		Sequence:       cp.GetSequence(),
		CommitSequence: cp.GetCommitSequence(),
		CommitIndex:    cp.GetCommitIndex(),
		ChangeSequence: cp.GetChangeSequence(),
		TransactionID:  cp.GetTransactionID(),
	}

	if len(cp.GetNewColumns()) > 0 {
		c.NewRow = makeRow(cp.GetNewColumns())
	}
	if len(cp.GetOldColumns()) > 0 {
		c.OldRow = makeRow(cp.GetOldColumns())
	}
	return c
}

func makeRow(cols []*ColumnPb) Row {
	row := make(map[string]*ColumnVal)
	for _, colPb := range cols {
		cv := &ColumnVal{
			Type:  colPb.GetType(),
			Value: unwrapColumnVal(colPb.GetValue()),
		}
		row[colPb.GetName()] = cv
	}
	return row
}

func unwrapColumnVal(v *ValuePb) interface{} {
	if v == nil {
		return nil
	}
	pv := v.GetValue()
	if pv == nil {
		return nil
	}
	switch pv.(type) {
	case *ValuePb_String_:
		return v.GetString_()
	case *ValuePb_Int:
		return v.GetInt()
	case *ValuePb_Uint:
		return v.GetUint()
	case *ValuePb_Double:
		return v.GetDouble()
	case *ValuePb_Bool:
		return v.GetBool()
	case *ValuePb_Bytes:
		return v.GetBytes()
	default:
		panic("Invalid data type in protobuf")
	}
}

/*
Marshal turns a Change into JSON.
*/
func (c *Change) Marshal() []byte {
	data, err := json.MarshalIndent(c, indentPrefix, indent)
	if err == nil {
		return data
	}
	panic(err.Error())
}

/*
MarshalProto turns a Change into a protobuf.
*/
func (c *Change) MarshalProto() []byte {
	buf, err := proto.Marshal(c.convertProto())
	if err != nil {
		panic(err.Error())
	}
	return buf
}

func (c *Change) convertProto() *ChangePb {
	cp := &ChangePb{
		Operation: proto.Int32(int32(c.Operation)),
		Table:     proto.String(c.Table),
	}
	if c.Sequence != "" {
		cp.Sequence = proto.String(c.Sequence)
	}
	if c.CommitSequence != 0 {
		cp.CommitSequence = proto.Uint64(c.CommitSequence)
	}
	if c.ChangeSequence != 0 {
		cp.ChangeSequence = proto.Uint64(c.ChangeSequence)
	}
	if c.CommitIndex != 0 {
		cp.CommitIndex = proto.Uint32(c.CommitIndex)
	}
	if c.TransactionID != 0 {
		cp.TransactionID = proto.Uint32(c.TransactionID)
	}
	cp.NewColumns = unmakeRow(c.NewRow)
	cp.OldColumns = unmakeRow(c.OldRow)
	return cp
}

func unmakeRow(row Row) []*ColumnPb {
	var cols []*ColumnPb
	for name, v := range row {
		cpb := &ColumnPb{
			Name: proto.String(name),
		}
		if v != nil {
			v := &ValuePb{
				Value: convertParameter(v.Value),
			}
			cpb.Value = v
		}
		if v.Type != 0 {
			cpb.Type = proto.Int32(v.Type)
		}
		cols = append(cols, cpb)
	}
	return cols
}

/*
AddTables is a helper function that inserts Tables in to a existing Snapshot
*/
func (s *Snapshot) AddTables(tb Table) []Table {
	s.Tables = append(s.Tables, tb)
	return s.Tables
}

/*
AddRowstoTable is a helper function that inserts rows to an existing table
*/
func (sid *Table) AddRowstoTable(rv Row) []Row {
	sid.Rows = append(sid.Rows, rv)
	return sid.Rows
}
