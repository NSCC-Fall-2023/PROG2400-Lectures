#include <iostream>

void print() {
    static int count = 0;
    std::cout << "Hello";
    count++;
    if (count < 510000) {
        print();
    }
}

int main() {
    print();
    return 0;
}