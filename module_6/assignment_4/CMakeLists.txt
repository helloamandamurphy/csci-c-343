cmake_minimum_required(VERSION 4.3)
project(assignment_4)

set(CMAKE_CXX_STANDARD 23)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_poem.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/oliver.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/random_dictionary.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(assignment_4 main.cpp
        src/Sequence.cpp
        src/Sequence.h
        src/Node.h
        src/WordParser.cpp
        src/WordParser.h)
