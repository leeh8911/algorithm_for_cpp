/*!
 * @file hash_table_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hash/hash_table.h"

#include <gtest/gtest.h>

TEST(HashTableTest, NoDuplicatedHashValue) {
    algorithm::HashTable table(7);

    table.Emplace(1);
    table.Emplace(3);
    table.Emplace(5);

    EXPECT_DOUBLE_EQ(3.0 / 7.0, table.LoadFactor());

    EXPECT_TRUE(table.Contains(1));
    EXPECT_TRUE(table.Contains(3));
    EXPECT_TRUE(table.Contains(5));
    EXPECT_FALSE(table.Contains(9));
}
TEST(HashTableTest, DuplicatedHashValue) {
    algorithm::HashTable table(7);

    table.Emplace(1);
    table.Emplace(3);
    table.Emplace(10);
    table.Emplace(17);

    EXPECT_DOUBLE_EQ(2.0 / 7.0, table.LoadFactor());

    EXPECT_TRUE(table.Contains(1));
    EXPECT_FALSE(table.Contains(3));
    EXPECT_FALSE(table.Contains(10));
    EXPECT_TRUE(table.Contains(17));
}