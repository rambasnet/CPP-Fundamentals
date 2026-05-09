#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/doggopher.hpp"

TEST_CASE("Testing distance function")
{
    SUBCASE("Sub Case 1")
    {
        CHECK(distance(0, 0, 0, 0) == 0);
    }
    SUBCASE("Sub Case 2")
    {
        CHECK(distance(0, 0, 3, 4) == 5);
    }
    // FIXME35: Write 2 more test sub cases for distance function with at least 2 subcases
}