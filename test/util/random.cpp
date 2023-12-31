/*!
 * @file random.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "util/random.h"

#include <random>

namespace test_util {

std::random_device Random::m_rd{};
std::mt19937 Random::m_generator(Random::m_rd());

}  // namespace test_util