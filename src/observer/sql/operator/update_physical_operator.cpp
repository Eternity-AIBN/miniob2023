#include "common/log/log.h"
#include "sql/operator/update_physical_operator.h"
#include "storage/record/record.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "sql/stmt/update_stmt.h"
#include "util/typecast.h"

RC UpdatePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  // TODO  先 get_value 拿到 TupleCell，根据 TupleCell 构造 Value，以适配 table update_record 的接口
  // auto get_cell_for_sub_query =  // TODO sub-query

  // std::vector<Value *> values;
  for (size_t i = 0; i < exprs_.size(); ++i) {
    // if (ExprType::SUBQUERYTYPE == expr->type()) {  // TODO sub-query
    assert(ExprType::VALUE == exprs_[i]->type());
    Value *update_value = new Value(((ValueExpr *)exprs_[i])->get_value());
    
    const FieldMeta *field_meta = fields_[i];
    const AttrType field_type = field_meta->type();
    const AttrType value_type = update_value->attr_type();
    if (field_type != value_type){    // 类型转换
      if (field_type == DATES){
        int32_t date = -1;
        RC rc = string_to_date(update_value->get_string(), date);
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
  RC rc = child->open(trx);
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
