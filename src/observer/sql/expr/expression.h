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

#pragma once

#include <string.h>
#include <memory>
#include <string>

#include "storage/field/field.h"
#include "sql/parser/value.h"
#include "common/log/log.h"
#include "sql/parser/parse_defs.h"
#include "storage/db/db.h"

class Tuple;
class SelectStmt;
class SelectAggStmt;
class ProjectPhysicalOperator;
class ProjectAggPhysicalOperator;

/**
 * @defgroup Expression
 * @brief 表达式
 */

/**
 * @brief 表达式类型
 * @ingroup Expression
 */
enum class ExprType 
{
  NONE,
  STAR,         ///< 星号，表示所有字段
  FIELD,        ///< 字段。在实际执行时，根据行数据内容提取对应字段的值
  VALUE,        ///< 常量值
  CAST,         ///< 需要做类型转换的表达式
  COMPARISON,   ///< 需要做比较的表达式
  CONJUNCTION,  ///< 多个表达式使用同一种关系(AND或OR)来联结
  ARITHMETIC,   ///< 算术运算
  SUBQUERY,     ///< 子查询
};

/**
 * @brief 表达式的抽象描述
 * @ingroup Expression
 * @details 在SQL的元素中，任何需要得出值的元素都可以使用表达式来描述
 * 比如获取某个字段的值、比较运算、类型转换
 * 当然还有一些当前没有实现的表达式，比如算术运算。
 *
 * 通常表达式的值，是在真实的算子运算过程中，拿到具体的tuple后
 * 才能计算出来真实的值。但是有些表达式可能就表示某一个固定的
 * 值，比如ValueExpr。
 */
class Expression 
{
public:
  Expression() = default;
  virtual ~Expression() = default;

  /**
   * @brief 根据具体的tuple，来计算当前表达式的值。tuple有可能是一个具体某个表的行数据
   */
  virtual RC get_value(const Tuple &tuple, Value &value) const = 0;

  /**
   * @brief 在没有实际运行的情况下，也就是无法获取tuple的情况下，尝试获取表达式的值
   * @details 有些表达式的值是固定的，比如ValueExpr，这种情况下可以直接获取值
   */
  virtual RC try_get_value(Value &value) const
  {
    return RC::UNIMPLENMENT;
  }

  /**
   * @brief 表达式的类型
   * 可以根据表达式类型来转换为具体的子类
   */
  virtual ExprType type() const = 0;

  /**
   * @brief 表达式值的类型
   * @details 一个表达式运算出结果后，只有一个值
   */
  virtual AttrType value_type() const = 0;

  /**
   * @brief 表达式的名字，比如是字段名称，或者用户在执行SQL语句时输入的内容
   */
  virtual std::string name() const { return name_; }
  virtual void set_name(std::string name) { name_ = name; }

private:
  std::string  name_;
};

/**
 * @brief 字段表达式
 * @ingroup Expression
 */
class FieldExpr : public Expression 
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field)
  {}
  FieldExpr(const Field &field) : field_(field)
  {}

  virtual ~FieldExpr() = default;

  ExprType type() const override { return ExprType::FIELD; }
  AttrType value_type() const override { return field_.attr_type(); }

  Field &field() { return field_; }

  const Field &field() const { return field_; }

  const char *table_name() const { return field_.table_name(); }

  const char *field_name() const { return field_.field_name(); }

  RC get_value(const Tuple &tuple, Value &value) const override;

private:
  Field field_;
};

/**
 * @brief 常量值表达式
 * @ingroup Expression
 */
class ValueExpr : public Expression 
{
public:
  ValueExpr() = default;
  explicit ValueExpr(const Value &value) : value_(value)
  {}

  virtual ~ValueExpr() = default;

  RC get_value(const Tuple &tuple, Value &value) const override;
  RC try_get_value(Value &value) const override { value = value_; return RC::SUCCESS; }

  ExprType type() const override { return ExprType::VALUE; }

  AttrType value_type() const override { return value_.attr_type(); }

  void get_value(Value &value) const { value = value_; }

  const Value &get_value() const { return value_; }

// private:
public:
  Value value_;
};

/**
 * @brief 类型转换表达式
 * @ingroup Expression
 */
class CastExpr : public Expression 
{
public:
  CastExpr(std::unique_ptr<Expression> child, AttrType cast_type);
  virtual ~CastExpr();

  ExprType type() const override
  {
    return ExprType::CAST;
  }
  RC get_value(const Tuple &tuple, Value &value) const override;

  RC try_get_value(Value &value) const override;

  AttrType value_type() const override { return cast_type_; }

