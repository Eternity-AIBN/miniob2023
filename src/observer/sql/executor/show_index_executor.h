#pragma once

#include "common/rc.h"

class SQLStageEvent;

/**
 * @brief 展示索引的执行器
 * @ingroup Executor
 */
class ShowIndexExecutor
{
public:
  ShowIndexExecutor() = default;
  virtual ~ShowIndexExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};