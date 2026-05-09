#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/bacon.h"

TEST_CASE("Testing split_string function")
{
    SUBCASE("Basic test")
    {
        string line = "Bacon Eggs Spam";
        vector<string> expected = {"Bacon", "Eggs", "Spam"};
        vector<string> result = split_string(line);
        CHECK(result == expected);
    }

    SUBCASE("Empty string")
    {
        string line = "";
        vector<string> expected = {};
        vector<string> result = split_string(line);
        CHECK(result == expected);
    }
    // FIXME5: Add 2 more test cases to test split_string function
}

TEST_CASE("Testing read_items and print_items functions")
{
    SUBCASE("Basic test")
    {
        // Simulate input
        string input_data = "Alice Bacon Eggs\nBob Spam Bacon\nCharlie Eggs Spam\n";
        istringstream input_stream(input_data);
        cin.rdbuf(input_stream.rdbuf());

        int n = 3; // number of lines to read
        map_str_set items = read_items(n);

        // Expected output map
        map_str_set expected = {
            {"Bacon", {"Alice", "Bob"}},
            {"Eggs", {"Alice", "Charlie"}},
            {"Spam", {"Bob", "Charlie"}}};

        CHECK(items == expected);
    }
    // FIXME6: Add 2 more test cases to test read_items and print_items functions
}