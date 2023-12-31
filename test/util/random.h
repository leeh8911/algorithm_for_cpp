/*!
 * @file random.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <random>
#include <type_traits>

namespace test_util {
class Random {
 public:
    template <typename T,
              std::enable_if_t<std::is_integral<T>::value, bool> = true>
    static T Generate(T min, T max) {
        return std::uniform_int_distribution<T>(min, max)(m_generator);
    }
    template <typename T,
              std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
    static T Generate(T min, T max) {
        return std::uniform_real_distribution<T>(min, max)(m_generator);
    }

    template <typename Container,
              std::enable_if_t<
                  std::is_integral<typename Container::value_type>::value,
                  bool> = true>
    static Container Generate(typename Container::value_type min,
                              typename Container::value_type max, size_t size) {
        Container container(size);
        for (auto& elm : container) {
            elm = Generate<typename Container::value_type>(min, max);
        }

        return container;
    }

 private:
    static std::random_device m_rd;
    static std::mt19937 m_generator;
};

}  // namespace test_util