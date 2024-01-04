/*!
 * @file dividable_packing_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "greedy/dividable_packing.h"

#include <gtest/gtest.h>

#include "util.h"

TEST(DividablePackingTest, SampleCase) {
    std::vector<int64_t> ids = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int64_t> weights = {1, 2, 5, 9, 2, 3, 4};
    std::vector<double> prices = {10., 7., 15., 10., 12., 11., 5.};

    std::vector<algorithm::Object> objects{};
    objects.reserve(weights.size());

    auto id_iter = ids.begin();
    auto weight_iter = weights.begin();
    auto price_iter = prices.begin();
    for (; weight_iter != weights.end();
         ++id_iter, ++weight_iter, ++price_iter) {
        objects.emplace_back(*id_iter, *weight_iter, *price_iter);
    }

    auto result = algorithm::DividablePacking(objects, 7);

    EXPECT_EQ(4, result.size());
    EXPECT_EQ(algorithm::Object(1, 1, 10.), result[0]);
    EXPECT_EQ(algorithm::Object(5, 2, 12.), result[1]);
    EXPECT_EQ(algorithm::Object(6, 3, 11.), result[2]);
    EXPECT_EQ(algorithm::Object(2, 1, 3.5), result[3]);
}