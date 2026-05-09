#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/util.hpp"

TEST_CASE("Testing erase_animal_sound function")
{
    vector<string> recordings = {"bo", "boo", "meow", "bo", "ba", "wooon", "bo"};
    erase_animal_sound(recordings, "bo");
    vector<string> expected = {"boo", "meow", "ba", "wooon"};
    CHECK(recordings == expected);
    // FIXME5: add 2 more test cases
}

TEST_CASE("Testing fox_says function")
{
    vector<string> recordings = {"bo", "boo", "meow", "bo", "ba", "wooon", "bo"};
    erase_animal_sound(recordings, "bo");
    // after animal sounds are deleted
    string ans = fox_says(recordings);
    cerr << "ans = " << ans << endl;
    CHECK(ans == "boo meow ba wooon");
    // FIXME6: add 2 more test cases
}