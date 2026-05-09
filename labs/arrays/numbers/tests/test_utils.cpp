#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME7: adjust the path as needed
#include "../includes/utils.h"

TEST_CASE("Test Max & Min Functionality")
{
    SUBCASE("Sub Case 1: Distinct values")
    {
        int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
        int max, min;
        find_max_min(nums, 9, max, min);
        CHECK(max == 9);
        CHECK(min == 1);
    }
    SUBCASE("Sub Case 2: All same values")
    {
        int nums[] = {7, 7, 7, 7, -7};
        int max, min;
        find_max_min(nums, 5, max, min);
        CHECK(max == 7);
        CHECK(min == -7);
    }
    // FIXME8: Write test cases for find_max_min function with at least 2 subcases
}

TEST_CASE("Test Bubble Sort Functionality")
{
    SUBCASE("Sub Case 1: Unsorted array")
    {
        int nums[] = {64, 34, 25, 12, 22, 11, 90};
        bubble_sort(nums, 7);
        int expected[] = {11, 12, 22, 25, 34, 64, 90};
        for (int i = 0; i < 7; i++)
        {
            CHECK(nums[i] == expected[i]);
        }
    }
    SUBCASE("Sub Case 2: Already sorted array")
    {
        int nums[] = {1, 2, 3, 4, 5};
        bubble_sort(nums, 5);
        int expected[] = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++)
        {
            CHECK(nums[i] == expected[i]);
        }
    }
    // FIXME9: Write the test case for bubble_sort function with at least 2 subcases
}

TEST_CASE("Find Sum Functionality")
{
    SUBCASE("Sub Case 1: Positive numbers")
    {
        int nums[] = {1, 2, 3, 4, 5};
        long long sum = find_sum(nums, 5);
        CHECK(sum == 15);
    }
    SUBCASE("Sub Case 2: Negative and positive numbers")
    {
        int nums[] = {-1, -2, 3, 4, -5};
        long long sum = find_sum(nums, 5);
        CHECK(sum == -1);
    }
    // FIXME10: Write the test case for find_sum function with at least 2 subcases
}
