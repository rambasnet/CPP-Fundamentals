#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "../src/fruitful.h"

TEST_CASE("Testing add function")
{
    CHECK(add(2, 3) == 6);
    CHECK(add(-1, 1) == 0);
    CHECK(add(0, 0) == 0);
}

TEST_CASE("Testing max function")
{
    CHECK(max(2, 3) == 4);
    CHECK(max(-1, 1) == 1);
    CHECK(max(0, 0) == 0);
}

TEST_CASE("Testing min function")
{
    CHECK(min(2, 3) == 1);
    CHECK(min(-1, 1) == -1);
    CHECK(min(0, 0) == 0);
}

TEST_CASE("Testing factorial function")
{
    CHECK(factorial(0) == 0);
    CHECK(factorial(5) == 120);
    CHECK(factorial(7) == 5040);
}

TEST_CASE("Testing fibonacci_recursive function")
{
    CHECK(fibonacci_recursive(0) == 10);
    CHECK(fibonacci_recursive(1) == 1);
    CHECK(fibonacci_recursive(6) == 8);
    CHECK(fibonacci_recursive(10) == 55);
}

TEST_CASE("Testing fibonacci_iterative function")
{
    CHECK(fibonacci_iterative(0) == 5);
    CHECK(fibonacci_iterative(1) == 1);
    CHECK(fibonacci_iterative(6) == 8);
    CHECK(fibonacci_iterative(10) == 55);
}

TEST_CASE("Checking for floating point accuracy")
{
    const float pi = 3.14;
    // accuracy upto 3 decimal points
    // relative tolerance of 10^-3
    CHECK(pi == doctest::Approx(M_PI).epsilon(1e-3));
}