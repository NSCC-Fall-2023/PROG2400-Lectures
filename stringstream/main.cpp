#include <iostream>
#include <sstream>

int main() {

    std::stringstream ss;

    std::string user_input;
    char command, space;
    int start = -1, end = -1;

    std::cout << "Enter a command and two numbers: ";
    std::getline(std::cin, user_input);

    // store user input for later parsing
    ss << user_input;

    // try to parse a command
    ss >> command;
    std::cout << "command: " << command << std::endl;

    // determine is this a possible command? (L, D, E, I)
    bool is_command = true;
    if (is_command) {
        ss >> start;

        if (ss) {
            std::cout << "start: " << start;

            ss >> end;
            std::cout << ", end: " << end << std::endl;
        }
    } else {
        // just some text
        std::cout << "You typed: " << user_input << std::endl;
    }

    return 0;
}