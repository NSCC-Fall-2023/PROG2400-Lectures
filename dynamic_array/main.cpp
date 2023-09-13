#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& output, const std::vector<int>& v) {
    for (auto& n:v) {
        output << n << ' ';
    }
    return output;
}

void operator<<(std::vector<int>& v, const std::vector<int>& in_vec) {
    for (auto& n: in_vec) {
        v.push_back(n);
    }
}

int main() {

    std::vector<int> v = {1, 2, 3, 4, 5};

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "--" << std::endl;

    v.push_back(6);

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "--" << std::endl;

    v << std::vector({7, 8, 9, 10, 11});

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "--" << std::endl;

    v.shrink_to_fit();

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "--" << std::endl;

    v.reserve(25);

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "--" << std::endl;

    // instant access
    std::cout << "Element 10: " << v.at(10) << std::endl;

    return 0;
}