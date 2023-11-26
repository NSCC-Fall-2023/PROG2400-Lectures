#include <iomanip>
#include <span>
#include "binary_search_tree.h"

BST::~BST() {
    delete_tree(m_root);
}

void BST::insert(int num) {
    insert(num, m_root);
}

void BST::insert(int num, Node *&node) {
    if (node == nullptr) {
        // hit the bottom of the tree
        // end of the recursion
        node = new Node();
        node->m_data = num;
    } else if (num < node->m_data) {
        // traverse to the left of the tree
        insert(num, node->m_left);
    } else if (num > node->m_data) {
        // traverse to the right of the tree
        insert(num, node->m_right);
    } else {
        // inserting duplicate value
        //std::cout << "Node value " << node->m_data << " already exists." << std::endl;
    }
}

void BST::remove(int num) {

    Node *node = m_root;
    Node *parent = nullptr;

    // look for node to delete
    while (node != nullptr) {
        if (num < node->m_data) {
            parent = node;
            node = node->m_left;
        } else if (num > node->m_data) {
            parent = node;
            node = node->m_right;
        } else {
            // found the node we are looking for
            break;
        }
    }

    // didn't find the node, so just exit
    if (node == nullptr) return;

    // if the node has two children,
    // use the right-most node in the left subtree
    // as the successor
    if (node->m_left != nullptr && node->m_right != nullptr) {
        // we have two children

        // start on the left subtree
        auto successor = node->m_left;

        // go as far right as possible
        parent = node;
        while (successor->m_right != nullptr) {
            parent = successor;
            successor = successor->m_right;
        }

        // swap data between successor and node to delete
        node->m_data = successor->m_data;
        node = successor;
    }

    // assume there is a left child
    Node *subtree = node->m_left;

    // if there is no left child, assume a right child
    if (subtree == nullptr) {
        subtree = node->m_right;
    }

    // determine if node is left child or right child
    if (parent == nullptr) {
        // must be the root node
        m_root = subtree;
    } else if (parent->m_left == node) {
        // must be parent's left child
        parent->m_left = subtree;
    } else if (parent->m_right == node) {
        // must be parent's right child
        parent->m_right = subtree;
    }

    // finally delete the node
    delete node;
}

void BST::delete_tree(Node *node) {
    if (node == nullptr) return;

    delete_tree(node->m_left);
    delete_tree(node->m_right);
    delete node;
    node = nullptr;
}

void BST::print_tree(std::ostream &output, Node *&node, int indent) {
    if (node != nullptr) {
        print_tree(output, node->m_right, indent + 8);
        output << std::setw(indent) << node->m_data << std::endl;
        print_tree(output, node->m_left, indent + 8);
    }
}

void BST::save_array(std::span<int> nums) {
    save_array(nums, m_root);
}

void BST::save_array(std::span<int> nums, Node*& node) {
    static int i = 0;

    if (node != nullptr) {
        save_array(nums, node->m_left);
        nums[i++] = node->m_data;
        save_array(nums, node->m_right);
    }
}

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}