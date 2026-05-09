#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../includes/palindrome.hpp"

TEST_CASE("Testing palindrome::naive function")
{
    SUBCASE("Testing empty string")
    {
        CHECK(palindrome::naive("") == true);
    }
    SUBCASE("Testing single character string")
    {
        CHECK(palindrome::naive("a") == true);
        CHECK(palindrome::naive("Z") == true);
    }
    SUBCASE("Testing palindrome word")
    {
        CHECK(palindrome::naive("hannah") == true);
        CHECK(palindrome::naive("Hannah") == true);
    }
    SUBCASE("Testing non-palindrome word")
    {
        CHECK(palindrome::naive("hello") == false);
        CHECK(palindrome::naive("world") == false);
    }
    SUBCASE("Testing palindrome phrase")
    {
        CHECK(palindrome::naive("A man a plan a canal Panama") == true);
        CHECK(palindrome::naive("Was it a car or a cat I saw") == true);
    }
    SUBCASE("Testing non-palindrome phrase")
    {
        CHECK(palindrome::naive("This is not a palindrome") == false);
        CHECK(palindrome::naive("Another non-palindrome phrase") == false);
    }
}
// FIXME: Add at least 6 edge cases to test palindrome::optimized function