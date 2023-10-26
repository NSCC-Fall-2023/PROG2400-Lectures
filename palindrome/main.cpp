#include <iostream>
#include <cstring>

bool is_palindrome(const char* input, size_t len) {
    for (int i = 0; i < len / 2; ++i) {
        if (input[i] != input[len-i-1]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome_recursive(const char* input, size_t len) {
    // end condition
    if (len <= 1) return true;
    // compare first and last letters
    if (input[0] == input[len-1]) {
        // could be a palindrome
        // check the next set of characters
        return is_palindrome_recursive(&input[1], len-2);
    }
    return false;
}

// Steven Crosby
bool is_palindrome_recursive(const std::string &input_string, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (input_string[start] != input_string[end]) {
        return false;
    }
    return is_palindrome_recursive(input_string, start + 1, end - 1);
}

int main() {
    constexpr int BUFFER_SIZE = 80;
    char buffer[BUFFER_SIZE];

    std::cout << "Enter a word: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " IS NOT a palindrome." << std::endl;
    }

    if (is_palindrome_recursive(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " IS NOT a palindrome." << std::endl;
    }
    return 0;
}