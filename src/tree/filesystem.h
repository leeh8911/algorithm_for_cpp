/*!
 * @file filesystem.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ALGORITHM_FOR_CPP_FILESYSTEM_H
#define ALGORITHM_FOR_CPP_FILESYSTEM_H

#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

namespace algorithm {
class FileSystem {
 public:
    struct Node;
    using NodePtr = std::shared_ptr<Node>;

    struct Node {
        std::string name;
        bool is_directory;
        NodePtr parent;
        std::unordered_set<NodePtr> children;
    };

    FileSystem();

    void Add(const std::string& path);
    std::unordered_set<std::string> Find(const std::string& name);

 private:
    std::string FullPath(NodePtr last);

    std::unordered_set<std::string> FindImpl(
        const NodePtr& current, const std::string& name,
        std::unordered_set<std::string>& path_list);

    NodePtr m_Root{};
};
}  // namespace algorithm

#endif  // ALGORITHM_FOR_CPP_FILESYSTEM_H