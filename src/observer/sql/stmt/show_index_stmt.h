#pragma once

#include <string>

#include "sql/stmt/stmt.h"

struct ShowIndexSqlNode;
class Table;
class FieldMeta;

/**
 * @brief 创建索引的语句
 * @ingroup Statement
 */
class ShowIndexStmt : public Stmt
{
public:
  ShowIndexStmt(Table *table): table_(table)
  {}

  virtual ~ShowIndexStmt() = default;

  StmtType type() const override { return StmtType::SHOW_INDEX; }

  Table *table() const { return table_; }

public:
  static RC create(Db *db, const ShowIndexSqlNode &show_index, Stmt *&stmt);

private:
  Table *table_ = nullptr;
};
