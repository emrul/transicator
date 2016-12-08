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
/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: transicator.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "transicator.pb-c.h"
void   common__value_pb__init
                     (Common__ValuePb         *message)
{
  static Common__ValuePb init_value = COMMON__VALUE_PB__INIT;
  *message = init_value;
}
size_t common__value_pb__get_packed_size
                     (const Common__ValuePb *message)
{
  assert(message->base.descriptor == &common__value_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__value_pb__pack
                     (const Common__ValuePb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__value_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__value_pb__pack_to_buffer
                     (const Common__ValuePb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__value_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__ValuePb *
       common__value_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__ValuePb *)
     protobuf_c_message_unpack (&common__value_pb__descriptor,
                                allocator, len, data);
}
void   common__value_pb__free_unpacked
                     (Common__ValuePb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__value_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__column_pb__init
                     (Common__ColumnPb         *message)
{
  static Common__ColumnPb init_value = COMMON__COLUMN_PB__INIT;
  *message = init_value;
}
size_t common__column_pb__get_packed_size
                     (const Common__ColumnPb *message)
{
  assert(message->base.descriptor == &common__column_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__column_pb__pack
                     (const Common__ColumnPb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__column_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__column_pb__pack_to_buffer
                     (const Common__ColumnPb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__column_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__ColumnPb *
       common__column_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__ColumnPb *)
     protobuf_c_message_unpack (&common__column_pb__descriptor,
                                allocator, len, data);
}
void   common__column_pb__free_unpacked
                     (Common__ColumnPb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__column_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__change_pb__init
                     (Common__ChangePb         *message)
{
  static Common__ChangePb init_value = COMMON__CHANGE_PB__INIT;
  *message = init_value;
}
size_t common__change_pb__get_packed_size
                     (const Common__ChangePb *message)
{
  assert(message->base.descriptor == &common__change_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__change_pb__pack
                     (const Common__ChangePb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__change_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__change_pb__pack_to_buffer
                     (const Common__ChangePb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__change_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__ChangePb *
       common__change_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__ChangePb *)
     protobuf_c_message_unpack (&common__change_pb__descriptor,
                                allocator, len, data);
}
void   common__change_pb__free_unpacked
                     (Common__ChangePb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__change_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__change_list_pb__init
                     (Common__ChangeListPb         *message)
{
  static Common__ChangeListPb init_value = COMMON__CHANGE_LIST_PB__INIT;
  *message = init_value;
}
size_t common__change_list_pb__get_packed_size
                     (const Common__ChangeListPb *message)
{
  assert(message->base.descriptor == &common__change_list_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__change_list_pb__pack
                     (const Common__ChangeListPb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__change_list_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__change_list_pb__pack_to_buffer
                     (const Common__ChangeListPb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__change_list_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__ChangeListPb *
       common__change_list_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__ChangeListPb *)
     protobuf_c_message_unpack (&common__change_list_pb__descriptor,
                                allocator, len, data);
}
void   common__change_list_pb__free_unpacked
                     (Common__ChangeListPb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__change_list_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__snapshot_header_pb__init
                     (Common__SnapshotHeaderPb         *message)
{
  static Common__SnapshotHeaderPb init_value = COMMON__SNAPSHOT_HEADER_PB__INIT;
  *message = init_value;
}
size_t common__snapshot_header_pb__get_packed_size
                     (const Common__SnapshotHeaderPb *message)
{
  assert(message->base.descriptor == &common__snapshot_header_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__snapshot_header_pb__pack
                     (const Common__SnapshotHeaderPb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__snapshot_header_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__snapshot_header_pb__pack_to_buffer
                     (const Common__SnapshotHeaderPb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__snapshot_header_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__SnapshotHeaderPb *
       common__snapshot_header_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__SnapshotHeaderPb *)
     protobuf_c_message_unpack (&common__snapshot_header_pb__descriptor,
                                allocator, len, data);
}
void   common__snapshot_header_pb__free_unpacked
                     (Common__SnapshotHeaderPb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__snapshot_header_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__table_header_pb__init
                     (Common__TableHeaderPb         *message)
{
  static Common__TableHeaderPb init_value = COMMON__TABLE_HEADER_PB__INIT;
  *message = init_value;
}
size_t common__table_header_pb__get_packed_size
                     (const Common__TableHeaderPb *message)
{
  assert(message->base.descriptor == &common__table_header_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__table_header_pb__pack
                     (const Common__TableHeaderPb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__table_header_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__table_header_pb__pack_to_buffer
                     (const Common__TableHeaderPb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__table_header_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__TableHeaderPb *
       common__table_header_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__TableHeaderPb *)
     protobuf_c_message_unpack (&common__table_header_pb__descriptor,
                                allocator, len, data);
}
void   common__table_header_pb__free_unpacked
                     (Common__TableHeaderPb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__table_header_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__row_pb__init
                     (Common__RowPb         *message)
{
  static Common__RowPb init_value = COMMON__ROW_PB__INIT;
  *message = init_value;
}
size_t common__row_pb__get_packed_size
                     (const Common__RowPb *message)
{
  assert(message->base.descriptor == &common__row_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__row_pb__pack
                     (const Common__RowPb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__row_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__row_pb__pack_to_buffer
                     (const Common__RowPb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__row_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__RowPb *
       common__row_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__RowPb *)
     protobuf_c_message_unpack (&common__row_pb__descriptor,
                                allocator, len, data);
}
void   common__row_pb__free_unpacked
                     (Common__RowPb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__row_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__stream_message_pb__init
                     (Common__StreamMessagePb         *message)
{
  static Common__StreamMessagePb init_value = COMMON__STREAM_MESSAGE_PB__INIT;
  *message = init_value;
}
size_t common__stream_message_pb__get_packed_size
                     (const Common__StreamMessagePb *message)
{
  assert(message->base.descriptor == &common__stream_message_pb__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__stream_message_pb__pack
                     (const Common__StreamMessagePb *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__stream_message_pb__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__stream_message_pb__pack_to_buffer
                     (const Common__StreamMessagePb *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__stream_message_pb__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__StreamMessagePb *
       common__stream_message_pb__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__StreamMessagePb *)
     protobuf_c_message_unpack (&common__stream_message_pb__descriptor,
                                allocator, len, data);
}
void   common__stream_message_pb__free_unpacked
                     (Common__StreamMessagePb *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &common__stream_message_pb__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor common__value_pb__field_descriptors[6] =
{
  {
    "string",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, string),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "int",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT64,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, int_),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "uint",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT64,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, uint),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "double",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_DOUBLE,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, double_),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "bytes",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, bytes),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "bool",
    6,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BOOL,
    offsetof(Common__ValuePb, value_case),
    offsetof(Common__ValuePb, bool_),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__value_pb__field_indices_by_name[] = {
  5,   /* field[5] = bool */
  4,   /* field[4] = bytes */
  3,   /* field[3] = double */
  1,   /* field[1] = int */
  0,   /* field[0] = string */
  2,   /* field[2] = uint */
};
static const ProtobufCIntRange common__value_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor common__value_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.ValuePb",
  "ValuePb",
  "Common__ValuePb",
  "common",
  sizeof(Common__ValuePb),
  6,
  common__value_pb__field_descriptors,
  common__value_pb__field_indices_by_name,
  1,  common__value_pb__number_ranges,
  (ProtobufCMessageInit) common__value_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__column_pb__field_descriptors[3] =
{
  {
    "name",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ColumnPb, name),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Common__ColumnPb, value),
    &common__value_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "type",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(Common__ColumnPb, has_type),
    offsetof(Common__ColumnPb, type),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__column_pb__field_indices_by_name[] = {
  0,   /* field[0] = name */
  2,   /* field[2] = type */
  1,   /* field[1] = value */
};
static const ProtobufCIntRange common__column_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor common__column_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.ColumnPb",
  "ColumnPb",
  "Common__ColumnPb",
  "common",
  sizeof(Common__ColumnPb),
  3,
  common__column_pb__field_descriptors,
  common__column_pb__field_indices_by_name,
  1,  common__column_pb__number_ranges,
  (ProtobufCMessageInit) common__column_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__change_pb__field_descriptors[11] =
{
  {
    "operation",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Common__ChangePb, operation),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "table",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChangePb, table),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sequence",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChangePb, sequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "commitSequence",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT64,
    offsetof(Common__ChangePb, has_commitsequence),
    offsetof(Common__ChangePb, commitsequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "changeSequence",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT64,
    offsetof(Common__ChangePb, has_changesequence),
    offsetof(Common__ChangePb, changesequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "commitIndex",
    6,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Common__ChangePb, has_commitindex),
    offsetof(Common__ChangePb, commitindex),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "transactionID",
    7,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT32,
    offsetof(Common__ChangePb, has_transactionid),
    offsetof(Common__ChangePb, transactionid),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "newColumns",
    8,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__ChangePb, n_newcolumns),
    offsetof(Common__ChangePb, newcolumns),
    &common__column_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "oldColumns",
    9,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__ChangePb, n_oldcolumns),
    offsetof(Common__ChangePb, oldcolumns),
    &common__column_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "timestamp",
    10,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT64,
    offsetof(Common__ChangePb, has_timestamp),
    offsetof(Common__ChangePb, timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "transactionIDEpoch",
    11,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_UINT64,
    offsetof(Common__ChangePb, has_transactionidepoch),
    offsetof(Common__ChangePb, transactionidepoch),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__change_pb__field_indices_by_name[] = {
  4,   /* field[4] = changeSequence */
  5,   /* field[5] = commitIndex */
  3,   /* field[3] = commitSequence */
  7,   /* field[7] = newColumns */
  8,   /* field[8] = oldColumns */
  0,   /* field[0] = operation */
  2,   /* field[2] = sequence */
  1,   /* field[1] = table */
  9,   /* field[9] = timestamp */
  6,   /* field[6] = transactionID */
  10,   /* field[10] = transactionIDEpoch */
};
static const ProtobufCIntRange common__change_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 11 }
};
const ProtobufCMessageDescriptor common__change_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.ChangePb",
  "ChangePb",
  "Common__ChangePb",
  "common",
  sizeof(Common__ChangePb),
  11,
  common__change_pb__field_descriptors,
  common__change_pb__field_indices_by_name,
  1,  common__change_pb__number_ranges,
  (ProtobufCMessageInit) common__change_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__change_list_pb__field_descriptors[3] =
{
  {
    "lastSequence",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChangeListPb, lastsequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "firstSequence",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChangeListPb, firstsequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "changes",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__ChangeListPb, n_changes),
    offsetof(Common__ChangeListPb, changes),
    &common__change_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__change_list_pb__field_indices_by_name[] = {
  2,   /* field[2] = changes */
  1,   /* field[1] = firstSequence */
  0,   /* field[0] = lastSequence */
};
static const ProtobufCIntRange common__change_list_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor common__change_list_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.ChangeListPb",
  "ChangeListPb",
  "Common__ChangeListPb",
  "common",
  sizeof(Common__ChangeListPb),
  3,
  common__change_list_pb__field_descriptors,
  common__change_list_pb__field_indices_by_name,
  1,  common__change_list_pb__number_ranges,
  (ProtobufCMessageInit) common__change_list_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__snapshot_header_pb__field_descriptors[2] =
{
  {
    "timestamp",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__SnapshotHeaderPb, timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "snapshot",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__SnapshotHeaderPb, snapshot),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__snapshot_header_pb__field_indices_by_name[] = {
  1,   /* field[1] = snapshot */
  0,   /* field[0] = timestamp */
};
static const ProtobufCIntRange common__snapshot_header_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor common__snapshot_header_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.SnapshotHeaderPb",
  "SnapshotHeaderPb",
  "Common__SnapshotHeaderPb",
  "common",
  sizeof(Common__SnapshotHeaderPb),
  2,
  common__snapshot_header_pb__field_descriptors,
  common__snapshot_header_pb__field_indices_by_name,
  1,  common__snapshot_header_pb__number_ranges,
  (ProtobufCMessageInit) common__snapshot_header_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__table_header_pb__field_descriptors[2] =
{
  {
    "name",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__TableHeaderPb, name),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "columns",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__TableHeaderPb, n_columns),
    offsetof(Common__TableHeaderPb, columns),
    &common__column_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__table_header_pb__field_indices_by_name[] = {
  1,   /* field[1] = columns */
  0,   /* field[0] = name */
};
static const ProtobufCIntRange common__table_header_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor common__table_header_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.TableHeaderPb",
  "TableHeaderPb",
  "Common__TableHeaderPb",
  "common",
  sizeof(Common__TableHeaderPb),
  2,
  common__table_header_pb__field_descriptors,
  common__table_header_pb__field_indices_by_name,
  1,  common__table_header_pb__number_ranges,
  (ProtobufCMessageInit) common__table_header_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__row_pb__field_descriptors[1] =
{
  {
    "values",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__RowPb, n_values),
    offsetof(Common__RowPb, values),
    &common__value_pb__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__row_pb__field_indices_by_name[] = {
  0,   /* field[0] = values */
};
static const ProtobufCIntRange common__row_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor common__row_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.RowPb",
  "RowPb",
  "Common__RowPb",
  "common",
  sizeof(Common__RowPb),
  1,
  common__row_pb__field_descriptors,
  common__row_pb__field_indices_by_name,
  1,  common__row_pb__number_ranges,
  (ProtobufCMessageInit) common__row_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__stream_message_pb__field_descriptors[2] =
{
  {
    "table",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__StreamMessagePb, message_case),
    offsetof(Common__StreamMessagePb, table),
    &common__table_header_pb__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "row",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__StreamMessagePb, message_case),
    offsetof(Common__StreamMessagePb, row),
    &common__row_pb__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__stream_message_pb__field_indices_by_name[] = {
  1,   /* field[1] = row */
  0,   /* field[0] = table */
};
static const ProtobufCIntRange common__stream_message_pb__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor common__stream_message_pb__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.StreamMessagePb",
  "StreamMessagePb",
  "Common__StreamMessagePb",
  "common",
  sizeof(Common__StreamMessagePb),
  2,
  common__stream_message_pb__field_descriptors,
  common__stream_message_pb__field_indices_by_name,
  1,  common__stream_message_pb__number_ranges,
  (ProtobufCMessageInit) common__stream_message_pb__init,
  NULL,NULL,NULL    /* reserved[123] */
};
