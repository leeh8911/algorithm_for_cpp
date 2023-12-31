/*!
 * @file sort.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_DIVID_AND_CONQUER_SORT_H_
#define SRC_DIVID_AND_CONQUER_SORT_H_

#include <functional>
#include <iostream>
#include <iterator>
namespace algorithm {
template <typename Container,
          typename Compare = std::less<typename Container::value_type>>
void MergeSort(typename Container::iterator begin,
               typename Container::iterator end) {
    auto dist = std::distance(begin, end);
    if (dist <= 1) {
        return;
    }
    if (dist == 2) {
        if (!Compare()(*begin, *(begin + 1))) {
            std::iter_swap(begin, begin + 1);
        }
        return;
    }

    auto mid = begin + dist / 2;

    MergeSort<Container, Compare>(begin, mid);
    MergeSort<Container, Compare>(mid, end);

    Container temporal_container{};
    temporal_container.reserve(dist);

    auto it = begin;
    auto jt = mid;
    while (it != mid && jt != end) {
        if (Compare()(*it, *jt)) {
            temporal_container.emplace_back(*it);
            ++it;
        } else {
            temporal_container.emplace_back(*jt);
            ++jt;
        }
    }

    std::copy(temporal_container.begin(), temporal_container.end(), begin);

    return;
}

template <typename Container, typename Compare>
typename Container::iterator Partition(typename Container::iterator begin,
                                       typename Container::iterator last) {
    const auto pivot_value = *begin;
    auto left_iter = begin + 1;
    auto right_iter = last;

    while (true) {
        while (!Compare()(pivot_value, *left_iter) &&
               std::distance(left_iter, right_iter) > 0) {
            ++left_iter;
        }
        while (Compare()(pivot_value, *right_iter) &&
               distance(left_iter, right_iter) > 0) {
            --right_iter;
        }

        if (left_iter == right_iter) {
            break;
        }

        std::iter_swap(left_iter, right_iter);
    }
    if (Compare()(*right_iter, pivot_value)) {
        std::iter_swap(begin, right_iter);
    }

    return right_iter;
}
template <typename Container,
          typename Compare = std::less<typename Container::value_type>>
void QuickSort(typename Container::iterator begin,
               typename Container::iterator last) {
    auto size = std::distance(begin, last) + 1;

    if (size <= 1) {
        return;
    }
    auto partition_iter = Partition<Container, Compare>(begin, last);

    QuickSort<Container, Compare>(begin, partition_iter - 1);
    QuickSort<Container, Compare>(partition_iter, last);
}
}  // namespace algorithm

#endif  // SRC_DIVID_AND_CONQUER_SORT_H_
