#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../includes/num_system.hpp"

TEST_CASE("Testing decToBin function")
{
    SUBCASE("Typical case")
    {
        CHECK(decToBin(10) == "1010");
    }
    SUBCASE("Edge case: zero")
    {
        CHECK(decToBin(0) == "0");
    }
    // FIXME5: Add 2 more test cases to cover edge cases
}

TEST_CASE("Testing binToDec function")
{
    SUBCASE("Typical case")
    {
        CHECK(binToDec("1010") == 10);
    }
    SUBCASE("Edge case: zero")
    {
        CHECK(binToDec("0") == 0);
    }
    // FIXME6: Add 2 more test cases to cover edge cases
}

// FIXME7: Write test cases (with at least 2 subcases) for decToOct function declared in num_system.hpp
// FIXME8: Write test cases (with at least 2 subcases) for octToDec function declared in num_system.hpp