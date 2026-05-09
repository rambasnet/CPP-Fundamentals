#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/util.hpp"

TEST_CASE("Testing answer function")
{
    SUBCASE("Normal cases with 'Simon says' prefix")
    {
        CHECK(answer("Simon says learn C++") == " learn C++");
        CHECK(answer("Simon says do labs") == " do labs");
    }
    SUBCASE("Cases without 'Simon says' prefix")
    {
        CHECK(answer("learn C++") == "");
        CHECK(answer("do labs") == "");
    }
}

// FIXME6: Add 2 more test cases to cover other edge cases