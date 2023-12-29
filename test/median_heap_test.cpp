/*!
 * @file median_heap_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "heap/median_heap.h"

#include <gtest/gtest.h>

TEST(MedianHeapTest, MedianHeapCase) {
    algorithm::MedianHeap heap;

    heap.Emplace(1);
    EXPECT_EQ(1, heap.Get());

    heap.Emplace(5);
    EXPECT_EQ(3, heap.Get());

    heap.Emplace(2);
    EXPECT_EQ(2, heap.Get());

    heap.Emplace(10);
    EXPECT_EQ(3.5, heap.Get());

    heap.Emplace(40);
    EXPECT_EQ(5, heap.Get());
}
