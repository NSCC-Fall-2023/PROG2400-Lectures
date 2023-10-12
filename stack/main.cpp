#include <iostream>
#include <utility>
#include <memory>

class Stack;

//class SmartPtr {
//private:
//    Stack *data {nullptr};
//
//    static SmartPtr make_smartptr() {
//        auto ptr = SmartPtr();
//        ptr.data = new Stack();
//    }
//
//    ~SmartPtr() {
//        delete data;
//    }
//};

struct Student {
    std::string m_id   {"W999999"};
    std::string m_name {"No Name"};
};

struct Node {
    Student m_data;
    std::unique_ptr<Node> m_next {nullptr};
};

class Stack {
private:
    std::unique_ptr<Node> m_top {nullptr};

public:
    void push(Student data) {
        //auto node = new Node();
        auto node = std::make_unique<Node>();
        node->m_data = std::move(data);
        node->m_next = std::move(m_top);
        m_top = std::move(node);
    }

    void pop() {
        //auto node = m_top;
        m_top = m_top ? std::move(m_top->m_next) : nullptr;
        //delete node;
    }

    Student peek() {
        if (m_top == nullptr) return {"W000000", "Empty Peek"};
        return m_top->m_data;
    }

    bool empty() {
        return m_top == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, const Student& student) {
    output << "Name: " << student.m_name << ", ";
    output << "ID: " << student.m_id << std::endl;
    return output;
}

std::ostream& operator<<(std::ostream& output, Stack& stack) {
    auto node = stack.m_top.get();
    while (node != nullptr) {
        std::cout << node->m_data;
        node = node->m_next.get();
    }

    return output;
}

int main() {

    Stack stack;

    // test 1 - add some nodes to the stack
    stack.push({"W111222", "John"});
    stack.push({"W222333", "Jane"});
    stack.push({"W333444", "Jill"});
    stack.push({"W444555", "Jack"});
    stack.push({"W555666", "Jeff"});

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
    while (!stack.empty()) {
        std::cout << stack << std::endl;
        stack.pop();
    }

    return 0;
}