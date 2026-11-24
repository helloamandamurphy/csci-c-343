cmake_minimum_required(VERSION 4.3)
project(assignment_5)

set(CMAKE_CXX_STANDARD 23)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_poem.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/oliver.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/random_dictionary.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(assignment_5 main.cpp
        src/AvlNode.h
        src/WordParser.cpp
        src/WordParser.h
        src/AVLTree.h)

add_executable(test_avl_tree test/test_avl_tree.cpp src/AVLTree.h src/AvlNode.h)
