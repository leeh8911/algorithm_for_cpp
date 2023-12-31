/*!
 * @file excercise_9_partial_sort_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "divid_and_conquer/excercise_9_partial_sort.h"

#include <gtest/gtest.h>

#include <random>
#include <vector>

#include "divid_and_conquer/sort.h"
#include "util.h"

TEST(ExcercisePartialSortTest, SampleCase) {
    std::vector<int64_t> v =
        test_util::Random::Generate<decltype(v)>(1, 99, 100);

    auto v_copy = v;

    int64_t partial_size = 10;

    {
        std::cout << "Partial QuickSort\n";
        test_util::Timer _{};
        algorithm::PartialQuickSort<decltype(v)>(v.begin(), v.end() - 1,
                                                 partial_size);
    }
    {
        std::cout << "Total QuickSort\n";
        test_util::Timer _{};
        algorithm::QuickSort<decltype(v_copy)>(v_copy.begin(),
                                               v_copy.end() - 1);
    }

    EXPECT_EQ(v[0], v_copy[0]);
    EXPECT_EQ(v[1], v_copy[1]);
    EXPECT_EQ(v[2], v_copy[2]);
    EXPECT_EQ(v[3], v_copy[3]);
    EXPECT_EQ(v[4], v_copy[4]);
    EXPECT_EQ(v[5], v_copy[5]);
    EXPECT_EQ(v[6], v_copy[6]);
    EXPECT_EQ(v[7], v_copy[7]);
    EXPECT_EQ(v[8], v_copy[8]);
    EXPECT_EQ(v[9], v_copy[9]);

    std::cout << "Partial_QuickSort: \n";
    std::cout << v << "\n";

    std::cout << "QuickSort:\n";
    std::cout << v_copy << "\n";
}