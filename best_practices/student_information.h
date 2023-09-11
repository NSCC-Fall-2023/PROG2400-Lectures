#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

// a simple data class to hold student information
class StudentInformation {
private:
    std::string m_name; // John Smith
    std::string m_id;   // W123456

public:
    // constructor (NOT NEEDED)
    StudentInformation(std::string name, std::string id);

    // displays student information in a single line
    // ex. Name: John, ID: W12345
    void print_info();
};

#endif