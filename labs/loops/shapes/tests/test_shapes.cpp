#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/shapes.h"

TEST_CASE("Testing get_triangle function")
{
    SUBCASE("Height 3")
    {
        std::stringstream triangle_3 = get_triangle(3);
        std::string expected_3 = "* \n* * \n* * * \n";
        CHECK(triangle_3.str() == expected_3);
    }

    SUBCASE("Height 5")
    {
        std::stringstream triangle_5 = get_triangle(5);
        std::string expected_5 = "* \n* * \n* * * \n* * * * \n* * * * * \n";
        CHECK(triangle_5.str() == expected_5);
    }
}