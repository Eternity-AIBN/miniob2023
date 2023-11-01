/* Copyright (c) 2021OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "util/typecast.h"

InsertStmt::InsertStmt(Table *table, std::vector<Value *> &values, int value_amount)
    : table_(table), value_amount_(value_amount)
{
  for (int i = 0; i < values.size(); i++){
    values_.push_back(values[i]);
  }
}

// RC InsertStmt::create(Db *db, const InsertSqlNode &inserts, Stmt *&stmt)
RC InsertStmt::create(Db *db, InsertSqlNode &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || inserts.values.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d",
        db, table_name, static_cast<int>(inserts.values.size()));
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // support insert multi rows
  std::vector<Value *> row_values;
  const int value_num = static_cast<int>(inserts.values[0].size());
  for (int k=0; k<inserts.values.size(); k++){
    // check the fields number
    Value *values = inserts.values[k].data();
    // const int value_num = static_cast<int>(inserts.values.size());
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num() - table_meta.sys_field_num() - 1;
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }
    
    // check fields type
    const int sys_field_num = table_meta.sys_field_num();
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type = values[i].attr_type();
      // check null first
      if (AttrType::NULLS == value_type) {  // 插入 null 值
        if (!field_meta->nullable()) {      // 该列 not null
          LOG_WARN("field type mismatch. can not be null. table=%s, field=%s, field type=%d, value_type=%d",
              table_name,
              field_meta->name(),
              field_type,
              value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
        values[i].set_type(AttrType::NULLS);    // 只是将type设置成NULLS
        continue;
      }
      if (field_type != value_type) {  // try to convert the value type to field type
        if (field_type == DATES){
          int32_t date = -1;
          RC rc = string_to_date(values[i].get_string(), date);
          if (rc != RC::SUCCESS){
            LOG_WARN("field_type is date error");
            return rc;
          }
          values[i].set_date(date);
        }
        else if(!type_cast_not_support(value_type, field_type)){
          void *tmp_data = nullptr;
          tmp_data = cast_to[value_type][field_type](values[i].get_data());
          if (nullptr == tmp_data) {
            LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
              table_name, field_meta->name(), field_type, value_type);
            return RC::SCHEMA_FIELD_TYPE_MISMATCH;
          }
          
          int copy_len = field_meta->len();
          if (field_type == CHARS) {
            const int data_len = strlen((const char *)tmp_data);
            if (copy_len > data_len) {
              copy_len = data_len + 1;
            }
          }
          values[i].set_type(field_type);
          values[i].set_data((char *)tmp_data, copy_len);
        }
        else{
          LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
            table_name, field_meta->name(), field_type, value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
      }
    }

    // const Value *const_values = new Value(*values);
    Value test = values[1];
    row_values.push_back(values);
  }
  
  // everything alright
  // stmt = new InsertStmt(table, values, value_num);
  stmt = new InsertStmt(table, row_values, value_num);
  return RC::SUCCESS;
}
