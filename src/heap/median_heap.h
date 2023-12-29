/*!
 * @file median_heap.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ALGORITHM_FOR_CPP_HEAP_MEDIAN_HEAP_H
#define ALGORITHM_FOR_CPP_HEAP_MEDIAN_HEAP_H

#include "heap/heap.h"

namespace algorithm {

class MedianHeap {
 public:
    MedianHeap() = default;

    void Emplace(int64_t value) {
        if (m_MaxHeap.Empty()) {
            m_MaxHeap.Emplace(value);
        } else if (value < m_MaxHeap.Get()) {
            m_MaxHeap.Emplace(value);
        } else {
            m_MinHeap.Emplace(value);
        }

        if (m_MaxHeap.Size() > m_MinHeap.Size() + 1) {
            m_MinHeap.Emplace(m_MaxHeap.Get());
            m_MaxHeap.Pop();
        } else if (m_MaxHeap.Size() + 1 < m_MinHeap.Size()) {
            m_MaxHeap.Emplace(m_MinHeap.Get());
            m_MinHeap.Pop();
        }
    }
    double Get() const {
        if (m_MaxHeap.Size() < m_MinHeap.Size()) {
            return static_cast<double>(m_MinHeap.Get());
        } else if (m_MaxHeap.Size() > m_MinHeap.Size()) {
            return static_cast<double>(m_MaxHeap.Get());
        } else {
            return static_cast<double>(m_MaxHeap.Get() + m_MinHeap.Get()) / 2.0;
        }
    }
    size_t Size() const { return m_MaxHeap.Size() + m_MinHeap.Size(); }

 private:
    Heap<int64_t, std::vector<int64_t>, std::less<int64_t>> m_MaxHeap{};
    Heap<int64_t, std::vector<int64_t>, std::greater<int64_t>> m_MinHeap{};
};
}  // namespace algorithm
#endif  // ALGORITHM_FOR_CPP_HEAP_MEDIAN_HEAP_H