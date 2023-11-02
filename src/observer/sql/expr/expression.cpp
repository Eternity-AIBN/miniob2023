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
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/operator/project_physical_operator.h"
#include "sql/operator/project_agg_physical_operator.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/select_agg_stmt.h"
#include "expression.h"
#include "util/typecast.h"
#include "sql/optimizer/logical_plan_generator.h"
#include "sql/optimizer/physical_plan_generator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/project_agg_logical_operator.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/select_agg_stmt.h"

using namespace std;

RC FieldExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  return tuple.find_cell(TupleCellSpec(table_name(), field_name()), value);
}

RC ValueExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  value = value_;
  return RC::SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
CastExpr::CastExpr(unique_ptr<Expression> child, AttrType cast_type)
    : child_(std::move(child)), cast_type_(cast_type)
{}

CastExpr::~CastExpr()
{}

RC CastExpr::cast(const Value &value, Value &cast_value) const
{
  RC rc = RC::SUCCESS;
  if (this->value_type() == value.attr_type()) {
    cast_value = value;
    return rc;
  }

  switch (cast_type_) {
    case BOOLEANS: {
      bool val = value.get_boolean();
      cast_value.set_boolean(val);
    } break;
    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported convert from type %d to %d", child_->value_type(), cast_type_);
    }
  }
  return rc;
}

RC CastExpr::get_value(const Tuple &tuple, Value &cell, Trx *trx) const
{
  RC rc = child_->get_value(tuple, cell);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(cell, cell);
}

RC CastExpr::try_get_value(Value &value) const
{
  RC rc = child_->try_get_value(value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, value);
}

////////////////////////////////////////////////////////////////////////////////

