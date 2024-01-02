/*!
 * @file work_priority_scheduling.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "greedy/work_priority_scheduling.h"

#include <algorithm>
#include <iterator>
#include <vector>


namespace algorithm {

void MinimizeMeanWaitingWorkScheduling(std::vector<int64_t>::iterator begin,
                                       std::vector<int64_t>::iterator end) {
    std::sort(begin, end);
}
}  // namespace algorithm