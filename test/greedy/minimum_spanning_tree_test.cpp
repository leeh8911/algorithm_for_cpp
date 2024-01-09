/*!
 * @file minimum_spanning_tree_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "greedy/minimum_spanning_tree.h"

#include <gtest/gtest.h>

TEST(MinimumSpanningTreeTest, SampleCase) {
    algorithm::Graph g;

    g.AddEdge({1, 2, 2});
    g.AddEdge({1, 5, 3});
    g.AddEdge({2, 4, 1});
    g.AddEdge({2, 5, 5});
    g.AddEdge({3, 4, 2});
    g.AddEdge({3, 7, 3});
    g.AddEdge({4, 5, 2});
    g.AddEdge({4, 6, 4});
    g.AddEdge({4, 8, 5});
    g.AddEdge({5, 8, 3});
    g.AddEdge({6, 7, 4});
    g.AddEdge({6, 8, 1});

    auto result = MinimumSpanningTree(g);
    EXPECT_EQ(14, result.Weight());

    EXPECT_EQ(7, result.Edges().size());

    auto edges = result.Edges();
    std::sort(edges.begin(), edges.end(),
              [](const algorithm::Edge& lhs, const algorithm::Edge& rhs) {
                  return lhs.weight > rhs.weight;
              });

    EXPECT_EQ("3-7(3)", edges[0].ToString());
    EXPECT_EQ("5-8(3)", edges[1].ToString());
    EXPECT_EQ("4-5(2)", edges[2].ToString());
    EXPECT_EQ("1-2(2)", edges[3].ToString());
    EXPECT_EQ("3-4(2)", edges[4].ToString());
    EXPECT_EQ("2-4(1)", edges[5].ToString());
    EXPECT_EQ("6-8(1)", edges[6].ToString());
}