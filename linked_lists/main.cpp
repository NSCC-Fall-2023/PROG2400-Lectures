#include <iostream>


class LinkedList {
private:
    struct LinkedListNode {
        int m_data {-1};
        LinkedListNode* m_next {nullptr};
    };

    LinkedListNode* m_start {nullptr};

public:
    void add(int num) {
        // create a new node
        auto node = new LinkedListNode();
        node->m_data = num;

        if (m_start == nullptr) {
            // set initial node
            m_start = node;
        } else {
            // add other nodes
            auto curr = m_start;
            auto prev = (LinkedListNode *) nullptr;

            // find the end of the chain
            while (curr != nullptr) {
                prev = curr;
                curr = curr->m_next;
            }

            prev->m_next = node;
        }
    }

    void remove(int data) {
        auto curr = m_start;
        auto prev = (LinkedListNode *) nullptr;

        // find node to delete
        while (curr != nullptr) {

            // when node is found, exit
            if (curr->m_data == data) {
                break;
            }

            prev = curr;
            curr = curr->m_next;
        }

        // curr node is the node to delete
        // prev node is the node to modify

        // only delete node if it was found
        if (curr != nullptr) {

            // am I deleting the first node?
            if (prev == nullptr) {
                // yes, it is the first node
                m_start = curr->m_next;
            } else {
                // detach node from list
                prev->m_next = curr->m_next;
            }

            // delete the node
            delete curr;
        }
    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list.m_start;

    // output all nodes in the list
    while (node != nullptr) {
        std::cout << node->m_data << " ";
        node = node->m_next;
    }

    return output;
}

int main() {

    // Test 1 - add some nodes
    LinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 1" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << list << std::endl;

    // Test 2 - delete node at the end of the list
    list.remove(5); // delete the node with the value of 5

    std::cout << "Test 2" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << list << std::endl;

    // Test 3 - delete node at the beginning of the list
    list.remove(1); // delete the node with the value of 1

    std::cout << "Test 3" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << list << std::endl;

    // Test 4 - delete node in the middle of the list
    list.remove(3); // delete the node with the value of 3

    std::cout << "Test 4" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}