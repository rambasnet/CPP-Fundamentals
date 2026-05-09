#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/addtwo.h"

TEST_CASE("Testing add_two_numbers function")
{
    SUBCASE("Basic additions of smalle positive numbers")
    {
        CHECK(add_two_numbers(2, 3) == 5);
    }
    SUBCASE("Adding small negative and positive numbers")
    {
        CHECK(add_two_numbers(-1, 1) == 0);
    }
    // FIXME5: Add 3 more test cases to cover edge cases
}