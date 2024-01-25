/*!
 * @file mst_algorithm.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GRAPH_MST_ALGORITHM_H_
#define SRC_GRAPH_MST_ALGORITHM_H_

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

#include "graph/graph.h"

namespace algorithm {
template <typename T>
struct Label {
    uint64_t id;
    T distance;

    inline bool operator>(const Label<T>& other) const {
        return distance > other.distance;
    }
};

template <typename T>
using LabelList = std::vector<Label<T>>;

template <typename T>
std::vector<typename Edge<T>::Node> PrimAlgorithm(
    const Graph<T>& graph, typename Edge<T>::Node start) {
    std::vector<typename Edge<T>::Node> result{};

    std::priority_queue<Label<T>, LabelList<T>, std::greater<Label<T>>> heap{};
    std::vector<T> distances(graph.SizeVertices(),
                             std::numeric_limits<T>::max());
    std::unordered_set<typename Edge<T>::Node> visit;

    heap.emplace(Label<T>{start, 0});

    while (!heap.empty()) {
        auto current_vertex = heap.top();
        heap.pop();

        if (!visit.contains(current_vertex.id)) {
            result.emplace_back(current_vertex.id);

            for (auto& e : graph.Edges(current_vertex.id)) {
                auto neighbor = e.to;
                auto new_distance = e.weight;

                if (new_distance < distances[neighbor]) {
                    heap.emplace(Label<T>{neighbor, new_distance});
                    distances[neighbor] = new_distance;
                }
            }

            visit.insert(current_vertex.id);
        }
    }

    return result;
}

template <typename T>
std::vector<typename Edge<T>::Node> DijkstraAlgorithm(
    const Graph<T>& graph, typename Edge<T>::Node start,
    typename Edge<T>::Node end) {
    std::vector<typename Edge<T>::Node> mst{};

    std::priority_queue<Label<T>, LabelList<T>, std::greater<Label<T>>> heap{};
    std::vector<T> distances(graph.SizeVertices(),
                             std::numeric_limits<T>::max());
    std::vector<typename Edge<T>::Node> parent(graph.SizeVertices());
    std::unordered_set<typename Edge<T>::Node> visit;

    heap.emplace(Label<T>{start, 0});

    while ((!heap.empty())) {
        auto current_vertex = heap.top();
        heap.pop();

        if (!visit.contains(current_vertex.id)) {
            mst.emplace_back(current_vertex.id);

            for (auto& e : graph.Edges(current_vertex.id)) {
                auto neighbor = e.to;
                auto new_distance = current_vertex.distance + e.weight;

                if (new_distance < distances[neighbor]) {
                    heap.emplace(Label<T>{neighbor, new_distance});

                    parent[neighbor] = current_vertex.id;
                    distances[neighbor] = new_distance;
                }
            }

            visit.insert(current_vertex.id);
        }

        if (current_vertex.id == end) {
            break;
        }
    }
    std::vector<typename Edge<T>::Node> result{};
    auto current_vertex = end;

    while (current_vertex != start) {
        result.emplace_back(current_vertex);
        current_vertex = parent[current_vertex];
    }
    result.emplace_back(start);
    std::reverse(result.begin(), result.end());

    return result;
}

template <typename T>
std::vector<T> BellmanFordAlgorithm(const Graph<T>& graph,
                                    typename Edge<T>::Node start) {
    constexpr T kMaxValue = std::numeric_limits<T>::max();
    std::vector<T> distances(graph.SizeVertices(), kMaxValue);
    distances[start] = 0;

    for (int16_t i = 0; i < graph.SizeVertices() - 1; ++i) {
        for (const auto& edge : graph.Edges()) {
            if (distances[edge.from] == kMaxValue) {
                continue;
            }

            if (distances[edge.to] > distances[edge.from] + edge.weight) {
                distances[edge.to] = distances[edge.from] + edge.weight;
            }
        }
    }
    return distances;
}

}  // namespace algorithm

#endif  // SRC_GRAPH_MST_ALGORITHM_H_