  std::unique_ptr<Expression> &child() { return child_; }

private:
  RC cast(const Value &value, Value &cast_value) const;

private:
  std::unique_ptr<Expression> child_;  ///< 从这个表达式转换
  AttrType cast_type_;  ///< 想要转换成这个类型
};

/**
 * @brief 比较表达式
 * @ingroup Expression
 */
class ComparisonExpr : public Expression 
{
public:
  ComparisonExpr(CompOp comp, bool exist_not, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ComparisonExpr();

  ExprType type() const override { return ExprType::COMPARISON; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  AttrType value_type() const override { return BOOLEANS; }

  CompOp comp() const { return comp_; }

  bool exist_not() const { return exist_not_; }

  std::unique_ptr<Expression> &left()  { return left_;  }
  std::unique_ptr<Expression> &right() { return right_; }

  /**
   * 尝试在没有tuple的情况下获取当前表达式的值
   * 在优化的时候，可能会使用到
   */
  RC try_get_value(Value &value) const override;

  /**
   * compare the two tuple cells
   * @param value the result of comparison
   */
  RC compare_value(const Value &left, const Value &right, bool &value) const;

private:
  CompOp comp_;
  bool exist_not_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
};

/**
 * @brief 联结表达式
 * @ingroup Expression
 * 多个表达式使用同一种关系(AND或OR)来联结
 * 当前miniob仅有AND操作
 */
class ConjunctionExpr : public Expression 
{
public:
  enum class Type {
    AND,
    OR,
  };

public:
  ConjunctionExpr(Type type, std::vector<std::unique_ptr<Expression>> &children);
  virtual ~ConjunctionExpr() = default;

  ExprType type() const override { return ExprType::CONJUNCTION; }

  AttrType value_type() const override { return BOOLEANS; }

  RC get_value(const Tuple &tuple, Value &value) const override;

  Type conjunction_type() const { return conjunction_type_; }

  std::vector<std::unique_ptr<Expression>> &children() { return children_; }

private:
  Type conjunction_type_;
  std::vector<std::unique_ptr<Expression>> children_;
};

/**
 * @brief 算术表达式
 * @ingroup Expression
 */
class ArithmeticExpr : public Expression 
{
public:
  enum class Type {
    ADD,
    SUB,
    MUL,
    DIV,
    NEGATIVE,
  };

public:
  ArithmeticExpr(Type type, Expression *left, Expression *right);
  ArithmeticExpr(Type type, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
  virtual ~ArithmeticExpr() = default;

  ExprType type() const override { return ExprType::ARITHMETIC; }

  AttrType value_type() const override;

  RC get_value(const Tuple &tuple, Value &value) const override;
  RC try_get_value(Value &value) const override;

  Type arithmetic_type() const { return arithmetic_type_; }

  std::unique_ptr<Expression> &left() { return left_; }
  std::unique_ptr<Expression> &right() { return right_; }

private:
  RC calc_value(const Value &left_value, const Value &right_value, Value &value) const;
  
private:
  Type arithmetic_type_;
  std::unique_ptr<Expression> left_;
  std::unique_ptr<Expression> right_;
};


/**
 * @brief 子查询表达式
 * @ingroup Expression
 */
class SubQueryExpression : public Expression {
public:
  SubQueryExpression() = default;
  // SubQueryExpression(SelectSqlNode &sql_node)
  // {
  //   std::vector<RelAttrSqlNode> new_attributes;  
  //   std::vector<std::string> new_relations; 
  //   std::vector<ConditionSqlNode> new_conditions;
  //   for(int i=0; i<sql_node.attributes.size(); i++){
  //     RelAttrSqlNode *tmp_rel = new RelAttrSqlNode();
  //     std::string *tmp_relation_name = new std::string(sql_node.attributes[i].relation_name.c_str());
  //     std::string *tmp_attribute_name = new std::string(sql_node.attributes[i].attribute_name.c_str());
  //     tmp_rel->relation_name = *tmp_relation_name;
  //     tmp_rel->attribute_name = *tmp_attribute_name;
  //     new_attributes.push_back(*tmp_rel);
  //   }
  //   for(int i=0; i<sql_node.relations.size(); i++){
  //     std::string *tmp = new std::string(sql_node.relations[i].c_str());
  //     new_relations.push_back(*tmp);
  //   }
  //   for(int i=0; i<sql_node.conditions.size(); i++){
  //     ConditionSqlNode *tmp_condition = new ConditionSqlNode();
  //     tmp_condition->left_is_attr = sql_node.conditions[i].left_is_attr;
  //     tmp_condition->exist_not = sql_node.conditions[i].exist_not;
  //     tmp_condition->right_is_attr = sql_node.conditions[i].right_is_attr;
  //     tmp_condition->comp = sql_node.conditions[i].comp;
  //     // Value           left_value; 
  //     Value *tmp_left_value = new Value(sql_node.conditions[i].left_value);
  //     tmp_condition->left_value = *tmp_left_value;
  //     // Value           right_value;
  //     Value *tmp_right_value= new Value(sql_node.conditions[i].right_value);
  //     tmp_condition->right_value = *tmp_right_value;
  //     // RelAttrSqlNode  left_attr;
  //     RelAttrSqlNode *tmp_left_attr = new RelAttrSqlNode();
  //     std::string *tmp_relation_name = new std::string(sql_node.conditions[i].left_attr.relation_name.c_str());
  //     std::string *tmp_attribute_name = new std::string(sql_node.conditions[i].left_attr.attribute_name.c_str());
  //     tmp_left_attr->relation_name = *tmp_relation_name;
  //     tmp_left_attr->attribute_name = *tmp_attribute_name;
  //     tmp_condition->left_attr = *tmp_left_attr;
  //     // RelAttrSqlNode  right_attr;
  //     RelAttrSqlNode *tmp_right_attr = new RelAttrSqlNode();
  //     std::string *tmp_relation_name2 = new std::string(sql_node.conditions[i].right_attr.relation_name.c_str());
  //     std::string *tmp_attribute_name2 = new std::string(sql_node.conditions[i].right_attr.attribute_name.c_str());
  //     tmp_right_attr->relation_name = *tmp_relation_name2;
  //     tmp_right_attr->attribute_name = *tmp_attribute_name2;
  //     tmp_condition->right_attr = *tmp_right_attr;
  //     new_conditions.push_back(*tmp_condition);
  //   }
  //   select_sql.attributes = new_attributes;
  //   select_sql.relations = new_relations;
  //   select_sql.conditions = new_conditions;
  // }
  SubQueryExpression(SelectSqlNode *sql_node) : select_sql(sql_node)
  {}
  SubQueryExpression(SelectAggSqlNode *sql_node) : select_agg_sql(sql_node)
  {}
  virtual ~SubQueryExpression() = default;

  ExprType type() const override
  {
    return ExprType::SUBQUERY;
  }

  RC get_value(const Tuple &tuple, Value &value) const override { return RC::SUCCESS; }

  AttrType value_type() const override { return AttrType::UNDEFINED; }

  RC get_value(Value &value) const;

  // For no agg-func
  // void set_select_node(SelectSqlNode *sql_node)
  // {
  //   select_sql = sql_node;
  // }
  SelectSqlNode *get_select_node() const
  {
    return select_sql;
  }
  void set_sub_query_stmt(SelectStmt *sub_stmt)
  {
    sub_stmt_ = sub_stmt;
  }
  SelectStmt *get_sub_query_stmt() const
  {
    return sub_stmt_;
  }
  void set_sub_query_top_oper(ProjectPhysicalOperator *oper)
  {
    sub_top_oper_ = oper;
  }
  ProjectPhysicalOperator *get_sub_query_top_oper() const
  {
    return sub_top_oper_;
  }

  // For agg-func
  // void set_select_agg_node(SelectAggSqlNode *sql_node)
  // {
  //   select_agg_sql = sql_node;
  // }
  SelectAggSqlNode *get_select_agg_node() const
  {
    return select_agg_sql;
  }
  void set_sub_query_agg_stmt(SelectAggStmt *sub_agg_stmt)
  {
    sub_agg_stmt_ = sub_agg_stmt;
  }
  SelectAggStmt *get_sub_query_agg_stmt() const
  {
    return sub_agg_stmt_;
  }
  void set_sub_query_agg_top_oper(ProjectAggPhysicalOperator *oper)
  {
    sub_agg_top_oper_ = oper;
  }
  ProjectAggPhysicalOperator *get_sub_query_agg_top_oper() const
  {
    return sub_agg_top_oper_;
  }

  RC open_sub_query(Trx *trx) const;
  RC close_sub_query() const;

  RC create_expression(Expression *&expr, Expression *&res_expr, CompOp comp = NO_OP, Db *db = nullptr);

private:
  SelectSqlNode *select_sql;
  SelectStmt *sub_stmt_ = nullptr;
  ProjectPhysicalOperator *sub_top_oper_ = nullptr;

  SelectAggSqlNode *select_agg_sql = nullptr;
  SelectAggStmt *sub_agg_stmt_ = nullptr;
  ProjectAggPhysicalOperator *sub_agg_top_oper_ = nullptr;
};