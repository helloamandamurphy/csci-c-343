cmake_minimum_required(VERSION 4.3)
project(assignment_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(assignment_4 main.cpp
        src/Sequence.cpp
        src/Sequence.h
        src/Node.h)
