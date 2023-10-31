#include "common/log/log.h"
#include "sql/operator/update_physical_operator.h"
#include "storage/record/record.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "sql/stmt/update_stmt.h"
#include "util/typecast.h"
#include "sql/optimizer/logical_plan_generator.h"
#include "sql/optimizer/physical_plan_generator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/project_agg_logical_operator.h"
#include "sql/operator/project_physical_operator.h"
#include "sql/operator/project_agg_physical_operator.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/select_agg_stmt.h"


RC UpdatePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }
  RC rc = RC::SUCCESS;

  // TODO  先 get_value 拿到 TupleCell，根据 TupleCell 构造 Value，以适配 table update_record 的接口
  auto get_value_for_sub_query = [](Trx *trx, const SubQueryExpression *expr, Value &cell) {
    expr->open_sub_query(trx);
    RC rc = expr->get_value(cell);
    if (RC::RECORD_EOF == rc) {      // TODO support NULL
      // e.g. a = select a  -> a = null
      cell.set_type(AttrType::NULLS);
    } else if (RC::SUCCESS == rc) {
      Value tmp_cell;
      if (RC::SUCCESS == (rc = expr->get_value(tmp_cell))) {
        // e.g. a = select a  -> a = (1, 2, 3)
        // std::cout << "Should not have rows more than 1" << std::endl;
        expr->close_sub_query();
        return RC::INTERNAL;
      }
    } else {
      expr->close_sub_query();
      return rc;
    }
    expr->close_sub_query();
    return RC::SUCCESS;
  };


  for (size_t i = 0; i < exprs_.size(); ++i) {
    Value *update_value = nullptr;
    if (ExprType::SUBQUERY == exprs_[i]->type()) { 
      auto sub_query_expr = (SubQueryExpression *)exprs_[i];
      // 同样要判断是select还是select-agg
      Stmt *sub_select;
      if (nullptr == sub_query_expr->get_sub_query_agg_stmt()){   // select
        sub_select = dynamic_cast<Stmt *>(sub_query_expr->get_sub_query_stmt());
      }else{
        sub_select = dynamic_cast<Stmt *>(sub_query_expr->get_sub_query_agg_stmt());
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

      if (nullptr == sub_query_expr->get_sub_query_agg_stmt()){   // select
        sub_query_expr->set_sub_query_top_oper(static_cast<ProjectPhysicalOperator *>(physical_oper.get()));
      }else{
        sub_query_expr->set_sub_query_agg_top_oper(static_cast<ProjectAggPhysicalOperator *>(physical_oper.get()));
      }

      Value cell;
      if (RC::SUCCESS != (rc = get_value_for_sub_query(trx, sub_query_expr, cell))) {
        LOG_WARN("Update get cell for sub_query failed. RC = %d:%s", rc, strrc(rc));
        // return rc;
        multi_records = true;
      }
      update_value = new Value(cell);
    } else{
      assert(ExprType::VALUE == exprs_[i]->type());
      update_value = new Value(((ValueExpr *)exprs_[i])->get_value());
    }
    
    const FieldMeta *field_meta = fields_[i];
    const AttrType field_type = field_meta->type();
    const AttrType value_type = update_value->attr_type();
    if (AttrType::NULLS == value_type) {  // 更新 null 值
      if (!field_meta->nullable()) {      // 该列 not null
        LOG_WARN("field type mismatch. can not be null. table=%s, field=%s, field type=%d, value_type=%d",
            table_->name(),
            field_meta->name(),
            field_type,
            value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      update_value->set_type(AttrType::NULLS);    // 只是将type设置成NULLS
    }
    else if (field_type != value_type){    // 类型转换
      if (field_type == DATES){
        int32_t date = -1;
        rc = string_to_date(update_value->get_string(), date);
        if (rc != RC::SUCCESS){
          LOG_WARN("field_type is date error");
          return rc;
        }
        update_value->set_date(date);
      }
      else if(!type_cast_not_support(value_type, field_type)){
        void *tmp_data = nullptr;
        tmp_data = cast_to[value_type][field_type](update_value->get_data());
        if (nullptr == tmp_data) {
          LOG_WARN("field type mismatch in update. field type=%d, value_type=%d", field_type, value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
        int copy_len = field_meta->len();
        if (field_type == CHARS) {
          const int data_len = strlen((const char *)tmp_data);
          if (copy_len > data_len) {
            copy_len = data_len + 1;
          }
        }
        update_value->set_type(field_type);
        update_value->set_data((char *)tmp_data, copy_len);
      }
      else{
        LOG_WARN("field type mismatch in update. field type=%d, value_type=%d", field_type, value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }

    values_.push_back(*update_value);
  }


  std::unique_ptr<PhysicalOperator> &child = children_[0];
  rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  PhysicalOperator *child = children_[0].get();
  while (RC::SUCCESS == (rc = child->next())) {
    if(multi_records){
      multi_records = false;
      return RC::INTERNAL;
    }
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);

    // 在这里更新record
    rc = row_tuple->update_cell(attribute_name_, values_);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      return rc;
    }

    Record &record = row_tuple->record();
    rc = trx_->update_record(table_, record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      return rc;
    }
  }

  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}
