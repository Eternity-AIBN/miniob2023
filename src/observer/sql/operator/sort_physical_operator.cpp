#include "common/log/log.h"
#include "sql/operator/sort_physical_operator.h"
#include "storage/record/record.h"
#include "sql/stmt/orderby_stmt.h"
#include "storage/field/field.h"


RC SortPhysicalOperator::open(Trx *trx)
{
  // if (children_.size() != 1) {
  //   LOG_WARN("predicate operator must has one child");
  //   return RC::INTERNAL;
  // }

  // return children_[0]->open(trx);
  RC rc = RC::SUCCESS;
  if (RC::SUCCESS != (rc = children_[0]->open(trx))) {
    rc = RC::INTERNAL;
    LOG_WARN("SortOperater child open failed!");
  }
  return rc;
}

RC SortPhysicalOperator::fetch_and_sort_table()
{
  RC rc = RC::SUCCESS;

  int index = 0;
  typedef std::pair<std::vector<Value>, int> CmpPair;
  std::vector<CmpPair> pair_sort_table;
  std::vector<Value> pair_value;

  auto &units = orderby_stmt_->orderby_units();
  while (RC::SUCCESS == (rc = children_[0]->next())) {
    // construct pair sort table
    // 1 cons vector<value>
    pair_value.clear();
    for (const OrderByUnit *unit : units) {
      Expression *expr = unit->expr();
      Value value;
      expr->get_value(*children_[0]->current_tuple(), value);
      pair_value.emplace_back(value);
    }
    // 2 cons pair
    // 3 cons pair vector
    pair_sort_table.emplace_back(std::make_pair(pair_value, index++));
    // store child records
    std::vector<Record *> cpd_rcd;
    children_[0]->current_tuple()->get_record(cpd_rcd);
    // need to deep copy the rcd and push back to rht
    // remember to delete them in dtor
    for (auto &rcd_ptr : cpd_rcd) {
      rcd_ptr = new Record(*rcd_ptr);
    }
    sort_table_.emplace_back(cpd_rcd);
  }
  if (RC::RECORD_EOF != rc) {
    LOG_ERROR("Fetch Table Error In SortOperator. RC: %d", rc);
    return rc;
  }
  rc = RC::SUCCESS;
  LOG_INFO("Fetch Table Success In SortOperator");
  // print_info();

  // then sort table
  bool order[units.size()];  // specify 1 asc or 2 desc
  for (std::vector<OrderByUnit *>::size_type i = 0; i < units.size(); ++i) {
    order[i] = units[i]->sort_type();
  }
  // consider null
  auto cmp = [&order](const CmpPair &a, const CmpPair &b) {
    auto &values_a = a.first;
    auto &values_b = b.first;
    assert(values_a.size() == values_b.size());
    for (size_t i = 0; i < values_a.size(); ++i) {
      auto &value_a = values_a[i];
      auto &value_b = values_b[i];
      if (value_a.attr_type()==AttrType::NULLS && value_b.attr_type()==AttrType::NULLS) {
        continue;
      }
      if (value_a.attr_type()==AttrType::NULLS) {
        return order[i] ? true : false;
      }
      if (value_b.attr_type()==AttrType::NULLS) {
        return order[i] ? false : true;
      }
      if (value_a != value_b) {
        return order[i] ? value_a < value_b : value_a > value_b;
      }
    }
    return false;  // completely same
  };
  std::sort(pair_sort_table.begin(), pair_sort_table.end(), cmp);
  LOG_INFO("Sort Table Success In SortOperator");

  // fill ordered_idx_
  for (size_t i = 0; i < pair_sort_table.size(); ++i) {
    ordered_idx_.emplace_back(pair_sort_table[i].second);
  }
  it_ = ordered_idx_.begin();

  return rc;  // return RC::SUCCESS
}

RC SortPhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  // at first cache child tuple and sort them
  if (is_first_) {
    is_first_ = false;
    rc = fetch_and_sort_table();
    if (RC::SUCCESS != rc) {
      return rc;
    }
  }

  if (ordered_idx_.end() != it_) {
    // NOTE: PAY ATTENTION HERE
    children_[0]->current_tuple()->set_record(sort_table_[*it_]);
    it_++;
    return RC::SUCCESS;
  }

  return RC::RECORD_EOF;
}

RC SortPhysicalOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

Tuple *SortPhysicalOperator::current_tuple()
{
  return children_[0]->current_tuple();
}
