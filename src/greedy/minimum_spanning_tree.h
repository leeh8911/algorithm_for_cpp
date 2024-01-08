/*!
 * @file minimum_spanning_tree.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GREEDY_MINIMUM_SPANNING_TREE_H_
#define SRC_GREEDY_MINIMUM_SPANNING_TREE_H_

#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace algorithm {

class SimpleDisjointSet {
 public:
    SimpleDisjointSet() = default;

    void MakeSet(const uint64_t& x) { m_nodes.emplace_back(x); }

    uint64_t Find(uint64_t x) {
        auto node_it =
            std::find_if(m_nodes.begin(), m_nodes.end(),
                         [x](const Node& node) { return node.id == x; });

        auto node_id = node_it->id;

        while (node_id != m_nodes[node_id].parent) {
            node_id = m_nodes[node_id].parent;
        }

        return node_id;
    }

    void UnionSets(uint64_t x, uint64_t y) {
        auto root_x = Find(x);
        auto root_y = Find(y);

        if (root_x == root_y) {
            return;
        }

        if (m_nodes[root_x].rank > m_nodes[root_y].rank) {
            std::swap(root_x, root_y);
        }

        m_nodes[root_x].parent = m_nodes[root_y].parent;
        ++m_nodes[root_y].rank;
    }

 private:
    struct Node {
        uint64_t id{};
        uint64_t rank{};
        uint64_t parent{};

        explicit Node(uint64_t id) : id(id), rank(0), parent(id) {}

        bool operator!=(const Node& n) const { return this->id != n.id; }
    };

    std::vector<Node> m_nodes{};
};
struct Edge {
    uint64_t from;
    uint64_t to;
    int64_t weight;

    bool operator<(const Edge& other) const { return weight < other.weight; }
    bool operator>(const Edge& other) const { return weight > other.weight; }
    std::string ToString() const {
        return std::to_string(from) + "-" + std::to_string(to) + "(" +
               std::to_string(weight) + ")";
    }
};

using EdgeList = std::vector<Edge>;

class Graph {
 public:
    Graph() = default;

    void AddEdge(const Edge& edge) {
        std::cout << "Graph::AddEdge - " << edge.from << " -> " << edge.to
                  << " (" << edge.weight << ")\n";
        m_edges.emplace_back(edge);
    }

    EdgeList Edges() const { return m_edges; }
    EdgeList Edges(uint64_t v) const {
        EdgeList edges_from_v{};

        for (auto& e : m_edges) {
            if (e.from == v) {
                edges_from_v.emplace_back(e);
            }
        }
        return edges_from_v;
    }

    int64_t Weight() const {
        int64_t result = 0;
        for (const auto& e : m_edges) {
            result += e.weight;
        }
        return result;
    }

 private:
    EdgeList m_edges{};
};

Graph MinimumSpanningTree(const Graph& g) {
    std::priority_queue<Edge, EdgeList, std::greater<Edge>> heap;

    for (auto& e : g.Edges()) {
        heap.emplace(e);
    }

    SimpleDisjointSet disjoint_set{};

    Graph result;
    while (!heap.empty()) {
        auto e = heap.top();
        heap.pop();

        if (disjoint_set.Find(e.from) != disjoint_set.Find(e.to)) {
            result.AddEdge(e);
            disjoint_set.UnionSets(e.from, e.to);
        }
    }

    return result;
}
}  // namespace algorithm

#endif  // SRC_GREEDY_MINIMUM_SPANNING_TREE_H_
