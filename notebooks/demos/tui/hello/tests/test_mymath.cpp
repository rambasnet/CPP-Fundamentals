#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "../include/my_math.h"

TEST_CASE("Testing MyMath::add function")
{
    CHECK(MyMath::add(3.5, 4.2) == doctest::Approx(7.7));
    CHECK(MyMath::add(-1.0, 1.0) == doctest::Approx(0.0));
    CHECK(MyMath::add(0.0, 0.0) == doctest::Approx(0.0));
}
