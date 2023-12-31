/*!
 * @file timer.h
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef TEST_UTIL_TIMER_H_
#define TEST_UTIL_TIMER_H_

#include <chrono>
#include <iostream>

namespace test_util {

class Timer {
 public:
    Timer() : start(std::chrono::steady_clock::now()) {}
    ~Timer() {
        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        std::cout << "Elapsed Time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         end - start)
                         .count()
                  << "\n";
    }

 private:
    std::chrono::steady_clock::time_point start;
};
}  // namespace test_util

#endif  // TEST_UTIL_TIMER_H_
