/*!
 * @file coloring_graph.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GREEDY_COLORING_GRAPH_H_
#define SRC_GREEDY_COLORING_GRAPH_H_

#include <vector>

namespace algorithm {
template <typename Color>
class ColoringGraph {
 public:
    ColoringGraph() = default;

    void AddEdge(int64_t from, int64_t to) {}

    std::vector<Color> Nodes() const { return nodes; };

 private:
    struct Edge {
        std::pair<int64_t, Color> from;
        std::pair<int64_t, Color> to;
    };
    std::vector<Edge> edges{};
    std::vector<Color> nodes{};
};
}  // namespace algorithm

#endif  // SRC_GREEDY_COLORING_GRAPH_H_
