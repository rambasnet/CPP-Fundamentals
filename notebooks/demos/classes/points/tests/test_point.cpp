#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../doctest/doctest.hpp"
#include "../src/point.hpp"

TEST_CASE("Testing Point class functionality")
{
    Point p1(3.0, 4.0);
    Point p2(1.0, 2.0);

    SUBCASE("Test distance from origin")
    {
        CHECK(p1.distance_from_origin() == doctest::Approx(5.0));
        CHECK(p2.distance_from_origin() == doctest::Approx(sqrt(5.0)));
    }

    SUBCASE("Test point addition")
    {
        Point p3 = p1 + p2;
        CHECK(p3 == Point(4.0, 6.0));
    }

    SUBCASE("Test point equality")
    {
        Point p4(3.0, 4.0);
        CHECK(p1 == p4);
        CHECK_FALSE(p1 == p2);
    }

    SUBCASE("Test output stream operator")
    {
        std::ostringstream os;
        os << p1;
        CHECK(os.str() == "(3, 4)");
    }
}