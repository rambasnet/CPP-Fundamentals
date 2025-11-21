#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME4: adjust the path as needed
#include "../src/util.h"

TEST_CASE("1 - Testing convert_miles_to_feet function")
{
    SUBCASE("Sub Case 1")
    {
        int miles = 1;
        int expected = 5280;
        int result = convert_miles_to_feet(miles);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 2")
    {
        int miles = 5;
        int expected = 26400;
        int result = convert_miles_to_feet(miles);
        CHECK(result == expected);
    }
}
// FIXME5: Write test cases for convert_miles_to_feet function with atleate 2 subcases

TEST_CASE("1 - Testing calculate_answer function")
{
    SUBCASE("Sub Case 1")
    {
        int total_feet = 5280;
        int numb_students = 1;
        int expected = 5280;
        int result = calculate_answer(total_feet, numb_students);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 2")
    {
        int total_feet = 26400;
        int numb_students = 5;
        int expected = 5280;
        int result = calculate_answer(total_feet, numb_students);
        CHECK(result == expected);
    }
}
// FIXME6: Write the test case for calculate_answer function with atleate 2 subcases