ComparisonExpr::ComparisonExpr(CompOp comp, bool exist_not, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : comp_(comp), exist_not_(exist_not), left_(std::move(left)), right_(std::move(right))
{}

ComparisonExpr::~ComparisonExpr()
{}

RC ComparisonExpr::compare_value(const Value &left, const Value &right, bool &result) const
{
  RC rc = RC::SUCCESS;
  // Add NULL compare
  if (left.attr_type() == NULLS || right.attr_type() == NULLS){
    result = false;
    return rc;
  }

  if(comp_ == LIKE_TO){
      int cmp_result = left.like(right);
      result = (1 == cmp_result);
      if(exist_not_ == 1){
        result = !result;
      }
      return rc;
  } 
  int cmp_result = left.compare(right);
  result = false;
  switch (comp_) {
    case EQUAL_TO: {
      result = (0 == cmp_result);
    } break;
    // case LIKE_TO: {
    //   result = ;    // TODO
    // } break;
    case LESS_EQUAL: {
      result = (cmp_result <= 0);
    } break;
    case NOT_EQUAL: {
      result = (cmp_result != 0);
    } break;
    case LESS_THAN: {
      result = (cmp_result < 0);
    } break;
    case GREAT_EQUAL: {
      result = (cmp_result >= 0);
    } break;
    case GREAT_THAN: {
      result = (cmp_result > 0);
    } break;
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }

  if(exist_not_ == 1){
    result = !result;
  }

  return rc;
}

RC ComparisonExpr::try_get_value(Value &cell) const
{
  if (left_->type() == ExprType::VALUE && right_->type() == ExprType::VALUE) {
    ValueExpr *left_value_expr = static_cast<ValueExpr *>(left_.get());
    ValueExpr *right_value_expr = static_cast<ValueExpr *>(right_.get());

    
    if(right_value_expr->is_null_){    // xxx is null 的情况
      const Value &left_cell = left_value_expr->get_value();
      if (left_cell.attr_type() == NULLS){   // null is null 才成立
        cell.set_boolean(exist_not_ ? false : true);
      } else{
        cell.set_boolean(exist_not_ ? true : false);
      }
      return RC::SUCCESS;
    }
    

    const Value &left_cell = left_value_expr->get_value();
    const Value &right_cell = right_value_expr->get_value();

    bool value = false;
    RC rc = compare_value(left_cell, right_cell, value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to compare tuple cells. rc=%s", strrc(rc));
    } else {
      cell.set_boolean(value);
    }
    return rc;
  }

  return RC::INVALID_ARGUMENT;
}

RC ComparisonExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  Value left_value;
  Value right_value;

  if (ValueExpr* derived = dynamic_cast<ValueExpr*>(right_.get())){
    if(derived->is_null_){    // xxx is null 的情况
      RC rc = left_->get_value(tuple, left_value);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
        return rc;
      }
      if (left_value.attr_type() == NULLS){   // null is null 才成立
        value.set_boolean(exist_not_ ? false : true);
      } else{
        value.set_boolean(exist_not_ ? true : false);
      }
      return rc;
    }
  }

  RC rc = left_->get_value(tuple, left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  auto has_null = [](const std::vector<Value> &cells) {   // 判断cells中是否有NULL值
    for (auto &cell : cells) {
      if (cell.attr_type() == NULLS) {
        return true;
      }
    }
    return false;
  };

  if (comp_ == CompOp::IN_OP){    // where col in() 此时右边为ValueExpr/SubQueryExpr, 可能不止有一个值
    std::vector<Value> right_values;
    if(SubQueryExpression* derived = dynamic_cast<SubQueryExpression*>(right_.get())){     //SubQueryExpr
      Stmt *sub_select;
      if (nullptr == derived->get_sub_query_agg_stmt()){   // select
        sub_select = dynamic_cast<Stmt *>(derived->get_sub_query_stmt());
      }else{
        sub_select = dynamic_cast<Stmt *>(derived->get_sub_query_agg_stmt());
      }
      // 根据 stmt 生成 LogicalOperator
      std::unique_ptr<LogicalOperator> logical_oper;
      LogicalPlanGenerator *logical_plan_generator = new LogicalPlanGenerator(); 
      rc = logical_plan_generator->create(sub_select, logical_oper);
      if(RC::SUCCESS != rc) { return rc; }
      // 根据 LogicalOperator 生成 PhysicalOperator
      std::unique_ptr<PhysicalOperator> physical_oper;
      PhysicalPlanGenerator *physical_plan_generator = new PhysicalPlanGenerator(); 
      rc = physical_plan_generator->create(*logical_oper, physical_oper);
      if(RC::SUCCESS != rc) { return rc; }

      if (nullptr == derived->get_sub_query_agg_stmt()){   // select
        derived->set_sub_query_top_oper(static_cast<ProjectPhysicalOperator *>(physical_oper.get()));
      }else{
        derived->set_sub_query_agg_top_oper(static_cast<ProjectAggPhysicalOperator *>(physical_oper.get()));
      }

      derived->get_values(right_values, trx);
    } else {  //ListExpr
      ListExpr* derived2 = dynamic_cast<ListExpr*>(right_.get());
      // right_values = derived2->value_;
      for (int i=0; i<derived2->value_.size(); i++){
        Value *tmp = new Value(derived2->value_[i]);
        right_values.push_back(*tmp);
      }
    }
    if (left_value.attr_type() == NULLS) {
      value.set_boolean(false);  // null don't in/not in any list
      return RC::SUCCESS;
    }
    // TODO 类型转换
    for(int i=0; i<right_values.size(); i++){
      if(right_values[i].attr_type() == NULLS){   // NULL不用转换
        continue;
      }
      if (left_value.attr_type() != right_values[i].attr_type()){
        if (left_value.attr_type() == DATES){
          int32_t date = -1;
          rc = string_to_date(right_values[i].get_string(), date);
          if (rc != RC::SUCCESS){
            LOG_WARN("field_type is date error");
            return rc;
          }
          right_values[i].set_date(date);
        }
        else if(!type_cast_not_support(right_values[i].attr_type(), left_value.attr_type())){
          void *tmp_data = nullptr;
          tmp_data = cast_to[right_values[i].attr_type()][left_value.attr_type()](right_values[i].get_data());
          if (nullptr == tmp_data) {
            LOG_WARN("field type mismatch in update. field type=%d, value_type=%d", left_value.attr_type(), right_values[i].attr_type());
            return RC::SCHEMA_FIELD_TYPE_MISMATCH;
          }
          int copy_len = left_value.length();
          if (left_value.attr_type() == CHARS) {
            const int data_len = strlen((const char *)tmp_data);
            if (copy_len > data_len) {
              copy_len = data_len + 1;
            }
          }
          right_values[i].set_type(left_value.attr_type());
          right_values[i].set_data((char *)tmp_data, copy_len);
        }
      }
    }

    if (exist_not_ == false){    // in
      bool res = left_value.in_values(right_values);
      value.set_boolean(res);
    } else {            // not in
      if (has_null(right_values)){
        value.set_boolean(false);  // null don't in/not in any list
      } else{
        bool res = left_value.not_in_values(right_values);
        value.set_boolean(res);
      }
    }
    return RC::SUCCESS;
  }

  rc = right_->get_value(tuple, right_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }

  bool bool_value = false;
  rc = compare_value(left_value, right_value, bool_value);
  if (rc == RC::SUCCESS) {
    value.set_boolean(bool_value);
  }
  return rc;
}

