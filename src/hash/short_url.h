/*!
 * @file short_url.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_HASH_SHORT_URL_H_
#define SRC_HASH_SHORT_URL_H_

#include <string>
#include <unordered_map>

namespace algorithm {
class ShortUrlMap {
 public:
    ShortUrlMap() = default;
    void Emplace(const std::string& short_url, const std::string& long_url) {
        m_map.emplace(short_url, long_url);
    }
    std::string& operator[](const std::string& short_url) {
        return m_map[short_url];
    }

 private:
    std::unordered_map<std::string, std::string> m_map{};
};
}  // namespace algorithm

#endif  // SRC_HASH_SHORT_URL_H_
