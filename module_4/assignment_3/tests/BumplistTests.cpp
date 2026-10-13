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

// TransferFrom

// Advance
// TODO: Need to come back to this one
TEST_CASE("ADVANCE: Fails when right is <>") {
    auto *list = new BumpList<int>();
    REQUIRE_THROWS_AS(list->advance(), std::out_of_range);
    REQUIRE(list->leftLength() == 0);
    REQUIRE(list->rightLength() == 0);
}

TEST_CASE("ADVANCE: Correctly moves one element from left to right") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    list->addRightFront(a);
    list->addRightFront(b);
    list->addRightFront(c); // <>, <1,2,3>
    list->advance(); // <1>, <2,3>

    REQUIRE(list->leftLength() == 1);
    REQUIRE(list->rightLength() == 2);
    REQUIRE(list->rightFront() == 2); // 2 should be the starting element of right after advance
}

TEST_CASE("ADVANCE: Total size remains the same") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    list->addRightFront(a);
    list->addRightFront(b);
    list->addRightFront(c); // <>, <1,2,3>
    int originalTotal = list->leftLength() + list->rightLength();
    list->advance(); // <1>, <2,3>

    int endingTotal = list->leftLength() + list->rightLength();
    REQUIRE(originalTotal == endingTotal);
}
// Operator=

// MoveToStart

// MoveToFinish

// AddRightFront

// RemoveRightFront

// ReplaceRightFront

// SwapRights

// LeftLength
TEST_CASE("LEFT LENGTH: Left initializes at zero") {
    auto *list = new BumpList<int>();
    REQUIRE(list->leftLength() == 0);
}

TEST_CASE("LEFT LENGTH: Left gets correct count when greater than zero") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    list->addRightFront(a);
    list->addRightFront(b);
    list->addRightFront(c);
    REQUIRE(list->leftLength() == 0); // should be (<>, <1,2,3>)

    list->advance();
    REQUIRE(list->leftLength() == 1);
    list->advance();
    REQUIRE(list->leftLength() == 2);
    list->advance();
    REQUIRE(list->leftLength() == 3);
}

// RightLength
TEST_CASE("RIGHT LENGTH: Right initializes at zero") {
    auto *list = new BumpList<int>();
    REQUIRE(list->rightLength() == 0);
}

TEST_CASE("RIGHT LENGTH: Right gets correct count when less than zero") {
    auto *list = new BumpList<int>();
    int a = 3, b = 2, c = 1;
    REQUIRE(list->rightLength() == 0);
    list->addRightFront(a);
    REQUIRE(list->rightLength() == 1);
    list->addRightFront(b);
    REQUIRE(list->rightLength() == 2);
    list->addRightFront(c);
    REQUIRE(list->rightLength() == 3);

    list->advance();
    REQUIRE(list->rightLength() == 2);
}

// RightFront

// Find

//OutputBumpList

