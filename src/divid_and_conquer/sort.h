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
}  // namespace algorithm

#endif  // SRC_DIVID_AND_CONQUER_SORT_H_
