// Description: A program that creates simple student objects and outputs their information
//
// Author: Brian Shewan (optional)
// Date: Sept. 11, 2023 (optional)

#include <iostream>
#include "student_information.h"

using namespace std;

int main() {

    const std::string FIRST_NAME = "John"; // variable to hold first name (NOT NEEDED)

    // create new student object to demonstrate naming conventions
    StudentInformation student_one(FIRST_NAME, "W123456");
    student_one.print_info();

    return 0;
}