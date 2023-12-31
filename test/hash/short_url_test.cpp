/*!
 * @file short_url_test.cpp
 * @author sangwon (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hash/short_url.h"

#include <gtest/gtest.h>

TEST(ShortUrlTest, SampleCase) {
    algorithm::ShortUrlMap url_map{};

    url_map.Emplace("www.gg.su", "www.google.com");
    url_map.Emplace("www.nv.su", "www.naver.com");
    url_map.Emplace("www.kk.su", "www.kakao.com");

    EXPECT_EQ(url_map["www.gg.su"], "www.google.com");
    EXPECT_EQ(url_map["www.nv.su"], "www.naver.com");
    EXPECT_EQ(url_map["www.kk.su"], "www.kakao.com");
}