/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
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

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

UpdateStmt::UpdateStmt(Table *table, std::string attribute_name, Value values, int value_amount, FilterStmt *filter_stmt)
    : table_(table), attribute_name_(attribute_name), values_(values), value_amount_(value_amount), filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  // TODO
  // stmt = nullptr;
  // return RC::INTERNAL;

  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || update.attribute_name.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, attribute_name=%s",
        db, table_name, update.attribute_name.c_str());
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // const char *values = update.value.data();
  const Value values = update.value;
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num() - table_meta.sys_field_num();
  
  // check fields type
  const int sys_field_num = table_meta.sys_field_num();
  // bool flag = 0;
  for (int i = 0; i < field_num; i++) {  // 遍历表的所有属性，找到要更新的字段
    const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
    const std::string field_name = field_meta->name();
    if (field_name == update.attribute_name) {  
      // flag = 1;
      std::unordered_map<std::string, Table *> table_map;
      table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

      FilterStmt *filter_stmt = nullptr; 
      // if (update.conditions.size() == 0){  // 不带条件的更新
      //   stmt = new UpdateStmt(table, update.attribute_name, values, 1, filter_stmt);  // 当前实现update单个字段即可
      //   return RC::SUCCESS;
      // } 

      RC rc = FilterStmt::create(
          db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
        return rc;
      }
      stmt = new UpdateStmt(table, update.attribute_name, values, 1, filter_stmt);  // 当前实现update单个字段即可
      return RC::SUCCESS;
    }
  }
  // 要更新的字段不存在
  LOG_WARN("field type mismatch. table=%s", table_name);
  return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  // if (flag == 0){   // 要更新的字段不存在
  //   LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
  //         table_name, field_meta->name(), field_type, value_type);
  //   return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  // }

  // everything alright
  // stmt = new UpdateStmt(table, values, value_num);
  // stmt = new UpdateStmt(table, values, 1, filter_stmt);  // 当前实现update单个字段即可
  // return RC::SUCCESS;
}
