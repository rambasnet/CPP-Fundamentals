#include <cassert>
#include "../src/helper.h"
#include <iostream>

using namespace std;

int main()
{
    assert(twilight("Alice") == "Thank you, Alice, and farewell!");
    assert(twilight("Bob") == "Thank you, Bob, and farewell!");
    return 0;
}