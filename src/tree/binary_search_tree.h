/*!
 * @file binary_search_tree.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ALGORITHM_FOR_CPP_BINARY_SEARCH_TREE_H
#define ALGORITHM_FOR_CPP_BINARY_SEARCH_TREE_H

#include <iostream>
#include <memory>

namespace algorithm {
template <typename T>
class BinarySearchTree {
 public:
    struct Node;
    using NodePtr = std::shared_ptr<Node>;

    struct Node {
        T value;
        NodePtr left;
        NodePtr right;
        NodePtr parent;
        explicit Node(T value)
            : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
        Node(T value, NodePtr parent)
            : value(value), left(nullptr), right(nullptr), parent(parent) {}
    };

    BinarySearchTree() : m_Root(nullptr) {}

    void Insert(T value) {
        if (m_Root == nullptr) {
            m_Root = std::make_shared<Node>(value);
            return;
        }

        NodePtr node = m_Root;
        NodePtr parent = nullptr;
        while (node != nullptr) {
            if (node->value > value) {
                if (node->left == nullptr) {
                    node->left = std::make_shared<Node>(value, parent);
                    return;
                }
                parent = node;
                node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = std::make_shared<Node>(value, parent);
                    return;
                }
                parent = node;
                node = node->right;
            }
        }
    }
    void Delete(T value) {
        if (m_Root == nullptr) {
            return;
        }

        auto found = Find(value);

        if (found == nullptr) {
            return;
        }

        if ((found->left == nullptr) && (found->right == nullptr)) {
            if (found->parent == nullptr) {
                m_Root = nullptr;
            } else {
                if (found->parent->left == found) {
                    found->parent->left = nullptr;
                } else {
                    found->parent->right = nullptr;
                }
            }
        } else if (found->left == nullptr) {
            if (found->parent == nullptr) {
                m_Root = found->right;
                m_Root->parent = nullptr;
            } else {
                if (found->parent->left == found) {
                    found->parent->left = found->right;
                } else {
                    found->parent->right = found->right;
                }
                found->right->parent = found->parent;
            }
        } else if (found->right == nullptr) {
            if (found->parent == nullptr) {
                m_Root = found->left;
                m_Root->parent = nullptr;
            } else {
                if (found->parent->left == found) {
                    found->parent->left = found->left;
                } else {
                    found->parent->right = found->left;
                }
                found->left->parent = found->parent;
            }
        } else {
            auto successor = FindSuccesssor(found);
            found->value = successor->value;
            if (successor->parent->left == successor) {
                successor->parent->left = successor->right;
            } else {
                successor->parent->right = successor->right;
            }
            if (successor->right != nullptr) {
                successor->right->parent = successor->parent;
            }
        }
    }

    NodePtr Find(T value) {
        if (m_Root == nullptr) {
            return nullptr;
        }

        NodePtr node = m_Root;

        while (node != nullptr) {
            if (node->value == value) {
                return node;
            } else if (node->value > value) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return nullptr;
    }

 private:
    NodePtr FindSuccesssor(NodePtr current) const {
        NodePtr successor = current->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        return successor;
    }

    NodePtr m_Root;
};

}  // namespace algorithm
#endif  // ALGORITHM_FOR_CPP_BINARY_SEARCH_TREE_H
