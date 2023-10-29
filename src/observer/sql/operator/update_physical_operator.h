#pragma once

#include "sql/operator/physical_operator.h"

class Trx;
class UpdateStmt;

/**
 * @brief 物理算子，更新
 * @ingroup PhysicalOperator
 */
class UpdatePhysicalOperator : public PhysicalOperator
{
public:
  // UpdatePhysicalOperator(Table *table, std::vector<Value> values, std::vector<std::string> attribute_name) : table_(table)
  // {
  //   // values_(values), attribute_name_(attribute_name)
  //   for(int i=0; i<attribute_name.size(); i++){
  //     std::string *tmp_string = new std::string(attribute_name[i].c_str());
  //     attribute_name_.push_back(*tmp_string);

  //     Value *tmp_value = new Value(values[i].attr_type(), values[i].get_data(), values[i].length());
  //     values_.push_back(*tmp_value);
  //   }
  // }
  UpdatePhysicalOperator(Table *table, std::vector<Expression *> &exprs, std::vector<const FieldMeta *> &fields, std::vector<std::string> &attribute_name) : table_(table), exprs_(exprs), fields_(fields), attribute_name_(attribute_name)
  {}

  virtual ~UpdatePhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::UPDATE;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override
  {
    return nullptr;
  }

public:
  std::vector<const FieldMeta *> fields_;       // 把要更新的字段类型保存下来，后在operator中就不用再判断了

private:
  Table *table_ = nullptr;
  Trx *trx_ = nullptr;
  // Value values_;
  // std::string attribute_name_;
  std::vector<Value> values_;
  std::vector<Expression *> exprs_;
  std::vector<std::string> attribute_name_;
};
