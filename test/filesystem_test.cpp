/*!
 * @file filesystem_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "tree/filesystem.h"

#include <gtest/gtest.h>

TEST(FileSystemTest, FindFileCase) {
    algorithm::FileSystem fs;

    fs.Add("my/file/path/file_1.txt");
    fs.Add("my/file/path/file_2.txt");
    fs.Add("my/file/path/file_3.txt");
    fs.Add("my/file/path/file_4.txt");
    fs.Add("my/file/other/path/file_1.txt");
    fs.Add("my/file/other/path/file_2.txt");
    fs.Add("my/file/other/path/file_3.txt");
    fs.Add("somewhere/file/path/file_1.txt");
    fs.Add("somewhere/file/path/file_2.txt");

    auto path_list = fs.Find("file_1.txt");

    EXPECT_EQ(3, path_list.size());
    EXPECT_TRUE(path_list.contains("my/file/path/file_1.txt"));
    EXPECT_TRUE(path_list.contains("my/file/other/path/file_1.txt"));
    EXPECT_TRUE(path_list.contains("somewhere/file/path/file_1.txt"));
}
