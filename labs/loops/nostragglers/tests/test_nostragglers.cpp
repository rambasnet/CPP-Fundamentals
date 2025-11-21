#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME7: adjust the path as needed
#include "../src/utils.h"

TEST_CASE("1 - Testing total_stragglers function")
{
    SUBCASE("Sub Case 1")
    {
        int students = 5;
        int visitors = 3;
        int faculty = 2;
        int expected = 10;
        int result = total_stragglers(students, visitors, faculty);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 2")
    {
        int students = 0;
        int visitors = 0;
        int faculty = 0;
        int expected = 0;
        int result = total_stragglers(students, visitors, faculty);
        CHECK(result == expected);
    }
}
// FIXME8: Write test cases for total_stragglers function with atleate 2 subcases

TEST_CASE("2 - Testing update_count function")
{
    SUBCASE("Sub Case 1")
    {
        int students = 0;
        int visitors = 0;
        int faculty = 0;
        update_count('S', 'I', 5, students, visitors, faculty);
        CHECK(students == 5);
        CHECK(visitors == 0);
        CHECK(faculty == 0);
    }
    SUBCASE("Sub Case 2")
    {
        int students = 10;
        int visitors = 5;
        int faculty = 3;
        update_count('V', 'O', 2, students, visitors, faculty);
        CHECK(students == 10);
        CHECK(visitors == 3);
        CHECK(faculty == 3);
    }
}
// FIXME9: Write the test case for update_count function with atleate 2 subcases