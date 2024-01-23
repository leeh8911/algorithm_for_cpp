/*!
 * @file graph_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "graph/graph.h"

#include <gtest/gtest.h>

#include <algorithm>

TEST(GraphTest, ReturnAllEdges) {
    algorithm::Graph<int32_t> graph(4);

    graph.AddEdge({0, 1, 0});
    graph.AddEdge({1, 2, 0});
    graph.AddEdge({2, 3, 0});
    graph.AddEdge({3, 0, 0});

    auto edges = graph.Edges();

    EXPECT_EQ(4, edges.size());

    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{0, 1, 0}) != edges.end());
    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{1, 2, 0}) != edges.end());
    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{2, 3, 0}) != edges.end());
    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{3, 0, 0}) != edges.end());
}
TEST(GraphTest, SpecificEdges) {
    algorithm::Graph<int32_t> graph(4);

    graph.AddEdge({0, 1, 0});
    graph.AddEdge({1, 2, 0});
    graph.AddEdge({2, 3, 0});
    graph.AddEdge({3, 0, 0});
    graph.AddEdge({2, 0, 0});

    auto edges = graph.Edges(2);

    EXPECT_EQ(2, edges.size());

    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{2, 3, 0}) != edges.end());
    EXPECT_TRUE(std::find(edges.begin(), edges.end(),
                          algorithm::Edge{2, 0, 0}) != edges.end());
}