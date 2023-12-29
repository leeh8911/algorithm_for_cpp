/*!
 * @file heap.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ALGORITHM_FOR_CPP_HEAP_H
#define ALGORITHM_FOR_CPP_HEAP_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace algorithm {
template <typename VALUE, typename CONTAINER = std::vector<VALUE>,
          typename COMPARE = std::less<typename CONTAINER::value_type>>
class Heap {
 public:
    Heap() = default;

    void Emplace(const VALUE& value) {
        m_Container.emplace_back(value);

        size_t child_index = m_Container.size() - 1;
        size_t parent_index = child_index / 2;

        while (
            !m_Compare(m_Container[child_index], m_Container[parent_index])) {
            std::swap(m_Container[child_index], m_Container[parent_index]);
            child_index = parent_index;
            parent_index /= 2;

            if (parent_index >= child_index) {
                break;
            }
        }
    }

    const VALUE& Get() const { return m_Container.front(); }
    void Pop() {
        std::swap(m_Container.front(), m_Container.back());
        m_Container.pop_back();

        size_t parent_index = 0;

        while (parent_index < m_Container.size()) {
            size_t left_child = 2 * parent_index + 1;
            if ((left_child < m_Container.size()) &&
                !m_Compare(m_Container[left_child],
                           m_Container[parent_index])) {
                std::swap(m_Container[left_child], m_Container[parent_index]);
                parent_index = left_child;
                continue;
            }

            size_t right_child = 2 * parent_index + 2;
            if ((right_child < m_Container.size()) &&
                !m_Compare(m_Container[right_child],
                           m_Container[parent_index])) {
                std::swap(m_Container[right_child], m_Container[parent_index]);
                parent_index = right_child;
                continue;
            }
            break;
        }
    }

    size_t Size() const { return m_Container.size(); }
    bool Empty() const { return m_Container.empty(); }

    const CONTAINER& Container() const { return m_Container; }

 private:
    CONTAINER m_Container{};
    COMPARE m_Compare{};
};

}  // namespace algorithm

template <typename VALUE, typename CONTAINER, typename COMPARE>
std::ostream& operator<<(
    std::ostream& os, const algorithm::Heap<VALUE, CONTAINER, COMPARE>& heap) {
    auto container = heap.Container();

    for (const auto& elm : container) {
        os << elm << " ";
    }
    return os;
}
#endif  // ALGORITHM_FOR_CPP_HEAP_H