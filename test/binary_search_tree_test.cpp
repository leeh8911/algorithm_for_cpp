/// @file dummy_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-01-13
///
/// @copyright Copyright (c) 2023
///
///

#include "tree/binary_search_tree.h"

#include <gtest/gtest.h>

#include <cstdint>

TEST(BinarySearchTreeTest, FindValueCase) {
    algorithm::BinarySearchTree<int64_t> bst;
    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(4);
    bst.Insert(7);
    bst.Insert(6);

    EXPECT_EQ(6, bst.Find(6)->value);
    EXPECT_EQ(nullptr, bst.Find(10));

    bst.Delete(6);
    EXPECT_EQ(nullptr, bst.Find(6));
}
