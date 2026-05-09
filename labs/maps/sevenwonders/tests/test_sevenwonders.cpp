#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h> // FIXME: adjust the path as needed
#include "../src/sevenwonders.h"
#include <string>

using namespace std;

TEST_CASE("Testing count_cards function")
{
    SUBCASE("Basic test")
    {
        string cards = "TTC";
        SevenWonders *wonders = new SevenWonders();
        for (char card : cards)
        {
            wonders->update_card_count(card);
        }
        CHECK(wonders->card_count['T'] == 2);
        CHECK(wonders->card_count['C'] == 1);
        CHECK(wonders->card_count['G'] == 0);
        CHECK(wonders->card_count.size() == 2);  // only T and C should be in the map
        CHECK(wonders->calculate_points() == 5); // 2^2 + 1^2 = 4 + 1 = 5
        delete wonders;
    }
}

TEST_CASE("Testing count_bonus function")
{
    SUBCASE("Basic test with bonus")
    {
        string cards = "CTG";
        SevenWonders wonders = SevenWonders();
        for (char card : cards)
        {
            wonders.update_card_count(card);
        }
        CHECK(wonders.card_count['C'] == 1);
        CHECK(wonders.card_count['T'] == 1);
        CHECK(wonders.card_count['G'] == 1);
        CHECK(wonders.calculate_points() == 3);        // 1^2 + 1^2 + 1^2 = 3
        CHECK(wonders.calculate_bonus() == 7);         // 1 set of three different cards = 7 bonus points
        CHECK(wonders.calculate_total_points() == 10); // total points = 3 + 7 = 10
    }
}
// FIXME: Add 3 more test cases to cover different scenarios, such as no cards, only one type of card, and multiple sets of three different cards.
