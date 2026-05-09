#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME7: adjust the path as needed
#include "../src/modulo.h"

TEST_CASE("Testing init_flags function")
{
    SUBCASE("Sub Case 1")
    {
        const size_t len = 5;
        bool flags[len];
        init_flags(flags, len);
        for (size_t i = 0; i < len; i++)
        {
            CHECK(flags[i] == false);
        }
    }
}

TEST_CASE("Testing get_modulo_42 function")
{
    SUBCASE("Sub Case 1")
    {
        unsigned int num = 84;
        unsigned int expected = 0;
        unsigned int result = get_modulo_42(num);
        CHECK(result == expected);
    }
    // FIXME8: Write 2 test sub cases for get_modulo_42 function with at least 2 subcases
}

TEST_CASE("Testing count_flags function")
{
    SUBCASE("Sub Case 1")
    {
        bool flags[5] = {true, false, true, true, false};
        size_t expected = 3;
        size_t result = count_flags(flags, 5);
        CHECK(result == expected);
    }
    // FIXME9: Write 2 test sub cases for count_flags function with at least 2 subcases
}

TEST_CASE("Testing update_flags function")
{
    SUBCASE("Sub Case 1")
    {
        unsigned int numbers[3] = {42, 43, 44};
        bool flags[42];
        init_flags(flags, 42);
        update_flags(numbers, flags, 3);
        CHECK(flags[0] == true); // 42 % 42 == 0 is set
        CHECK(flags[1] == true); // 1 is set
        CHECK(flags[2] == true); // 2 is set
    }
    // FIXME10: Write 2 test sub cases for update_flags function with at least 2 subcases
}