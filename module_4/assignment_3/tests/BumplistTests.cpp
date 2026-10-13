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
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c);
    list.advance();
    list.clear();
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
}

// TransferFrom
TEST_CASE("TRANSFER FROM: Gets source's left and right and clears source") {
    BumpList<int> source, self;
    int a = 3, b = 2, c = 1;
    source.addRightFront(a);
    source.addRightFront(b);
    source.addRightFront(c);
    source.advance();

    self.transferFrom(source);

    REQUIRE(self.leftLength() == 1);
    REQUIRE(self.rightLength() == 2);
    REQUIRE(self.rightFront() == 2);
    REQUIRE(source.leftLength() == 0);
    REQUIRE(source.rightLength() == 0);
}

TEST_CASE("TRANSFER FROM: Empty source empties itself") {
    BumpList<int> source, self;
    int a = 5;
    self.addRightFront(a);
    self.transferFrom(source);

    REQUIRE(self.leftLength() == 0);
    REQUIRE(self.rightLength() == 0);
    REQUIRE(source.leftLength() == 0);
    REQUIRE(source.rightLength() == 0);
}

TEST_CASE("TRANSFER FROM: Source can be used after transfer") {
    BumpList<int> source, self;
    int a = 3, b = 2, c = 1;
    source.addRightFront(a);
    source.addRightFront(b);
    source.addRightFront(c);
    source.advance();

    self.transferFrom(source);

    source.addRightFront(a);

    REQUIRE(source.rightLength() == 1);
    REQUIRE(source.leftLength() == 0);
    REQUIRE(source.rightFront() == 3);
}

TEST_CASE("TRANSFER FROM: Self's previous contents are replaced") {
    BumpList<int> source, self;
    int a = 3, b = 2, c = 1;
    int d = 6, e = 5, f = 4;

    self.addRightFront(a);
    self.addRightFront(b);
    self.addRightFront(c);

    source.addRightFront(d);
    source.addRightFront(e);
    source.addRightFront(f);

    self.transferFrom(source);

    REQUIRE(self.rightFront() == 4);
    self.advance();
    REQUIRE(self.rightFront() == 5);
    self.advance();
    REQUIRE(self.rightFront() == 6);

}

// Advance
TEST_CASE("ADVANCE: Fails when right is <>") {
    BumpList<int> list;
    REQUIRE_THROWS_AS(list.advance(), std::out_of_range);
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
}

TEST_CASE("ADVANCE: Correctly moves one element from left to right") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c); // <>, <1,2,3>
    list.advance(); // <1>, <2,3>

    REQUIRE(list.leftLength() == 1);
    REQUIRE(list.rightLength() == 2);
    REQUIRE(list.rightFront() == 2); // 2 should be the starting element of right after advance
}

TEST_CASE("ADVANCE: Total size remains the same") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c); // <>, <1,2,3>
    int originalTotal = list.leftLength() + list.rightLength();
    list.advance(); // <1>, <2,3>

    int endingTotal = list.leftLength() + list.rightLength();
    REQUIRE(originalTotal == endingTotal);
}
// Operator=
// TODO

// MoveToStart
// TODO

// MoveToFinish
// TODO

// AddRightFront
TEST_CASE("ADD RIGHT FRONT: adds a new element to the list") {
    BumpList<int> list;
    int a = 3;
    list.addRightFront(a);
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 1);
    REQUIRE(list.rightFront() == 3);
}

TEST_CASE("ADD RIGHT FRONT: new element goes in the front of existing elements") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    REQUIRE(list.rightFront() == 3);
    list.addRightFront(b);
    REQUIRE(list.rightFront() == 2);
    list.addRightFront(c);
    REQUIRE(list.rightFront() == 1);
}

TEST_CASE("ADD RIGHT FRONT: doesn't change left") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.advance();
    list.addRightFront(c);
    REQUIRE(list.leftLength() == 1);
    REQUIRE(list.rightLength() == 2);
    REQUIRE(list.rightFront() == 1);
}

// RemoveRightFront
TEST_CASE("REMOVE RIGHT FRONT: Fails when right is <>") {
    BumpList<int> list;
    int x = 23;
    REQUIRE_THROWS_AS(list.removeRightFront(x), std::out_of_range);
    REQUIRE(x == 23); // still here after failure
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
}

TEST_CASE("REMOVE RIGHT FRONT: Removes front element from right and returns it") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c); // <>, <1,2,3>
    int x = 0;
    list.removeRightFront(x); // <>, <2,3>
    REQUIRE(x == 1);
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 2);
    REQUIRE(list.rightFront() == 2);
}

TEST_CASE("REMOVE RIGHT FRONT: Removing only element leaves right empty") {
    BumpList<int> list;
    int a = 3;
    int x = 0;

    list.addRightFront(a);
    REQUIRE(list.rightLength() == 1);
    list.removeRightFront(x);
    REQUIRE(x == 3);
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
    REQUIRE(list.rightFront() == std::nullopt);
}

TEST_CASE("REMOVE RIGHT FRONT: Overwrites value of x with removed value") {
    BumpList<int> list;
    int a = 3;
    int x = 0;

    list.addRightFront(a);
    list.removeRightFront(x);
    REQUIRE(x == 3);
}

// ReplaceRightFront
TEST_CASE("REPLACE RIGHT FRONT: Fails when right is <>") {
    BumpList<int> list;
    int x = 23;
    REQUIRE_THROWS_AS(list.replaceRightFront(x), std::out_of_range);
    REQUIRE(x == 23);
    REQUIRE(list.leftLength() == 0);
    REQUIRE(list.rightLength() == 0);
}

