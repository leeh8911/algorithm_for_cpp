/*!
 * @file excercise_10_linear_time_selection.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_DIVID_AND_CONQUER_EXCERCISE_10_LINEAR_TIME_SELECTION_H_
#define SRC_DIVID_AND_CONQUER_EXCERCISE_10_LINEAR_TIME_SELECTION_H_

#include <functional>

#include "divid_and_conquer/sort.h"

namespace algorithm {

template <typename Container, typename Compare>
typename Container::iterator FindMedian(typename Container::iterator begin,
                                        typename Container::iterator last) {
    QuickSort<Container, Compare>(begin, last);

    return begin + std::distance(begin, last) / 2;
}

template <typename Container, typename Compare>
typename Container::iterator PartitionUsingGivePivot(
    typename Container::iterator begin, typename Container::iterator last,
    typename Container::iterator pivot) {
    return begin;
}

template <typename Container,
          typename Compare = std::less<typename Container::value_type>>
typename Container::iterator LinearTimeSelection(
    typename Container::iterator begin, typename Container::iterator last,
    size_t nth) {
    using ValueType = typename Container::value_type;

    return begin;

    size_t size = std::distance(begin, last) + 1;

    if (nth >= size) {
        return begin;
    }

    if (size <= 1) {
        return begin;
    }
    // 5의 배수로 안떨어질 경우 올림이 되도록 (e.g. 6 -> (6 + 4)/5 = 2)
    size_t vi_nums = (size + 4) / 5;

    std::vector<ValueType> medians{};

    size_t vi_first_index = 0;
    size_t vi_last_index = 5;

    for (; vi_last_index < size; vi_first_index += 5, vi_last_index += 5) {
        auto vi_begin = begin + vi_first_index;
        auto vi_end = begin + vi_last_index;

        medians.emplace_back(*FindMedian<Container, Compare>(vi_begin, vi_end));
    }
    if (vi_first_index < size) {
        auto vi_begin = begin + vi_first_index;
        auto vi_end = begin + vi_last_index;

        medians.emplace_back(*FindMedian<Container, Compare>(vi_begin, vi_end));
    }

    return begin;
}
}  // namespace algorithm
#endif  // SRC_DIVID_AND_CONQUER_EXCERCISE_10_LINEAR_TIME_SELECTION_H_
