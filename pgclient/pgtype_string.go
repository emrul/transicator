/*
Copyright 2016 The Transicator Authors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
// Code generated by "stringer -type PgType ."; DO NOT EDIT

package pgclient

import "fmt"

const (
	_PgType_name_0 = "Bytea"
	_PgType_name_1 = "Int8Int2"
	_PgType_name_2 = "Int4"
	_PgType_name_3 = "OID"
	_PgType_name_4 = "Float4Float8"
	_PgType_name_5 = "TimestampTZ"
)

var (
	_PgType_index_0 = [...]uint8{0, 5}
	_PgType_index_1 = [...]uint8{0, 4, 8}
	_PgType_index_2 = [...]uint8{0, 4}
	_PgType_index_3 = [...]uint8{0, 3}
	_PgType_index_4 = [...]uint8{0, 6, 12}
	_PgType_index_5 = [...]uint8{0, 11}
)

func (i PgType) String() string {
	switch {
	case i == 17:
		return _PgType_name_0
	case 20 <= i && i <= 21:
		i -= 20
		return _PgType_name_1[_PgType_index_1[i]:_PgType_index_1[i+1]]
	case i == 23:
		return _PgType_name_2
	case i == 26:
		return _PgType_name_3
	case 700 <= i && i <= 701:
		i -= 700
		return _PgType_name_4[_PgType_index_4[i]:_PgType_index_4[i+1]]
	case i == 1184:
		return _PgType_name_5
	default:
		return fmt.Sprintf("PgType(%d)", i)
	}
}
