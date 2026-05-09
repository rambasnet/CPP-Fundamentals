#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME - update the path to doctest.h as per your lab structure
#include "../src/hailstone.hpp"

TEST_CASE("Testing hailstone::h_sum function")
{
    SUBCASE("Testing with small values of n")
    {
        CHECK(hailstone::h_sum(1) == 1);
        CHECK(hailstone::h_sum(2) == 3);
        CHECK(hailstone::h_sum(3) == 49);
        CHECK(hailstone::h_sum(4) == 7);
    }
}
// FIXME6 - add at least 3 test cases to test the function with larger values of n