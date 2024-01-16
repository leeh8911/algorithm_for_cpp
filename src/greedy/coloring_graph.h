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

#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algorithm {
template <typename T>
struct Node;

template <typename T>
using NodePtr = std::shared_ptr<Node<T>>;

template <typename T>
struct Node {
    T value;
    std::vector<NodePtr<T>> nexts;
    Node(const T& val) : value(val), nexts{} {}
};

template <typename T>
class Graph {
 public:
    Graph() = default;
    void AddEdge(T from, T to) {
        auto from_it = std::find_if(
            nodes.begin(), nodes.end(),
            [from](const NodePtr<T>& n) { return n->value == from; });
        if (from_it == nodes.end()) {
            nodes.emplace_back(from);
            *from_it = nodes.back();
        }

        auto to_it =
            std::find_if(nodes.begin(), nodes.end(),
                         [to](const NodePtr<T>& n) { return n->value == to; });
        if (to_it == nodes.end()) {
            nodes.emplace_back(to);
            *to_it = nodes.back();
        }

        (*from_it)->nexts.emplace_back(*to_it);
        (*to_it)->nexts.emplace_back(*from_it);
    }

    template <typename Color>
    std::unordered_map<T, Color> ColorNodes() {
        std::unordered_map<T, Color> colored{};

        std::sort(nodes.begin(), nodes.end(),
                  [](const auto& lhs, const auto& rhs) {
                      return lhs->nexts.size() < rhs->nexts.size();
                  });

        for (const auto& elm : nodes) {
            std::cout << elm->nexts.size() << " ";
        }
        return colored;
    }

    std::vector<NodePtr<T>> Nodes() const { return nodes; }

 private:
    std::vector<NodePtr<T>> nodes{};
};
}  // namespace algorithm

#endif  // SRC_GREEDY_COLORING_GRAPH_H_