////////////////////////////////////////////////////////////////////////////////
ConjunctionExpr::ConjunctionExpr(Type type, vector<unique_ptr<Expression>> &children)
    : conjunction_type_(type), children_(std::move(children))
{}

RC ConjunctionExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    value.set_boolean(true);
    return rc;
  }

  Value tmp_value;
  for (const unique_ptr<Expression> &expr : children_) {
    rc = expr->get_value(tuple, tmp_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value by child expression. rc=%s", strrc(rc));
      return rc;
    }
    bool bool_value = tmp_value.get_boolean();
    if ((conjunction_type_ == Type::AND && !bool_value) || (conjunction_type_ == Type::OR && bool_value)) {
      value.set_boolean(bool_value);
      return rc;
    }
  }

  bool default_value = (conjunction_type_ == Type::AND);
  value.set_boolean(default_value);
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, Expression *left, Expression *right)
    : arithmetic_type_(type), left_(left), right_(right)
{}
ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : arithmetic_type_(type), left_(std::move(left)), right_(std::move(right))
{}

AttrType ArithmeticExpr::value_type() const
{
  if (!right_) {
    return left_->value_type();
  }

  if (left_->value_type() == AttrType::INTS &&
      right_->value_type() == AttrType::INTS &&
      arithmetic_type_ != Type::DIV) {
    return AttrType::INTS;
  }
  
  return AttrType::FLOATS;
}

RC ArithmeticExpr::calc_value(const Value &left_value, const Value &right_value, Value &value) const
{
  RC rc = RC::SUCCESS;

  const AttrType target_type = value_type();

  switch (arithmetic_type_) {
    case Type::ADD: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() + right_value.get_int());
      } else {
        value.set_float(left_value.get_float() + right_value.get_float());
      }
    } break;

    case Type::SUB: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() - right_value.get_int());
      } else {
        value.set_float(left_value.get_float() - right_value.get_float());
      }
    } break;

    case Type::MUL: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() * right_value.get_int());
      } else {
        value.set_float(left_value.get_float() * right_value.get_float());
      }
    } break;

    case Type::DIV: {
      if (target_type == AttrType::INTS) {
        if (right_value.get_int() == 0) {
          // NOTE: 设置为整数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为整数最大值。
          value.set_int(numeric_limits<int>::max());
        } else {
          value.set_int(left_value.get_int() / right_value.get_int());
        }
      } else {
        if (right_value.get_float() > -EPSILON && right_value.get_float() < EPSILON) {
          // NOTE: 设置为浮点数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为浮点数最大值。
          value.set_float(numeric_limits<float>::max());
        } else {
          value.set_float(left_value.get_float() / right_value.get_float());
        }
      }
    } break;

    case Type::NEGATIVE: {
      if (target_type == AttrType::INTS) {
        value.set_int(-left_value.get_int());
      } else {
        value.set_float(-left_value.get_float());
      }
    } break;

    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported arithmetic type. %d", arithmetic_type_);
    } break;
  }
  return rc;
}

