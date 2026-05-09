#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME if the path is different
#include "../includes/util.hpp"

TEST_CASE("Testing util::find_email function")
{
    SUBCASE("Testing empty string")
    {
        CHECK(util::find_email("") == "");
    }
    SUBCASE("Testing string with no email")
    {
        CHECK(util::find_email("This is a test string with no email") == "");
    }
    SUBCASE("Testing string with one email")
    {
        CHECK(util::find_email("Please contact us at cmu@coloradomesa.edu for more information.") == "cmu@coloradomesa.edu");
    }
}

// FIXME - add at least 3 edge cases to test util::find_social function
// FIXME - add at least 3 edge cases to test util::find_credit_card function