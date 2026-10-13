//
// Created by Amanda Murphy on 10/12/26.
//
#include <catch2/catch_test_macros.hpp> // Unit test framework for C++
#include "../src/Sequence.h"
#include "../src/BumpList.h"

// Constructor
TEST_CASE("CONSTRUCTOR: creates empty BumpList") {
    BumpList<int> list;
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
}

// Deconstructor
TEST_CASE("DECONSTRUCTOR: deletes a BumpList") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    list->addRightFront(a);
    list->addRightFront(b);
    list->addRightFront(c);
    delete list; // will crash if double-frees or segmentation faults occur, but does not test for memory leak
    // implemented sanitizer in CMakeLists.txt file
    SUCCEED();
}

// Clear
TEST_CASE("CLEAR: clears all of the elements in the the data structure") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    list->addRightFront(a);
    list->addRightFront(b);
    list->addRightFront(c);
    list->advance();
    list->clear();
    REQUIRE(list->leftLength() == 0);
    REQUIRE(list->rightLength() == 0);
}
