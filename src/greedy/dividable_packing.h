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

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace algorithm {
class Object {
 public:
    Object(int64_t id, int64_t weight, double price)
        : m_id{id},
          m_weight{weight},
          m_price{price},
          m_price_per_weight{static_cast<double>(weight) / price} {}

    Object(const Object& other)
        : Object(other.m_id, other.m_weight, other.m_price) {}

    bool operator==(const Object& other) const {
        return (m_id == other.m_id) && (m_weight == other.m_weight) &&
               (m_price == other.m_price);
    }

    bool operator<(const Object& other) const {
        return m_price_per_weight < other.m_price_per_weight;
    }

    bool operator>(const Object& other) const {
        return m_price_per_weight > other.m_price_per_weight;
    }

    int64_t Id() const { return m_id; }
    int64_t Weight() const { return m_weight; }
    double Price() const { return m_price; }

 private:
    int64_t m_id{};
    int64_t m_weight{};
    double m_price{};
    double m_price_per_weight{};
};

std::ostream& operator<<(std::ostream& os, const Object& object) {
    os << "Object[" << object.Id() << "] {weight: " << object.Weight()
       << ", price: " << object.Price() << "}";
    return os;
}

std::vector<Object> DividablePacking(std::vector<Object>& objects,
                                     int64_t capacity) {
    std::sort(objects.begin(), objects.end(), std::less<Object>());

    std::vector<Object> result{};

    for (const auto& obj : objects) {
        if (capacity > obj.Weight()) {
            result.emplace_back(obj);
            capacity -= obj.Weight();
        } else {
            result.emplace_back(obj.Id(), capacity,
                                (obj.Price() * capacity) / obj.Weight());
            break;
        }
    }
    return result;
}
}  // namespace algorithm

#endif  // SRC_GREEDY_DIVIDABLE_PACKING_H_
