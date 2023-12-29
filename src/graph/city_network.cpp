/*!
 * @file city_network.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "graph/city_network.h"

#include <cstdint>
#include <limits>

namespace algorithm {
void CityNetwork::Add(City c1, City c2, uint64_t cost) {
    std::size_t i = static_cast<std::size_t>(c1);
    std::size_t j = static_cast<std::size_t>(c2);
    m_Graph[i][j] = cost;
    m_Graph[j][i] = cost;
}

uint64_t CityNetwork::MinimumTravel(City from, City to) const {
    std::size_t i = static_cast<std::size_t>(from);
    std::size_t j = static_cast<std::size_t>(to);
    std::array<bool, kCitySize> visit{};
    return MinimumTravelImpl(i, j, visit);
}
uint64_t CityNetwork::MinimumTravelImpl(
    std::size_t from, std::size_t to,
    std::array<bool, kCitySize>& visit) const {
    if (visit[from]) {
        return 0;
    }
    visit[from] = true;

    if (m_Graph[from][to] != 0) {
        return m_Graph[from][to];
    }

    uint64_t min_cost = std::numeric_limits<uint64_t>::max();
    std::size_t min_destination = 0;
    for (std::size_t i = 0; i < kCitySize; ++i) {
        if (i == from) {
            continue;
        }
        if (m_Graph[from][i] != 0) {
            uint64_t cost = MinimumTravelImpl(i, to, visit);
            if (cost < min_cost) {
                min_cost = cost;
                min_destination = i;
            }
            if (cost != 0) {
                return m_Graph[from][i] + cost;
            }
        }
    }
    return 0;
}
}  // namespace algorithm

std::ostream& operator<<(std::ostream& os, const algorithm::City& c) {
    switch (c) {
        case (algorithm::City::London):
            os << "London";
            break;
        case (algorithm::City::Moscow):
            os << "Moscow";
            break;
        case (algorithm::City::Seoul):
            os << "Seoul";
            break;
        case (algorithm::City::Dubai):
            os << "Dubai";
            break;
        case (algorithm::City::Sydney):
            os << "Sydney";
            break;
        case (algorithm::City::Seattle):
            os << "Seattle";
            break;
        default:
            os << "Not Found City";
    }
    return os;
}