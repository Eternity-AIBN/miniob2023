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

UpdateStmt::UpdateStmt(Table *table, std::vector<std::string> attribute_name, std::vector<Value> values, int value_amount, FilterStmt *filter_stmt)
    : table_(table), value_amount_(value_amount), filter_stmt_(filter_stmt)
{
  // attribute_name_(attribute_name), values_(values), 向量不能直接=
  for(int i=0; i<attribute_name.size(); i++){
    std::string *tmp_string = new std::string(attribute_name[i].c_str());
    attribute_name_.push_back(*tmp_string);

    Value *tmp_value = new Value(values[i].attr_type(), values[i].get_data(), values[i].length());
    values_.push_back(*tmp_value);
  }
}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || update.attribute_name.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, attribute_name_nums=%d",
        db, table_name, update.attribute_name.size());
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<Value> new_values;
  for (int k=0; k<update.attribute_name.size(); k++){
    Value *values = new Value(update.value[k].attr_type(), const_cast<char *>(update.value[k].data()), update.value[k].length());
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num() - table_meta.sys_field_num();
    
    // check fields type
    bool flag = false;    // 要更新的字段是否存在 
    const int sys_field_num = table_meta.sys_field_num();
    for (int i = 0; i < field_num; i++) {  // 遍历表的所有属性，找到要更新的字段
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const std::string field_name = field_meta->name();
      if (field_name == update.attribute_name[k]) {  
        if (field_meta->type() == DATES){   // 日期列的更新，传入的update.value通常是"1999-02-01"，会被当成CHARS类型，需要转换为DATES类型
          int32_t date = -1;
          RC rc = string_to_date(values->get_string(), date);
          if (rc != RC::SUCCESS){
            LOG_WARN("field_type is date error");
            return rc;
          }
          values->set_date(date);
        }
        flag = true;
        new_values.push_back(*values);
        break;
      }
    }
    if (!flag){
      // 要更新的字段不存在
      LOG_WARN("field type mismatch. table=%s", table_name);
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }
  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr; 

  RC rc = FilterStmt::create(
      db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  stmt = new UpdateStmt(table, update.attribute_name, new_values, update.attribute_name.size(), filter_stmt);
  return RC::SUCCESS;
}
