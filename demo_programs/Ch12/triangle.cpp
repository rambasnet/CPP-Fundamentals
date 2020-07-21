// working with triangle using vector
// using functions as possible to break the problem
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// use struct to represent Triangle
struct Triangle {
    float side1, side2, side3;
};

// function prototypes
bool validTriangle(float s1, float s2, float s3);
void test_validTriangle();
Triangle getTriangle();
float trianglePerimeter(const Triangle & t);
void test_trianglePerimeter();
float triangleArea(const Triangle & t);
void assertAlmostEqual(float value1, float value2, int precision);
void test_triangleArea();
void computeAreaAndPerimeter(const Triangle & t);
void program();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test" ) {
        // run all test cases
        test_validTriangle();
        test_trianglePerimeter();
        test_triangleArea();
        cerr << "all test cases passed!\n";
    }
    else
        program();
    
    return 0;
}

// function to check if 3 sides form a triangle
bool validTriangle(float s1, float s2, float s3) {
    // sum of every pair must be greater than the third
    return (s1+s2 > s3 && (s2+s3 > s1) && (s1+s3 > s2))? true: false;
}

void test_validTriangle() {
    assert(validTriangle(2, 3, 4) == true);
    assert(validTriangle(1, 2, 3) == false);
    assert(validTriangle(4, 5, 10) == false);
    cerr << "all test cases passed for validTriangle()\n";
}

// function prompts user to enter 3 sides of a triangle
// creates and returns a triangle
Triangle getTriangle() {
    float s1, s2, s3;
    // input validation
    do {
        cout << "Enter three sides of a triangle separated by space: ";
        cin >> s1 >> s2 >> s3;
        // check if three sides form a triangle
        if (!validTriangle(s1, s2, s3))
            cout << "3 sides do not form a traingle.\n"
                << "Sum of any 2 sides must be greater than the third!\n";
        else
            break;
    } while(true);
    return Triangle({s1, s2, s3});
}

float trianglePerimeter(const Triangle & t) {
    return t.side1 + t.side2 + t.side3;
}

// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    assert(trianglePerimeter(Triangle({2, 3, 4})) == 9);
    assert(trianglePerimeter(Triangle({3, 4, 5})) == 12);
    assert(trianglePerimeter(Triangle({2.5, 3.5, 4.5})) == 10.5);
    cerr << "all test cases passed for trianglePerimeter()\n";
}

// function to compute area of a triangle
float triangleArea(const Triangle & t) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(t)/2;
    return sqrt(s*(s-t.side1)*(s-t.side2)*(s-t.side3));
}

// wrapper function to test if two floating numbers are equal upto precision decimal points
void assertAlmostEqual(float value1, float value2, int precision) {
    ostringstream oss;
    // create output string stream with precision for floating-point values
    oss << fixed << setprecision(precision) << value1 << " " << value2;
    // create input string stream from output string stream
    istringstream iss(oss.str());
    float v1, v2;
    // extract the values as float
    iss >> v1 >> v2;
    assert(v1 == v2);
}

// write 3 test cases for triangleArea
void test_triangleArea() {
    assert(triangleArea(Triangle({3, 4, 5})) == 6.0);
    float area = triangleArea({2, 4, 5}); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    assertAlmostEqual(triangleArea({3, 4, 6}), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}

// function to calculate and print the result on triangle
void computeAreaAndPerimeter(const Triangle & t) {
    cout << "Triangle info: \n"
         << "3 sides length: " << t.side1 << " " << t.side2 << " " << t.side3
         << "\narea: " << triangleArea(t) 
         << "\nperimeter: " << trianglePerimeter(t);        
}

// complete program
void program() {
    Triangle t;
    string cont;
    // store all the entered triangles into a vector
    vector<Triangle> triangles;
    do {
        t = getTriangle();
        computeAreaAndPerimeter(t);
        triangles.push_back(t);
        cout << "\nWant to enter another triangle? [yes|y]: ";
        cin >> cont;
        if (cont == "yes" || cont == "y") continue;
        else break;
    } while(true);
    cout << "You entered " << triangles.size() << 
        ((triangles.size() > 1)? " triangles\n" : " triangle\n");
    cout << "Good bye...\n";
}