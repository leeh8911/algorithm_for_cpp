/*!
 * @file hash_table_wtih_duplication_linked_list_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <gtest/gtest.h>

#include "hash/hash_table_with_duplication_linked_list.h"

TEST(HashTableLinkedListTest, NoDuplicatedHashValue) {
    algorithm::HashTableLinkedList table(7);

    table.Emplace(1);
    table.Emplace(3);
    table.Emplace(5);

    EXPECT_DOUBLE_EQ(3.0 / 7.0, table.LoadFactor());

    EXPECT_TRUE(table.Contains(1));
    EXPECT_TRUE(table.Contains(3));
    EXPECT_TRUE(table.Contains(5));
    EXPECT_FALSE(table.Contains(9));
}
TEST(HashTableLinkedListTest, DuplicatedHashValue) {
    algorithm::HashTableLinkedList table(7);

    table.Emplace(1);
    table.Emplace(3);
    table.Emplace(10);
    table.Emplace(17);

    EXPECT_DOUBLE_EQ(4.0 / 7.0, table.LoadFactor());

    EXPECT_TRUE(table.Contains(1));
    EXPECT_TRUE(table.Contains(3));
    EXPECT_TRUE(table.Contains(10));
    EXPECT_TRUE(table.Contains(17));
}