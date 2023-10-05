#include <iostream>

struct Node {
    int m_data {-1};
    Node* m_next {nullptr};
};

class Queue {
private:
    Node* m_first {nullptr};
    Node* m_last {nullptr};

public:
    void push(int data) {
        auto node = new Node();
        node->m_data = data;

        // check for empty queue
        if (m_first == nullptr) {
            // queue is empty
            m_first = node;
        } else {
            // queue has some nodes
            m_last->m_next = node;
        }

        m_last = node;
    }

    int peek() {
        if (m_first != nullptr) {
            return m_first->m_data;
        }
        return -1;
    }

    void pop() {
        if (m_first != nullptr) {
            // disconnect node from queue
            auto node = m_first;

            // check if popping last node
            if (m_first == m_last) {
                // we are removing the last node, so change last pointer
                m_last = nullptr;
            }
            m_first = node->m_next;

            // delete the disconnected node
            delete node;
        }
    }

    bool empty() {
        return m_first == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& output, Queue& queue);
};

std::ostream& operator<<(std::ostream& output, Queue& queue) {
    auto node = queue.m_first;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Queue queue;

    // Test 1 - add nodes to queue
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    std::cout << "Test 1" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << queue << std::endl;

    // Test 2 - read data from start of queue
    std::cout << "Test 2" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << queue.peek() << std::endl;

    // Test 3 - remove the first node from the queue
    std::cout << "Test 3" << std::endl;
    std::cout << "------" << std::endl;
    queue.pop();
    std::cout << queue << std::endl;

    // Test 4 - remove remaining node from the queue
    std::cout << "Test 4" << std::endl;
    std::cout << "------" << std::endl;
    while (!queue.empty()) {
        queue.pop();
        std::cout << queue << std::endl;
    }

    return 0;
}