/*!
 * @file operator.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef TEST_UTIL_OPERATOR_H_
#define TEST_UTIL_OPERATOR_H_

#include <iostream>

#include "util/type_traits.h"

template <
    typename Container,
    std::enable_if_t<test_util::is_container<Container>::value, bool> = true>
std::ostream& operator<<(std::ostream& os, const Container& container) {
    for (const auto& elm : container) {
        os << elm << " ";
    }

    return os;
}

template <
    typename Container,
    std::enable_if_t<test_util::is_container<Container>::value, bool> = true>
bool operator==(const Container& c1, const Container& c2) {
    if (c1.size() != c2.size()) {
        return false;
    }

    auto it1 = c1.begin();
    auto it2 = c2.begin();
    for (; it1 != c1.end(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }

    return true;
}

#endif  // TEST_UTIL_OPERATOR_H_
