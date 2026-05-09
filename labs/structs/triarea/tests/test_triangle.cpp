#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../src/triangle.hpp"

TEST_CASE("Test triangle area")
{
    SUBCASE("Test area of triangle no decmial points")
    {
        triangle::Triangle t1{10, 5};
        CHECK(triangle::find_area(t1) == 25.0);

        triangle::Triangle t2;
        t2.height = 3;
        t2.base = 4;
        CHECK(triangle::find_area(t2) == 6.0);

        triangle::Triangle *t3 = new triangle::Triangle;
        t3->height = 7;
        t3->base = 8;
        CHECK(triangle::find_area(*t3) == 28.0);
        delete t3;
    }

    // FIXME - add 3 more test cases
}