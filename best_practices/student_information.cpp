//
// Created by W0111036 on 2023-09-11.
//
#include <iostream>
#include <string>
#include "student_information.h"

using std::cout, std::endl;

StudentInformation::StudentInformation(std::string name, std::string id) :
    m_name(std::move(name)), m_id(std::move(id)) {
}

void StudentInformation::print_info() {
    cout << "Name: " << m_name << ", ID: " << m_id << endl;
}