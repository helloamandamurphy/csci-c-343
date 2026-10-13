#include "../src/Sequence.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("add and entry") {
    Sequence<int> s;
    int v = 10, v1=20, v2=30;
    s.add(v, 0);
    s.add(v1, s.length());
    s.add(v2, 1);
    REQUIRE(s.length() == 3);
    REQUIRE(s.entry(0).has_value());
    REQUIRE(s.entry(0).value() == 10);
    REQUIRE(s.entry(1).value() == 30);
}

TEST_CASE("outputSequence formats values") {
    Sequence<int> s;
    int a = 1, b = 2, c = 3;
    s.add(a, 0);
    s.add(b, 1);
    s.add(c, 2);

    REQUIRE(s.outputSequence() == "1, 2, 3, ");
}
