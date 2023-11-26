#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <iostream>

struct Node {
    int m_data {-1};
    Node* m_left {nullptr};
    Node* m_right {nullptr};
};

class BST {
private:
    Node* m_root {nullptr};
public:
    virtual ~BST();

    void insert(int num);
    void insert(int num, Node*& node);
    void remove(int num);
    void save_array(std::span<int> nums);

private:
    void delete_tree(Node* node);
    void save_array(std::span<int> nums, Node*& node);
    void print_tree(std::ostream& output, Node*& node, int indent);

    friend std::ostream& operator<<(std::ostream& output, BST& bst);
};

#endif