/*!
 * @file excercise_9_partial_sort.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_DIVID_AND_CONQUER_EXCERCISE_9_PARTIAL_SORT_H_
#define SRC_DIVID_AND_CONQUER_EXCERCISE_9_PARTIAL_SORT_H_

#include <functional>

#include "divid_and_conquer/sort.h"

namespace algorithm {
template <typename Container,
          typename Compare = std::less<typename Container::value_type>>
void PartialQuickSort(typename Container::iterator begin,
                      typename Container::iterator last, int64_t partial_size) {
    if (std::distance(begin, last) + 1 <= 1) {
        return;
    }

    auto pivot_iter = Partition<Container, Compare>(begin, last);

    auto pivot_count = std::distance(begin, pivot_iter);

    PartialQuickSort<Container, Compare>(begin, pivot_iter - 1, partial_size);
    if (pivot_count < partial_size) {
        PartialQuickSort<Container, Compare>(pivot_iter, last,
                                             partial_size - pivot_count);
    }

    return;
}
}  // namespace algorithm

#endif  // SRC_DIVID_AND_CONQUER_EXCERCISE_9_PARTIAL_SORT_H_
