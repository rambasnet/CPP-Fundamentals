#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <ncurses.h>
#include "../include/my_math.hpp"
// testing TUI is challenging and not reliable in automated tests, so we will focus on testing the MyMath functions instead.

TEST_CASE("Testing MyMath::add function")
{
    CHECK(MyMath::add(2, 3) == 5);
    CHECK(MyMath::add(-1, 1) == 0);
    CHECK(MyMath::add(0, 0) == 0);
}