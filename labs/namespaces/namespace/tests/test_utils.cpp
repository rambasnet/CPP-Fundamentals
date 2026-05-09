#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../includes/utils.h"

TEST_CASE("Testing find_larger function")
{
    SUBCASE("First number is larger")
    {
        CHECK(my_functions::find_larger(10, 5) == 10);
    }
    SUBCASE("Second number is larger")
    {
        CHECK(my_functions::find_larger(3, 7) == 7);
    }
    // FIXME6: Add 2 more test cases to cover edge cases
}

TEST_CASE("Testing find_sum function")
{
    SUBCASE("First number larger than second")
    {
        CHECK(my_functions::find_sum(10, 4) == 14);
    }
    SUBCASE("Negative and positive numbers")
    {
        CHECK(my_functions::find_sum(-5, 4) == -1);
    }
    // FIXME7: Add 2 more test cases to cover edge cases
}

TEST_CASE("Testing find_area_of_circle function")
{
    SUBCASE("Radius is positive")
    {
        CHECK(my_functions::find_area_of_circle(3.0) == doctest::Approx(28.274333882308138).epsilon(my_functions::EPSILON));
    }
    SUBCASE("Radius is zero")
    {
        CHECK(my_functions::find_area_of_circle(0.0) == doctest::Approx(0.0));
    }
    // FIXME8: Add 2 more test cases to cover edge cases
}
// FIXME9: Write test cases (with at least 2 subcases) for find_product function declared in utils.h
// FIXME10: Write test cases for find_difference function (with at least 2 subcases) declared in utils.h
