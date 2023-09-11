cmake_minimum_required(VERSION 3.26)
project(PROG2400_Lectures)

set(CMAKE_CXX_STANDARD 23)

add_executable(best_practices best_practices/main.cpp
        best_practices/student_information.cpp
        best_practices/student_information.h)
