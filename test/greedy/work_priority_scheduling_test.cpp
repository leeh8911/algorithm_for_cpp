/*!
 * @file work_priority_scheduling_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "greedy/work_priority_scheduling.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <vector>

#include "util.h"

TEST(WorkPrioritySchedulingTest, SampleCase) {
    std::vector<int64_t> works{8, 1, 2, 4, 9, 2, 3, 5};

    algorithm::MinimizeMeanWaitingWorkScheduling(works.begin(), works.end());

    std::vector<int64_t> waitings{};
    int64_t sum = 0;
    std::transform(works.begin(), works.end(), std::back_inserter(waitings),
                   [&sum](int64_t work) {
                       auto result = sum;
                       sum += work;
                       return result;
                   });

    double mean_time = static_cast<double>(
        std::accumulate(waitings.begin(), waitings.end(), 0LL));
    mean_time /= static_cast<double>(waitings.size());

    EXPECT_DOUBLE_EQ(8.875, mean_time);
    std::cout << "works: " << works << "\n";
}