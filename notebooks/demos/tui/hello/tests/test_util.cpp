#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <ncurses.h>

#include "../include/util.hpp"

TEST_CASE("Testing add function")
{
    SUBCASE("Sub Case 1")
    {
        CHECK(Demo::add(3.5f, 4.2f) == doctest::Approx(7.7f));
    }
    SUBCASE("Sub Case 2")
    {
        CHECK(Demo::add(-1.0f, 1.0f) == doctest::Approx(0.0f));
    }
    SUBCASE("Sub Case 3")
    {
        CHECK(Demo::add(0.0f, 0.0f) == doctest::Approx(0.0f));
    }
}

TEST_CASE("print_msg prints text at correct position")
{
    initscr();
    std::string msg = "Hello";
    Demo::print_msg(5, 10, msg);

    char buffer[32];

    // Read string back from screen
    mvinnstr(5, 10, buffer, msg.size());
    CHECK(std::string(buffer) == msg);

    endwin();
}