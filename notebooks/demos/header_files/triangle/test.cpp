#include <cassert>
#include <iostream>

// include user-defined headers
#include "triangle.h"
#include "test.h"
#include "utility.h"

using namespace std;

void test_validTriangle() {
    assert(validTriangle(2, 3, 4) == true);
    assert(validTriangle(1, 2, 3) == false);
    assert(validTriangle(4, 5, 10) == false);
    cerr << "all test cases passed for validTriangle()\n";
}

// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    assert(trianglePerimeter(Triangle({0, 2.0f, 3.0f, 4.0f})) == 9.0f);
    assert(trianglePerimeter(Triangle({0, 3.0f, 4.0f, 5.0f})) == 12.0f);
    assert(trianglePerimeter(Triangle({0, 2.5f, 3.5f, 4.5f})) == 10.5f);
    cerr << "all test cases passed for trianglePerimeter()\n";
}

// write 3 test cases for triangleArea
void test_triangleArea() {
    assert(triangleArea(Triangle({0, 3, 4, 5})) == 6.0);
    float area = triangleArea({0, 2, 4, 5}); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    assertAlmostEqual(triangleArea({0, 3, 4, 6}), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}