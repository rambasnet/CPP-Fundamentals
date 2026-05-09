#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/util.hpp"

TEST_CASE("Testing answer function")
{
    SUBCASE("String contains 'ss'")
    {
        CHECK(answer("hiss") == "hiss");
        CHECK(answer("mississippi") == "hiss");
    }
    SUBCASE("String does not contain 'ss'")
    {
        CHECK(answer("hello") == "no hiss");
        CHECK(answer("abcde") == "no hiss");
    }
}

// FIXME6: Add 2 more test cases to cover edge cases