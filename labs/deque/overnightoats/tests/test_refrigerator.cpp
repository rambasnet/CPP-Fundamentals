#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../src/refrigerator.hpp"

TEST_CASE("Test Case 1: No oats expire")
{
    Referigerator fridge;
    fridge.shelf_life = 2; // Set shelf life to 2 days
    fridge.add(0);         // Day 0: Add oats
    fridge.add(1);         // Day 1: Add oats
    CHECK(fridge.eat(1));  // Day 1: Eat oats (should succeed)
    CHECK(fridge.eat(2));  // Day 2: Eat oats (should succeed)
}

// FIXME - Add 2 more test cases to cover different scenarios, such as:
// - Eating oats that are exactly at the shelf life limit
// - Adding multiple cups of oats and eating them in order
// - Trying to eat oats when the fridge is empty

TEST_CASE("Test Case 2: Oats expire")
{
    Referigerator fridge;
    fridge.shelf_life = 1;         // Set shelf life to 1 day
    fridge.add(0);                 // Day 0: Add oats
    CHECK(fridge.eat(2) == false); // Day 2: Try to eat oats (should fail, expired)
}

// FIXME - Add 2 more test cases to cover edge cases for expired oats