/*!
 * @file work_priority_scheduling.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GREEDY_WORK_PRIORITY_SCHEDULING_H_
#define SRC_GREEDY_WORK_PRIORITY_SCHEDULING_H_

#include <iterator>
#include <vector>

namespace algorithm {

void MinimizeMeanWaitingWorkScheduling(std::vector<int64_t>::iterator begin,
                                       std::vector<int64_t>::iterator end);
}

#endif  // SRC_GREEDY_WORK_PRIORITY_SCHEDULING_H_
