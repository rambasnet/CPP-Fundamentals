#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../src/guests.hpp"

TEST_CASE("Testing Guests class")
{
    SUBCASE("Adding and checking guests")
    {
        Guests *guests = new Guests();
        guests->add_guest("Alice");
        guests->add_guest("Bob");

        CHECK(guests->is_guest_present("Alice") == true);
        CHECK(guests->is_guest_present("Bob") == true);
        CHECK(guests->is_guest_present("Charlie") == false);
        delete guests;
    }
}
TEST_CASE("Testing Guests class - Removing guests")
{
    SUBCASE("Removing guests and checking presence")
    {
        Guests guests;
        guests.add_guest("Alice");
        guests.add_guest("Bob");

        guests.remove_guest("Alice");

        CHECK(guests.is_guest_present("Alice") == false);
        CHECK(guests.is_guest_present("Bob") == true);
    }
}

// FXIME : Add at least 3 more test cases to cover edge cases