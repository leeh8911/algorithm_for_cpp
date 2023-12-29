/*!
 * @file city_network_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "graph/city_network.h"

#include <gtest/gtest.h>

class CityNetworkTest : public testing::Test {
 public:
    CityNetworkTest() = default;

 protected:
    void SetUp() override {
        GTEST_SKIP() << "Skip CityNetwork Test";
        network.Add(algorithm::City::London, algorithm::City::Moscow, 2500);
        network.Add(algorithm::City::London, algorithm::City::Seoul, 9000);
        network.Add(algorithm::City::London, algorithm::City::Dubai, 5500);
        network.Add(algorithm::City::Seoul, algorithm::City::Moscow, 6600);
        network.Add(algorithm::City::Seoul, algorithm::City::Seattle, 8000);
        network.Add(algorithm::City::Seoul, algorithm::City::Dubai, 7000);
        network.Add(algorithm::City::Seoul, algorithm::City::Sydney, 8000);
        network.Add(algorithm::City::Seattle, algorithm::City::Moscow, 8400);
        network.Add(algorithm::City::Seattle, algorithm::City::Sydney, 12000);
        network.Add(algorithm::City::Dubai, algorithm::City::Sydney, 1200);
        network.Add(algorithm::City::Seattle, algorithm::City::London, 8000);
    }
    void TearDown() override {}

    algorithm::CityNetwork network{};
};

TEST_F(CityNetworkTest, MinimumCase) {
    EXPECT_EQ(2500, network.MinimumTravel(algorithm::City::London,
                                          algorithm::City::Moscow));

    // 5500(London->Dubai) + 1200(Dubai->Sydney);
    EXPECT_EQ(6700, network.MinimumTravel(algorithm::City::London,
                                          algorithm::City::Sydney));
}
