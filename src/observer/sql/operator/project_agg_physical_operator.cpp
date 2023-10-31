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
    std::vector<int> count_res_no_null(num);
    std::vector<Value> sum_res(num);
    std::vector<Value> avg_res(num);
    std::vector<AttrType> attr_type(num); //记录每一列的类型，主要区分是不是int，用于求sum的时候输出int/float

    Value cell;
    RC rc = RC::SUCCESS;

    //获取第一个元组
    tuple_.set_tuple(children_[0]->current_tuple());
    
    for(int i=0; i<num; i++){
      rc = tuple_.cell_at(i, cell);
      if (cell.attr_type() == AttrType::NULLS){   // 该列是NULL值
        max_res[i] = cell;
        min_res[i] = cell;
        if (select_count_star_[i]){
          count_res[i] = 1;   // select count(*)
        }else{
          count_res[i] = 0;   // 如果是count(col)的话，NULL不统计，应该是0
          count_res_no_null[i] = 0;
        }
        sum_res[i] = cell;
        attr_type[i] = cell.attr_type();
      }
      else{
        max_res[i] = cell;
        min_res[i] = cell;
        count_res[i] = 1;
        count_res_no_null[i] = 1;
        sum_res[i].set_float(cell.get_float());
        attr_type[i] = cell.attr_type();
      }
    }

    //获取后续元组
    while (RC::SUCCESS == (rc = next())) {   
      tuple_.set_tuple(children_[0]->current_tuple());
      for(int i=0; i<num; i++){
        rc = tuple_.cell_at(i, cell);
        if (cell.attr_type() == AttrType::NULLS){   // 该列是NULL值
          min_res[i] = cell;      // NULL 是最小的，min_res更新，max_res不更新
          if (select_count_star_[i]){     // 如果是count(col)的话，NULL不统计
            count_res[i] += 1;   // select count(*)
          }
          // sum_res[i] += 0;     // NULL 值对sum/avg无影响
        } else {
          if(max_res[i].compare(cell) < 0){   //max_res[i] - cell
            max_res[i] = cell;
          }    
          if(min_res[i].compare(cell) > 0){   //min_res[i] - cell
            min_res[i] = cell;
          }
          count_res[i] += 1;     // select count(字段)?
          count_res_no_null[i] += 1;
          if(sum_res[i].attr_type() == AttrType::NULLS){    
            sum_res[i].set_float(cell.get_float());
          } else {               // 已经有值了（不是NULL），直接相加
            sum_res[i].set_float(sum_res[i].get_float() + cell.get_float());
          }
        }
      }
    }

    // 所有行的字段为NULL时则min/max/avg/sum结果为NULL
    for(int i=0; i<num; i++){
      if(sum_res[i].attr_type() == AttrType::NULLS){  //  所有行的字段为NULL
        avg_res[i].set_type(AttrType::NULLS);
      } else {
        avg_res[i].set_float(sum_res[i].get_float() / count_res_no_null[i]);
      }
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
        cell_res.set_value(avg_res[i]);
      }break;
      case SUM_OP:{
        if(attr_type[i] == INTS){
          cell_res.set_int((int)sum_res[i].get_float());
        }else{
          cell_res.set_value(sum_res[i]);
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
