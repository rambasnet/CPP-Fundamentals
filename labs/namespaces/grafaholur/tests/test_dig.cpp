#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/dig.h"

TEST_CASE("Testing calculate_rate_per_worker function")
{
    SUBCASE("Basic case")
    {
        int n_workers = 3;
        int h_hours = 4;
        int x_cubic_meters = 24;
        CHECK(dig::calculate_rate_per_worker(n_workers, h_hours, x_cubic_meters) == doctest::Approx(2.0).epsilon(dig::EPSILON));
    }
    SUBCASE("Single worker")
    {
        int n_workers = 1;
        int h_hours = 3;
        int x_cubic_meters = 8;
        CHECK(dig::calculate_rate_per_worker(n_workers, h_hours, x_cubic_meters) == doctest::Approx(2.6).epsilon(dig::EPSILON));
    }
    // FIXME4: Add 2 more test cases to cover edge cases
}