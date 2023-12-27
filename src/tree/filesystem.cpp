/*!
 * @file filesystem.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "tree/filesystem.h"

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <unordered_set>
#include <utility>

#include "tree/filesystem.h"

namespace algorithm {

FileSystem::FileSystem() : m_Root(std::make_shared<Node>()) {}

void FileSystem::Add(const std::string& path) {
    auto current = m_Root;
    auto path_list = std::deque<std::string>{};

    size_t pos = path.find('/');
    size_t prev_pos = 0;
    while (pos != std::string::npos) {
        path_list.push_back(path.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
        pos = path.find('/', pos + 1);
    }

    path_list.push_back(path.substr(prev_pos, path.size()));

    for (const auto& name : path_list) {
        auto found = std::find_if(
            current->children.begin(), current->children.end(),
            [&name](const auto& node) { return node->name == name; });

        if (found == current->children.end()) {
            auto node = std::make_shared<Node>();
            node->name = name;
            node->is_directory = true;
            node->parent = current;
            current->children.insert(node);
            current = node;
        } else {
            current = *found;
        }
    }
}

std::unordered_set<std::string> FileSystem::Find(const std::string& name) {
    std::unordered_set<std::string> path_list;

    std::deque<NodePtr> stack{m_Root};

    while (!stack.empty()) {
        auto current = stack.front();
        stack.pop_front();

        if (current->name == name) {
            path_list.emplace(FullPath(current));
        }

        for (const auto& next : current->children) {
            stack.emplace_back(next);
        }
    }

    return path_list;
}

std::string FileSystem::FullPath(NodePtr last) {
    std::deque<std::string> path_link{};

    auto current = last;
    while (current != nullptr) {
        path_link.emplace_front(current->name);
        current = current->parent;
    }

    std::string fullpath{};

    std::for_each(path_link.begin(), path_link.end(),
                  [&fullpath](const std::string& name) {
                      if (!fullpath.empty()) {
                          fullpath.append("/");
                      }
                      fullpath.append(name);
                  });

    return fullpath;
}

}  // namespace algorithm
