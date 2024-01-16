/*!
 * @file coloring_graph_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "greedy/coloring_graph.h"

#include <gtest/gtest.h>

enum class Color { Red = 1, Blue, Green, Yellow, Black, White };

TEST(ColoringGraphTest, SampleCase) {
    algorithm::Graph<uint64_t> graph{};

    graph.AddEdge(1, 2);
    graph.AddEdge(1, 5);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 7);
    graph.AddEdge(4, 5);
    graph.AddEdge(4, 6);
    graph.AddEdge(4, 8);
    graph.AddEdge(5, 8);
    graph.AddEdge(6, 8);

    auto nodes = graph.Nodes();

    graph.ColorNodes<Color>();

    // EXPECT_EQ(Color::Red, nodes[0]);
    // EXPECT_EQ(Color::Blue, nodes[1]);
    // EXPECT_EQ(Color::Red, nodes[2]);
    // EXPECT_EQ(Color::Green, nodes[3]);
    // EXPECT_EQ(Color::Yellow, nodes[4]);
    // EXPECT_EQ(Color::Red, nodes[5]);
    // EXPECT_EQ(Color::Blue, nodes[6]);
    // EXPECT_EQ(Color::Blue, nodes[7]);
}