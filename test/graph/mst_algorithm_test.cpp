/*!
 * @file mst_algorithm_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "graph/mst_algorithm.h"

#include <gtest/gtest.h>

#include <map>

class MstAlgorithmTest : public testing::Test {
 public:
    MstAlgorithmTest() = default;

 protected:
    void SetUp() override {
        graph.SizeVertices() = 9;

        std::map<uint64_t, std::vector<std::pair<uint64_t, WeightType>>>
            edge_map;
        edge_map[1] = {{2, 2}, {5, 3}};
        edge_map[2] = {{1, 2}, {5, 5}, {4, 1}};
        edge_map[3] = {{4, 2}, {7, 3}};
        edge_map[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
        edge_map[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
        edge_map[6] = {{4, 4}, {7, 4}, {8, 1}};
        edge_map[7] = {{3, 3}, {6, 4}};
        edge_map[8] = {{4, 5}, {5, 3}, {6, 1}};

        for (auto& i : edge_map) {
            for (auto& j : i.second) {
                graph.AddEdge(
                    algorithm::Edge<WeightType>{i.first, j.first, j.second});
            }
        }
    }
    void TearDown() override {}

    using WeightType = uint64_t;
    algorithm::Graph<WeightType> graph{};
};

TEST_F(MstAlgorithmTest, PrimAlgorithmCase) {
    auto result = algorithm::PrimAlgorithm<WeightType>(graph, 0);

    EXPECT_EQ(1, 1);
}