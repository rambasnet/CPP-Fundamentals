// working with triangle using vector
// using functions to divide the solution to the problem
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// function prototypes
bool validTriangle(const vector<float> &);
void test_validTriangle();
float trianglePerimeter(const vector<float> &);
void test_trianglePerimeter();
float triangleArea(const vector<float> &);
void assertAlmostEqual(float value1, float value2, int precision);
void test_triangleArea();
void getTriangle(vector<float> &);
void printTriangleInfo(const vector<float> & triangle);

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

// complete program
void program() {
    // store all the entered triangles into a vector
    char ans;
    do {
        vector<float> triangle;
        // read three sides of a traingle and store them into triangle vector
        getTriangle(triangle);
        printTriangleInfo(triangle);
        cout << "Would you like to continue? [y/n]: ";
        cin >> ans;
        if (ans != 'y') {
            break;
        }

    }while(true);
    cout << "Good bye...\n";
}

// function to check if 3 sides form a triangle
bool validTriangle(const vector<float> & triangle) {
    // sum of every pair must be greater than the third
    return ((triangle[0]+triangle[1] > triangle[2]) && 
        (triangle[0]+triangle[2] > triangle[1]) && 
        (triangle[1]+triangle[2] > triangle[0]))? true: false;
}

void test_validTriangle() {
    vector<float> t = {2, 3, 4};
    assert(validTriangle(t) == true);
    t = {1, 2, 3};
    assert(validTriangle(t) == false);
    t = {4, 5, 10};
    assert(validTriangle(t) == false);
    cerr << "all test cases passed for validTriangle()\n";
}

// function prompts user to enter 3 sides of a triangle
// creates and returns a triangle
void getTriangle(vector<float> & triangle) {
    // input validation
    triangle = {0, 0, 0}; // initialize three sides with 0s
    do {
        cout << "Enter three sides of a triangle separated by space: ";
        cin >> triangle[0] >> triangle[1] >> triangle[2];
        // check if three sides form a triangle
        if (!validTriangle(triangle))
            cout << "3 sides do not form a traingle.\n"
                << "Sum of any 2 sides must be greater than the third!\n";
        else
            break;
    } while(true);
}

float trianglePerimeter(const vector<float> & triangle) {
    float peri = 0;
    for (auto side: triangle)
        peri += side;
    return peri;
}

// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    vector<float> t = {2, 3, 4};
    assert(trianglePerimeter(t) == 9);
    t = {3, 4, 5};
    assert(trianglePerimeter(t) == 12);
    t = {2.5, 3.5, 4.5};
    assert(trianglePerimeter(t) == 10.5);
    cerr << "all test cases passed for trianglePerimeter()\n";
}

// function to compute area of a triangle
float triangleArea(const vector<float> & triangle) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(triangle)/2;
    return sqrt(s*(s-triangle[0])*(s-triangle[1])*(s-triangle[2]));
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
    vector<float> t = {3, 4, 5};
    assert(triangleArea(t) == 6.0);
    t = {2, 4, 5};
    float area = triangleArea(t); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    t = {3, 4, 6};
    assertAlmostEqual(triangleArea(t), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}

// function to calculate and print the result on triangle
void printTriangleInfo(const vector<float> & triangle) {
    cout << "Triangle info: \n"
         << "3 sides length: " << triangle[0] << " " << triangle[1] << " " << triangle[1]
         << "\narea: " << triangleArea(triangle) 
         << "\nperimeter: " << trianglePerimeter(triangle) << endl;        
}