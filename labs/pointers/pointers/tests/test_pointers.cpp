#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../includes/utils.h"

TEST_CASE("Testing find_sum function")
{
    SUBCASE("Two positive numbers")
    {
        CHECK(my_space::find_sum(new big_int(10), new big_int(4)) == 14);
    }
    SUBCASE("One negative and one positive number")
    {
        big_int *pos = new big_int(4);
        big_int *neg = new big_int(-5);
        CHECK(my_space::find_sum(neg, pos) == -1);
        delete pos;
        delete neg;
    }
    // FIXME8: Add 2 more test cases to cover edge cases
}
TEST_CASE("Testing find_product function")
{
    SUBCASE("Two positive numbers")
    {
        large_int a = 6;
        large_int b = 7;
        CHECK(my_space::find_product(a, b) == 42);
    }
    SUBCASE("One negative and one positive number")
    {
        large_int *n1 = new large_int(10);
        large_int *n2 = new large_int(-5);
        CHECK(my_space::find_product(*n1, *n2) == -50);
        delete n1;
        delete n2;
    }
    // FIXME9: Add 2 more test cases to cover edge cases
}

// FIXME10: Write test cases (with at least 2 subcases) for find_difference function declared in utils.h
// FIXME11: Write test cases (with at least 2 subcases) for find_larger function declared in utils.h