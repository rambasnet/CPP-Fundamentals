#include <cassert>
#include "../src/helper.h"
#include <iostream>

using namespace std;

void test_twilight_1()
{
    string input = "Alice";
    string expected = "Thank you, Alice, and farewell!";
    string result = twilight(input);
    assert(result == expected);
}

void test_twilight_2()
{
    string input = "Bob";
    string expected = "Thank you, Bob, and farewell!";
    string result = twilight(input);
    assert(result == expected);
}

int main()
{
    test_twilight_1();
    test_twilight_2();
    return 0;
}