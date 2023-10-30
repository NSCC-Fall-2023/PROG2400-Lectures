#include <iostream>
#include <iomanip>

struct Node {
    int m_data {-1};
    Node* m_left {nullptr};
    Node* m_right {nullptr};
};

class BST {
private:
    Node* m_root {nullptr};
public:
    void insert(int num) {
        insert(num, m_root);
    }

    void insert(int num, Node*& node) {
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
            std::cout << "Node value " << node->m_data << " already exists." << std::endl;
        }
    }

    void remove(int num) {

        Node* node = m_root;
        Node* parent = nullptr;

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

        // assume there is a left child
        Node* subtree = node->m_left;

        // if there is no left child, assume a right child
        if (subtree == nullptr) {
            subtree = node->m_right;
        }

        // determine if node is left child or right child
        if (parent->m_left == node) {
            // must be parent's left child
            parent->m_left = subtree;
        } else if (parent->m_right == node) {
            // must be parent's right child
            parent->m_right = subtree;
        }

        // finally delete the node
        delete node;
    }

private:
    void print_tree(std::ostream& output, Node*& node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->m_right, indent + 8);
            output << std::setw(indent) << node->m_data << std::endl;
            print_tree(output, node->m_left, indent + 8);
        }
    }

    friend std::ostream& operator<<(std::ostream& output, BST& bst);
};

std::ostream& operator<<(std::ostream& output, BST& bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}

int main() {

    BST bst;

    // test 1 - inserting root node

    bst.insert(5);

    std::cout << bst << std::endl;

    // test 2 - inserting other nodes

    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << bst << std::endl;

    // test 3 - remove a node with no children
    std::cout << "\n\nTest 3" << std::endl;
    std::cout << "------" << std::endl;

    bst.remove(2);

    std::cout << bst << std::endl;

    // test 4 - remove a node with one children
    std::cout << "\n\nTest 4" << std::endl;
    std::cout << "------" << std::endl;

    bst.remove(3);

    std::cout << bst << std::endl;

    return 0;
}