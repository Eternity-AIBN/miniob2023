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
// Created by Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "sql/executor/execute_stage.h"

#include "common/log/log.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/select_agg_stmt.h"
#include "storage/default/default_handler.h"
#include "sql/executor/command_executor.h"
#include "sql/operator/calc_physical_operator.h"

using namespace std;
using namespace common;

RC ExecuteStage::handle_request(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  const unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  if (physical_operator != nullptr) {
    return handle_request_with_physical_operator(sql_event);
  }

  SessionEvent *session_event = sql_event->session_event();

  Stmt *stmt = sql_event->stmt();
  if (stmt != nullptr) {
    CommandExecutor command_executor;
    rc = command_executor.execute(sql_event);
    session_event->sql_result()->set_return_code(rc);
  } else {
    return RC::INTERNAL;
  }
  return rc;
}

RC ExecuteStage::handle_request_with_physical_operator(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;

  Stmt *stmt = sql_event->stmt();
  ASSERT(stmt != nullptr, "SQL Statement shouldn't be empty!");

  unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  ASSERT(physical_operator != nullptr, "physical operator should not be null");

  // TODO 这里也可以优化一下，是否可以让physical operator自己设置tuple schema
  TupleSchema schema;
  switch (stmt->type()) {
    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
      bool with_table_name = select_stmt->tables().size() > 1;

      for (const Field &field : select_stmt->query_fields()) {
        if (with_table_name) {
          schema.append_cell(field.table_name(), field.field_name());
        } else {
          schema.append_cell(field.field_name());
        }
      }
    } break;

    case StmtType::SELECT_AGG: {
      SelectAggStmt *select_agg_stmt = static_cast<SelectAggStmt *>(stmt);
      bool with_table_name = select_agg_stmt->tables().size() > 1;

      
      // const FieldMeta *field_meta = table_meta.field(table_meta.sys_field_num());
      // std::string agg_name =  "count(*)"; 
      // const char* agg_name_char = agg_name.c_str();
      // field_meta_show = FieldMeta(agg_name_char, field_meta->type(), field_meta->offset(), field_meta->len(), field_meta->visible());
      // field_metas_show.push_back(Field(table, &field_meta_show));

      for (int i = 0; i < static_cast<int>(select_agg_stmt->aggop().size()); i++) {
        std::string aggop_name;
        switch (select_agg_stmt->aggop()[i])
        {
        case MAX_OP:
          aggop_name = "max";
          break;
        case MIN_OP:
          aggop_name = "min";
          break;
        case COUNT_OP:
          aggop_name = "count";
          break;
        case AVG_OP:
          aggop_name = "avg";
          break;
        case SUM_OP:
          aggop_name = "sum";
          break;
        default:
          break;
        }
        std::string agg_name;
        if(select_agg_stmt->select_count_star()[i] == true){
          agg_name = "count(*)";
        }else{
          agg_name = aggop_name + "(" + select_agg_stmt->query_fields()[i].field_name() + ")"; 
        }
        const char* agg_name_char = agg_name.c_str();
        if (with_table_name) {
          schema.append_cell(select_agg_stmt->query_fields()[i].table_name(), select_agg_stmt->query_fields()[i].field_name());
        } else {
          schema.append_cell(agg_name_char);
        }
      }
    } break;

    case StmtType::CALC: {
      CalcPhysicalOperator *calc_operator = static_cast<CalcPhysicalOperator *>(physical_operator.get());
      for (const unique_ptr<Expression> & expr : calc_operator->expressions()) {
        schema.append_cell(expr->name().c_str());
      }
    } break;

    case StmtType::EXPLAIN: {
      schema.append_cell("Query Plan");
    } break;
    default: {
      // 只有select返回结果
    } break;
  }

  SqlResult *sql_result = sql_event->session_event()->sql_result();
  sql_result->set_tuple_schema(schema);
  sql_result->set_operator(std::move(physical_operator));
  return rc;
}
