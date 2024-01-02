/*!
 * @file dividable_packing.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_GREEDY_DIVIDABLE_PACKING_H_
#define SRC_GREEDY_DIVIDABLE_PACKING_H_

#include <vector>

namespace algorithm {
class Object {
 public:
    Object(int64_t id, int64_t weight, int64_t price)
        : m_id{id},
          m_weight{weight},
          m_price{price},
          m_price_per_weight{static_cast<double>(weight) /
                             static_cast<double>(price)} {}
    bool operator==(const Object& other) {
        return (m_id == other.m_id) && (m_weight == other.m_weight) &&
               (m_price == other.m_price);
    }

 private:
    int64_t m_id{};
    int64_t m_weight{};
    int64_t m_price{};
    double m_price_per_weight{};
};

std::vector<Object> DividablePacking(std::vector<Object>& objects) {
    return objects;
}
}  // namespace algorithm

#endif  // SRC_GREEDY_DIVIDABLE_PACKING_H_