RC ArithmeticExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->get_value(tuple, left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_value(tuple, right_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_value(left_value, right_value, value);
}

RC ArithmeticExpr::try_get_value(Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->try_get_value(left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  if (right_) {
    rc = right_->try_get_value(right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
  }

  return calc_value(left_value, right_value, value);
}

////////////////////////////////////////////////////////////////////////////////
const void SubQueryExpression::get_values(std::vector<Value> &values, Trx *trx) const
{
  values.emplace_back(Value());
  open_sub_query(trx);
  while (RC::SUCCESS == get_value(values.back())) {
    values.emplace_back(Value());
  }
  close_sub_query();
  values.pop_back();  // pop null cell for record_eof
  return;
}

RC SubQueryExpression::get_value(Value &value, Trx *trx) const{
  RC rc = RC::SUCCESS;
  if(nullptr == sub_agg_top_oper_){
    RC rc = sub_top_oper_->next();
    if (RC::SUCCESS != rc) {
      return rc;
    }
    Tuple *child_tuple = sub_top_oper_->current_tuple();
    if (nullptr == child_tuple) {
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      return RC::INTERNAL;
    }
    rc = child_tuple->cell_at(0, value);  // only need the first cell
  }else{
    RC rc = sub_agg_top_oper_->next();
    if (RC::SUCCESS != rc) {
      return rc;
    }
    Tuple *child_tuple = sub_agg_top_oper_->current_tuple();
    if (nullptr == child_tuple) {
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      return RC::INTERNAL;
    }
    rc = child_tuple->cell_at(0, value);  // only need the first cell
  }
  
  return rc;
}

RC SubQueryExpression::open_sub_query(Trx *trx) const{
  if(nullptr == sub_agg_top_oper_){
    assert(nullptr != sub_top_oper_);
    return sub_top_oper_->open(trx);
  }else{
    assert(nullptr != sub_agg_top_oper_);
    return sub_agg_top_oper_->open(trx);
  }
  return RC::INTERNAL;
}

RC SubQueryExpression::close_sub_query() const{
  if(nullptr == sub_agg_top_oper_){
    assert(nullptr != sub_top_oper_);
    return sub_top_oper_->close();
  }else{
    assert(nullptr != sub_agg_top_oper_);
    return sub_agg_top_oper_->close();
  }
  return RC::INTERNAL;
}

// SubQueryExpression::create_expression(update.exprs[k], table_map, tables, expression, CompOp::EQUAL_TO, db)
// 只用到 update.exprs[k]，结果放在 expression 中
RC SubQueryExpression::create_expression(const Expression *expr, Expression *&res_expr, CompOp comp, Db *db)
{
  // 在这里判断是 select 还是 select-agg
  assert(ExprType::SUBQUERY == expr->type());
  Stmt *tmp_stmt = nullptr;
  RC rc;
  SubQueryExpression *sub_expr = new SubQueryExpression();
  if(nullptr == static_cast<const SubQueryExpression *>(expr)->get_select_agg_node()){
    // assert(select_sql != nullptr);
    rc = SelectStmt::create(db, *(static_cast<const SubQueryExpression *>(expr)->get_select_node()), tmp_stmt);
    if (RC::SUCCESS != rc) {
      LOG_ERROR("SubQueryExpression Create SelectStmt Failed. RC = %d:%s", rc, strrc(rc));
      return rc;
    }
    sub_expr->set_sub_query_stmt((SelectStmt *)tmp_stmt);
    res_expr = sub_expr;
  }else{
    rc = SelectAggStmt::create(db, *(static_cast<const SubQueryExpression *>(expr)->get_select_agg_node()), tmp_stmt);
    if (RC::SUCCESS != rc) {
      LOG_ERROR("SubQueryExpression Create SelectStmt Failed. RC = %d:%s", rc, strrc(rc));
      return rc;
    }
    sub_expr->set_sub_query_agg_stmt((SelectAggStmt *)tmp_stmt);
    res_expr = sub_expr;
  }
  return RC::SUCCESS;
  // switch (comp) {    // check projects num——不知道是什么，后面再看
  //   case EXISTS_OP:
  //   case NOT_EXISTS:
  //     break;
  //   default: {
  //     if (((SelectStmt *)tmp_stmt)->projects().size() != 1) {
  //       return RC::SQL_SYNTAX;
  //     }
  //     break;
  //   }
  // }
} 