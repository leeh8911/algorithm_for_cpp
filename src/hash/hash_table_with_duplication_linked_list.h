/*!
 * @file hash_table_with_duplication_linked_list.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_HASH_HASH_TABLE_WITH_DUPLICATION_LINKED_LIST_H_
#define SRC_HASH_HASH_TABLE_WITH_DUPLICATION_LINKED_LIST_H_

#include <list>
#include <vector>
namespace algorithm {
class HashTableLinkedList {
 public:
    explicit HashTableLinkedList(int64_t hash_key) : m_hash_key(hash_key) {
        m_map.resize(hash_key);
    }

    void Emplace(int64_t value) { m_map[Hash(value)].emplace_back(value); }

    bool Contains(int64_t query) {
        auto list = m_map[Hash(query)];

        if (list.empty()) {
            return false;
        }
        for (const auto& elm : list) {
            if (elm == query) {
                return true;
            }
        }
        return false;
    }

    double LoadFactor() const {
        auto count = 0;
        for (const auto& list : m_map) {
            for (const auto& elm : list) {
                ++count;
            }
        }
        return static_cast<double>(count) / static_cast<double>(m_map.size());
    }

 private:
    int64_t Hash(int64_t value) { return value % m_hash_key; }

    int64_t m_hash_key{};
    std::vector<std::list<int64_t>> m_map{};
};
}  // namespace algorithm

#endif  // SRC_HASH_HASH_TABLE_WITH_DUPLICATION_LINKED_LIST_H_
