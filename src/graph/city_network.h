/*!
 * @file city_network.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_GRAPH_CITY_NETWORK_H_
#define SRC_GRAPH_CITY_NETWORK_H_

#include <array>
#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>

namespace algorithm {
enum class City : std::size_t {
    London = 0,
    Moscow,
    Seoul,
    Dubai,
    Sydney,
    Seattle,
    Size,
};

constexpr size_t kCitySize = static_cast<size_t>(City::Size);

class CityNetwork {
 public:
    CityNetwork() = default;

    void Add(City c1, City c2, uint64_t cost);
    uint64_t MinimumTravel(City from, City to) const;

 private:
    uint64_t MinimumTravelImpl(std::size_t from, std::size_t to,
                               std::array<bool, kCitySize>& visit) const;

    std::array<std::array<uint64_t, kCitySize>, kCitySize> m_Graph{};
};
}  // namespace algorithm

std::ostream& operator<<(std::ostream& os, const algorithm::City& c);
#endif  // SRC_GRAPH_CITY_NETWORK_H_
