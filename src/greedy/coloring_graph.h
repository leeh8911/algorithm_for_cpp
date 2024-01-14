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

#include <memory>
#include <vector>

namespace algorithm {
template <typename T>
struct Edge {
    uint64_t from;
    uint64_t to;
    T weight;
};

template <typename T>
class Graph {
 public:
 private:
    std::vector<Edge> m_edges{};
};
}  // namespace algorithm

#endif  // SRC_GREEDY_COLORING_GRAPH_H_
