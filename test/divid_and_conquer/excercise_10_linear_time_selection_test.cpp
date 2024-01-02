/*!
 * @file excercise_10_linear_time_selection_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "divid_and_conquer/excercise_10_linear_time_selection.h"

#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "divid_and_conquer/sort.h"
#include "util.h"

TEST(LinearTimeSelectionTest, SampleCase) {
    size_t size = 100;
    std::vector<int64_t> v =
        test_util::Random::Generate<std::vector<int64_t>>(0, 99, size);
    size_t nth = test_util::Random::Generate<size_t>(0, size - 1);

    auto v_copy = v;

    auto result = algorithm::LinearTimeSelection<std::vector<int64_t>>(
        v.begin(), v.end() - 1, nth);

    algorithm::QuickSort<std::vector<int64_t>>(v_copy.begin(),
                                               v_copy.end() - 1);

    EXPECT_EQ(*(v_copy.begin() + nth), *result);
    std::cout << "N-th: " << nth << "\n";
    std::cout << v_copy << "\n";
}

TEST(LinearTimeSelectionTest, FindMedianCase) {
    std::vector<int64_t> v = {5, 3, 1, 4, 2};

    auto median =
        algorithm::FindMedian<std::vector<int64_t>, std::less<int64_t>>(
            v.begin(), v.end() - 1);

    EXPECT_EQ(*median, 3);
}
TEST(LinearTimeSelectionTest, PartitionCase) {
    std::vector<int64_t> v = {5, 3, 1, 4, 2};

    auto right_iter = algorithm::PartitionUsingGivePivot<std::vector<int64_t>,
                                                         std::less<int64_t>>(
        v.begin(), v.end() - 1, *(v.begin() + 3));

    EXPECT_EQ(*right_iter, 4);
    EXPECT_EQ(*(v.begin()), 2);
}