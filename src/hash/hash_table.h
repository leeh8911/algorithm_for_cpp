/*!
 * @file hash_table.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_HASH_HASH_TABLE_H_
#define SRC_HASH_HASH_TABLE_H_

#include <algorithm>
#include <vector>

namespace algorithm {
class HashTable {
 public:
    explicit HashTable(int64_t hash_key) : m_hash_key(hash_key) {
        m_map.resize(hash_key, -1);
    }

    void Emplace(int64_t value) { m_map[Hash(value)] = value; }

    bool Contains(int64_t query) {
        if (m_map[Hash(query)] == query) {
            return true;
        }
        return false;
    }

    double LoadFactor() const {
        auto empty_count = std::count(m_map.begin(), m_map.end(), -1);
        return static_cast<double>(m_map.size() - empty_count) /
               static_cast<double>(m_map.size());
    }

 private:
    int64_t Hash(int64_t value) { return value % m_hash_key; }

    int64_t m_hash_key{};
    std::vector<int64_t> m_map{};
};
}  // namespace algorithm

#endif  // SRC_HASH_HASH_TABLE_H_
