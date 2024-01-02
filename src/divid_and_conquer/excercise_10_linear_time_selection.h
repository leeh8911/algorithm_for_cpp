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
#include <iterator>
#include <utility>

#include "divid_and_conquer/sort.h"

namespace algorithm {

template <typename Container, typename Compare>
typename Container::iterator FindMedian(typename Container::iterator begin,
                                        typename Container::iterator end) {
    QuickSort<Container, Compare>(begin, end - 1);

    return begin + std::distance(begin, end) / 2;
}

template <typename Container, typename Compare>
typename Container::iterator PartitionUsingGivePivot(
    typename Container::iterator begin, typename Container::iterator last,
    typename Container::value_type pivot) {
    auto left_iter = begin;
    auto right_iter = last;
    while (true) {
        while (Compare()(*left_iter, pivot) &&
               std::distance(left_iter, right_iter) > 0) {
            ++left_iter;
        }

        while (!Compare()(*right_iter, pivot) &&
               std::distance(left_iter, right_iter) > 0) {
            --right_iter;
        }

        if (left_iter == right_iter) {
            break;
        }

        std::iter_swap(left_iter, right_iter);
    }

    auto pivot_iter = std::find(begin, last + 1, pivot);
    if (pivot_iter != last + 1) {
        if (Compare()(*right_iter, pivot)) {
            std::iter_swap(right_iter, pivot_iter);
        }
    }
    return right_iter;
}

template <typename Container,
          typename Compare = std::less<typename Container::value_type>>
typename Container::iterator LinearTimeSelection(
    typename Container::iterator begin, typename Container::iterator last,
    int64_t nth) {
    using ValueType = typename Container::value_type;

    int64_t size = static_cast<int64_t>(std::distance(begin, last));

    if (nth > size) {
        return begin;
    }

    if (size < 1) {
        return begin;
    }
    // 5의 배수로 안떨어질 경우 올림이 되도록 (e.g. 6 -> (6 + 4)/5 = 2)
    int64_t vi_nums = (size + 4) / 5;

    std::vector<ValueType> medians{};

    int64_t vi_first_index = 0;
    int64_t vi_last_index = 5;

    for (; vi_last_index < size; vi_first_index += 5, vi_last_index += 5) {
        auto vi_begin = begin + vi_first_index;
        auto vi_last = begin + vi_last_index;

        medians.emplace_back(
            *FindMedian<Container, Compare>(vi_begin, vi_last));
    }
    if (vi_first_index < size) {
        auto vi_begin = begin + vi_first_index;
        auto vi_last = begin + vi_first_index + (size % 5);

        medians.emplace_back(
            *FindMedian<Container, Compare>(vi_begin, vi_last));
    }

    auto median_of_medians = medians.begin();
    if (medians.size() > 1) {
        median_of_medians =
            FindMedian<Container, Compare>(medians.begin(), medians.end());
    }

    auto partition_iter = PartitionUsingGivePivot<Container, Compare>(
        begin, last, *median_of_medians);
    auto k = std::distance(begin, partition_iter) + 1;  // Why add +1?

    if (nth == k) {
        return partition_iter;
    } else if (nth < k) {
        return LinearTimeSelection<Container, Compare>(begin,
                                                       partition_iter - 1, nth);
    } else {
        return LinearTimeSelection<Container, Compare>(partition_iter + 1, last,
                                                       nth - k);
    }

    return begin;
}
}  // namespace algorithm
#endif  // SRC_DIVID_AND_CONQUER_EXCERCISE_10_LINEAR_TIME_SELECTION_H_
