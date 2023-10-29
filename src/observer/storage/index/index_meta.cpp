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
// Created by Wangyunlai.wyl on 2021/5/18.
//

#include "storage/index/index_meta.h"
#include "storage/field/field_meta.h"
#include "storage/table/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString UNIQUE_OR_NOT("unique");
const static Json::StaticString FIELD_FIELD_NAME("field_name");

// RC IndexMeta::init(const char *name, const FieldMeta &field)
// {
//   if (common::is_blank(name)) {
//     LOG_ERROR("Failed to init index, name is empty.");
//     return RC::INVALID_ARGUMENT;
//   }

//   name_ = name;
//   field_ = field.name();
//   return RC::SUCCESS;
// }

RC IndexMeta::init(const char *name, std::vector<FieldMeta *> field, bool unique)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  for (int i=0; i<field.size(); i++){
    std::string *tmp = new std::string(field[i]->name());
    field_.push_back(*tmp);
  }
  unique_ = unique;
  
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_NAME] = name_;
  json_value[FIELD_FIELD_NAME] = field_[0];  // TODO 暂时不考虑multi-index的情况
  json_value[UNIQUE_OR_NOT] = unique_;
}

// RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
RC IndexMeta::from_json(TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_value = json_value[FIELD_FIELD_NAME];
  const Json::Value &unique_value = json_value[UNIQUE_OR_NOT];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  if (!field_value.isString()) {
    LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
        name_value.asCString(),
        field_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  if (!unique_value.isBool()) { 
    LOG_ERROR("Unique is not a boolean. json value=%s", unique_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  // const FieldMeta *field = table.field(field_value.asCString());
  FieldMeta *field = table.field(field_value.asCString());
  if (nullptr == field) {
    LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field_value.asCString());
    return RC::SCHEMA_FIELD_MISSING;
  }

  std::vector<FieldMeta *> fields;
  fields.push_back(field);
  // return index.init(name_value.asCString(), *field);
  return index.init(name_value.asCString(), fields, unique_value.asBool());
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

// const char *IndexMeta::field() const
// {
//   return field_.c_str();
// }
std::vector<std::string> IndexMeta::field() const
{
  return field_;
}

void IndexMeta::desc(std::ostream &os) const
{
  // os << "index name=" << name_ << ", field=" << field_;
  os << "index name=" << name_ << ", field=(";
  int n = field_.size();
  for (int i=0; i<n-1; i++){
    os << field_[i] << ", ";
  }
  os << field_[n-1] << ")";
}