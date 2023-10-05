#include <iostream>

struct Node {
    int m_data {-1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};

public:
    void push(int data) {
        auto node = new Node();
        node->m_data = data;
        node->m_next = m_top;
        m_top = node;
    }

    void pop() {
        auto node = m_top;
        m_top = m_top ? m_top->m_next : nullptr;
        delete node;
    }

    int peek() {
        return m_top ? m_top->m_data : -1;
    }

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack) {
    auto node = stack.m_top;
    while (node != nullptr) {
        std::cout << node->m_data << ", ";
        node = node->m_next;
    }

    return output;
}

int main() {

    Stack stack;

    // test 1 - add some nodes to the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "Test 1 - adding nodes to stack" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << stack << std::endl;

    // test 2 - remove a node from the stack
    stack.pop();

    std::cout << "Test 2 - remove node from stack" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << stack << std::endl;

    // test 3 - get data from top of stack
    std::cout << "Test 3 - get data from stack" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << stack.peek() << std::endl;

    // test 4 - remove all nodes from stack
    std::cout << "Test 4 - remove all data from stack" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    while (stack.peek() != -1) {
        std::cout << stack << std::endl;
        stack.pop();
    }

    return 0;
}