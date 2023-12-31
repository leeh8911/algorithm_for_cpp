/*!
 * @file sort_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "divid_and_conquer/sort.h"

#include <gtest/gtest.h>

#include <vector>

TEST(SortTest, MergeSortCase) {
    std::vector<int64_t> v{1, 5, 9, 3, 7, 11, 46, 84, 23, 65, 70, 26};

    algorithm::MergeSort<decltype(v)>(v.begin(), v.end());

    auto it = v.begin();
    auto jt = it + 1;
    while (jt != v.end()) {
        EXPECT_LE(*it, *jt);
        ++it;
        ++jt;
    }
}
TEST(SortTest, QuickSortCase) {
    std::vector<int64_t> v{1, 5, 9, 3, 7, 11, 46, 84, 23, 65, 70, 26};

    std::cout << "QuickSortCase\n";
    for (const auto& elm : v) {
        std::cout << elm << " ";
    }
    std::cout << "\n";
    algorithm::QuickSort<decltype(v)>(v.begin(), v.end() - 1);

    auto it = v.begin();
    auto jt = it + 1;
    while (jt != v.end()) {
        EXPECT_LE(*it, *jt);
        ++it;
        ++jt;
    }
}