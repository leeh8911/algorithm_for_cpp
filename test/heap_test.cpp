/*!
 * @file heap_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "heap/heap.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

TEST(HeapTest, MaxHeapCase) {
    algorithm::Heap<int64_t> max_heap;

    max_heap.Emplace(5);
    max_heap.Emplace(3);
    max_heap.Emplace(1);
    max_heap.Emplace(7);

    EXPECT_EQ(7, max_heap.Get());

    max_heap.Pop();
    EXPECT_EQ(5, max_heap.Get());

    max_heap.Pop();
    EXPECT_EQ(3, max_heap.Get());

    max_heap.Pop();
    EXPECT_EQ(1, max_heap.Get());
}

TEST(HeapTest, MinHeapCase) {
    algorithm::Heap<int64_t, std::vector<int64_t>, std::greater<>> min_heap;

    min_heap.Emplace(5);
    min_heap.Emplace(3);
    min_heap.Emplace(1);
    min_heap.Emplace(7);

    EXPECT_EQ(1, min_heap.Get());

    min_heap.Pop();
    EXPECT_EQ(3, min_heap.Get());

    min_heap.Pop();
    EXPECT_EQ(5, min_heap.Get());

    min_heap.Pop();
    EXPECT_EQ(7, min_heap.Get());
}
