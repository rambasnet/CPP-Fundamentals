#include <cassert>
#include <iostream>
#include "triarea.h"

using namespace std;

// Function implementation
float area_of_triangle(const unsigned height, const unsigned base)
{
    float area = 0;
    // FIXME2: Find the area of traingle using the formular given in algorithm step: 2.a
    // store the area into area variable
    return area;
}

// function to test area function
void test_area_with_assert()
{
    unsigned height, base;
    float answer, expected;
    height = 10;
    base = 5;
    answer = area_of_triangle(height, base);
    expected = 25.0;
    assert(abs(answer - expected) < MAX_ERROR);
    // FIXME3: Write 2nd test case
    // FIXME4: Write 3rd test case
    // FIXME5: Write 4th test case
    cerr << "All test cases passed!\n";
}
