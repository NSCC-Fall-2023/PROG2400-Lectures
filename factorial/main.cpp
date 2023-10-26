#include <iostream>

int factorial(int num) {

    int answer = num;
    while (num > 1) {
        num--;
        answer *= num;
    }

    return answer;
}

int factorial_recursive(int num) {
    if (num == 1) return 1;
    return num * factorial_recursive(num - 1);
}

int main() {

    // factorial
    // 5! = 5 * 4 * 3 * 2 * 1 = 120

    std::cout << "5! = " << factorial_recursive(5) << std::endl;

    return 0;
}