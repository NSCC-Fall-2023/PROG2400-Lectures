cmake_minimum_required(VERSION 3.22)
project(PROG2400_Lectures)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-static")

add_executable(best_practices best_practices/main.cpp
        best_practices/student_information.cpp
        best_practices/student_information.h)
add_executable(command_line command_line/main.cpp)
add_executable(stringstream stringstream/main.cpp)
add_executable(dynamic_array dynamic_array/main.cpp)
add_executable(linked_lists linked_lists/main.cpp)
add_executable(queue queue/main.cpp)
add_executable(stack stack/main.cpp)
add_executable(palindrome palindrome/main.cpp)
add_executable(recursion recursion/main.cpp)
add_executable(factorial factorial/main.cpp)
add_executable(filesystem filesystem/main.cpp)