TEST_CASE("REPLACE RIGHT FRONT: New value becomes front and x gets the old front value") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c); // <>, <1,2,3>
    int x = 23;
    list.replaceRightFront(x);
    REQUIRE(list.rightFront() == 23);
    REQUIRE(x == 1);
}

TEST_CASE("REPLACE RIGHT FRONT: Works when rightLength == 1") {
    BumpList<int> list;
    int a = 3;
    int x = 23;
    list.addRightFront(a);
    list.replaceRightFront(x);
    REQUIRE(list.rightFront() == 23);
    REQUIRE(x == 3);
}

TEST_CASE("REPLACE RIGHT FRONT: Left is unchanged") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c); // <>, <1,2,3>
    list.advance(); // <1>, <2,3>
    int x = 23;
    list.replaceRightFront(x); // <1>, <23,3>
    REQUIRE(list.rightFront() == 23);
    REQUIRE(x == 2);
    REQUIRE(list.leftLength() == 1);
    REQUIRE(list.rightLength() == 2);
}

// SwapRights
TEST_CASE("SWAP RIGHTS: Rights trade places, lefts stay") {
    BumpList<int> one;
    BumpList<int> two;
    int a = 3, b = 2, c = 1;
    int d = 6, e = 5, f = 4;

    one.addRightFront(a);
    one.addRightFront(b);
    one.addRightFront(c);
    one.advance(); // <1>, <2,3>

    two.addRightFront(d);
    two.addRightFront(e);
    two.addRightFront(f); // <>, <4,5,6>

    one.swapRights(two);

    REQUIRE(one.leftLength() == 1);
    REQUIRE(one.rightLength() == 3);
    REQUIRE(one.rightFront() == 4);

    REQUIRE(two.leftLength() == 0);
    REQUIRE(two.rightLength() == 2);
    REQUIRE(two.rightFront() == 2);
}

TEST_CASE("RIGHT SWAPS: Order is preserved") {
    BumpList<int> one;
    BumpList<int> two;
    int a = 3, b = 2, c = 1;
    int d = 6, e = 5, f = 4;

    one.addRightFront(a);
    one.addRightFront(b);
    one.addRightFront(c);
    one.advance(); // <1>, <2,3>

    two.addRightFront(d);
    two.addRightFront(e);
    two.addRightFront(f); // <>, <4,5,6>

    one.swapRights(two);

    REQUIRE(one.leftLength() == 1);
    REQUIRE(one.rightLength() == 3);
    REQUIRE(one.rightFront() == 4);
    one.advance();
    REQUIRE(one.rightFront() == 5);
    one.advance();
    REQUIRE(one.rightFront() == 6);


    REQUIRE(two.leftLength() == 0);
    REQUIRE(two.rightLength() == 2);
    REQUIRE(two.rightFront() == 2);
    two.advance();
    REQUIRE(two.rightFront() == 3);
}

TEST_CASE("SWAP RIGHTS: Swapping itself doesn't change anything") {
    BumpList<int> one;
    int a = 3;
    one.addRightFront(a);
    one.swapRights(one);
    REQUIRE(one.rightLength() == 1);
    REQUIRE(one.rightFront() == 3);
}

TEST_CASE("SWAP RIGHTS: Can swap with empty right") {
    BumpList<int> one;
    BumpList<int> two;

    int a = 3;
    one.addRightFront(a);

    one.swapRights(two);
    REQUIRE(one.rightLength() == 0);
    REQUIRE(two.rightLength() == 1);
    REQUIRE(two.rightFront() == 3);
}


// LeftLength
TEST_CASE("LEFT LENGTH: Left initializes at zero") {
    BumpList<int> list;
    REQUIRE(list.leftLength() == 0);
}

TEST_CASE("LEFT LENGTH: Left gets correct count when greater than zero") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c);
    REQUIRE(list.leftLength() == 0); // should be (<>, <1,2,3>)

    list.advance();
    REQUIRE(list.leftLength() == 1);
    list.advance();
    REQUIRE(list.leftLength() == 2);
    list.advance();
    REQUIRE(list.leftLength() == 3);
}

// RightLength
TEST_CASE("RIGHT LENGTH: Right initializes at zero") {
    BumpList<int> list;
    REQUIRE(list.rightLength() == 0);
}

TEST_CASE("RIGHT LENGTH: Right gets correct count when less than zero") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    REQUIRE(list.rightLength() == 0);
    list.addRightFront(a);
    REQUIRE(list.rightLength() == 1);
    list.addRightFront(b);
    REQUIRE(list.rightLength() == 2);
    list.addRightFront(c);
    REQUIRE(list.rightLength() == 3);

    list.advance();
    REQUIRE(list.rightLength() == 2);
}

// RightFront
TEST_CASE("RIGHT FRONT: Returns nullopt if right is <>") {
    BumpList<int> list;
    REQUIRE(list.rightFront() == std::nullopt);
}

TEST_CASE("RIGHT FRONT: Returns first element from the right") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c);
    REQUIRE(list.rightFront() == 1);
}

TEST_CASE("RIGHT FRONT: Doesn't change length or values") {
    BumpList<int> list;
    int a = 3, b = 2, c = 1;
    list.addRightFront(a);
    list.addRightFront(b);
    list.addRightFront(c);
    int originalLeftLength = list.leftLength();
    int originalRightLength = list.rightLength();

    list.rightFront();

    REQUIRE(list.leftLength() == originalLeftLength);
    REQUIRE(list.rightLength() == originalRightLength);
    REQUIRE(list.rightFront() == 1);
}


// Find
// TODO

//OutputBumpList
// TODO 

