#include "common/log/log.h"
#include "sql/operator/project_agg_physical_operator.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC ProjectAggPhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectAggPhysicalOperator::next()
{
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  return children_[0]->next();
}

RC ProjectAggPhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}
Tuple *ProjectAggPhysicalOperator::current_tuple()
{
    // agg TODO 在这里进行聚合函数的计算，由sql_result中的tuple = operator_->current_tuple();调用返回结果
    // 在这里不断调用 operator_->next(); 才能获得所有元组

    // std::vector<AggOp> aggop_;

    // 保存每一列的max、min、count、sum
    int num = aggop_.size();     //确定列数
    std::vector<Value> max_res(num);
    std::vector<Value> min_res(num);
    std::vector<int> count_res(num);
    std::vector<float> sum_res(num);
    std::vector<float> avg_res(num);
    std::vector<AttrType> attr_type(num); //记录每一列的类型，主要区分是不是int，用于求sum的时候输出int/float

    Value cell;
    RC rc = RC::SUCCESS;

    //获取第一个元组
    tuple_.set_tuple(children_[0]->current_tuple());
    
    for(int i=0; i<num; i++){
      rc = tuple_.cell_at(i, cell);
      max_res[i] = cell;
      min_res[i] = cell;
      count_res[i] = 1;
      sum_res[i] = cell.get_float();
      attr_type[i] = cell.attr_type();
    }

    //获取后续元组
    while (RC::SUCCESS == (rc = next())) {   
      tuple_.set_tuple(children_[0]->current_tuple());
      // count_res[i] += 1;          // select count(*)?
      for(int i=0; i<num; i++){
        rc = tuple_.cell_at(i, cell);
        if(max_res[i].compare(cell) < 0){   //max_res[i] - cell
          max_res[i] = cell;
        }    
        if(min_res[i].compare(cell) > 0){   //min_res[i] - cell
          min_res[i] = cell;
        }
        count_res[i] += 1;     // select count(字段)?
        sum_res[i] += cell.get_float();
      }
    }

    for(int i=0; i<num; i++){
      avg_res[i] = sum_res[i] / count_res[i];
    }

    
    std::vector<Value> cells_res;
    Value cell_res; 
    for(int i=0; i<num; i++){
      switch (aggop_[i])
      {
      case MAX_OP:{
        cell_res.set_value(max_res[i]);
      }break;
      case MIN_OP:{
        cell_res.set_value(min_res[i]);
      }break;
      case COUNT_OP:{
        cell_res.set_int(count_res[i]);
      }break;
      case AVG_OP:{
        cell_res.set_float(avg_res[i]);
      }break;
      case SUM_OP:{
        if(attr_type[i] == INTS){
          cell_res.set_int((int)sum_res[i]);
        }else{
          cell_res.set_float(sum_res[i]);
        }
      }break;
      default:
        break;
      }
      cells_res.emplace_back(cell_res);
    }
    res_tuple.set_cells(cells_res);

  return &res_tuple;
}

void ProjectAggPhysicalOperator::add_projection(const Table *table, const FieldMeta *field_meta)
{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec = new TupleCellSpec(table->name(), field_meta->name(), field_meta->name());
  tuple_.add_cell_spec(spec);
}
