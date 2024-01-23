/*!
 * @file graph.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GRAPH_GRAPH_H_
#define SRC_GRAPH_GRAPH_H_

#include <algorithm>
#include <cassert>
#include <deque>
#include <iterator>
#include <unordered_set>
#include <vector>

namespace algorithm {
template <typename T>
struct Edge {
    using Node = uint64_t;
    Node from;
    Node to;
    T weight;

    Edge(Node from_, Node to_, T weight_ = 0)
        : from(from_), to(to_), weight(weight_) {}

    bool operator==(const Edge& other) {
        return ((from == other.from) && (to == other.to) &&
                (weight == other.weight));
    }
};

template <typename T>
using EdgeList = std::vector<Edge<T>>;

template <typename T>
class Graph {
 public:
    Graph() = default;
    Graph(size_t size_vertices) : m_size_vertices(size_vertices) {}

    void AddEdge(const Edge<T>& edge) {
        if (((0 <= edge.from) && (edge.from < m_size_vertices)) &&
            ((0 <= edge.to) && (edge.to < m_size_vertices))) {
            m_edges.emplace_back(edge);
        } else {
            assert(false);
        }
    }

    size_t& SizeVertices() { return m_size_vertices; }
    const size_t& SizeVertices() const { return m_size_vertices; }

    EdgeList<T> Edges() const { return m_edges; }
    EdgeList<T> Edges(uint64_t from) const {
        EdgeList<T> result{};

        std::copy_if(
            m_edges.begin(), m_edges.end(), std::back_inserter(result),
            [&from](const Edge<T>& edge) { return edge.from == from; });
        return result;
    }

 private:
    size_t m_size_vertices{};
    EdgeList<T> m_edges{};
};

template <typename T>
std::vector<uint64_t> BreadthFirstSearch(const Graph<T>& graph,
                                         uint64_t start) {
    std::unordered_set<uint64_t> visit{};
    std::vector<uint64_t> visit_order{};

    std::deque<uint64_t> q{start};

    while (!q.empty()) {
        auto vertex = q.front();
        q.pop_front();
        if (visit.contains(vertex)) {
            continue;
        }
        visit.emplace(vertex);
        visit_order.emplace_back(vertex);

        auto edges = graph.Edges(vertex);

        for (const auto& e : edges) {
            q.emplace_back(e.to);
        }
    }
}

template <typename T>
std::vector<uint64_t> DepthFirstSearch(const Graph<T>& graph, uint64_t start) {}

}  // namespace algorithm

#endif  // SRC_GRAPH_GRAPH_H_
