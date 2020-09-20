/*=====================================================
Area and Perimeter of a Rectangle
By: Ram Basnet
Date: 07/06/2020
License: MIT - Feel free to use it however you want. 

Program finds area and perimeter of a Rectangle using functions.

Algorithm steps:
1. prompt user to enter length and  width of a rectangle
  i. store the values into variables
2. calculate perimeter by summing two sides
  - perimeter = 2 x (length + width)
3. calculate area = length x width
4. display the results
======================================================*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cassert>

using namespace std;

// function prototypes

// 1.a. function to read length
float getLength();
// 1.b function to read width
float getWidth();
// 2. function to calculate area given length and width
float findArea(float, float);
// 3. function to calculate perimeter given length and width
float findPerimeter(float, float);
// 4. function to display the results (length, width, area, and perimeter of a rectangle)
void printResults(float, float, float, float);

void displayTitle();

void program();

// Test functions
void testFindArea();
void testFindPerimeter();

#define ERROR_MARGIN 0.001 // the relative error ~ 0.001

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        // run automated tests
        cout << setw(40) << setfill('=') << '\n';
        cout << setw(20) << setfill(' ') << "Automated Testing" << endl;
        testFindArea();
        testFindPerimeter();
        cout << setw(40) << setfill('=') << "" << setfill(' ') << endl;
        exit(EXIT_SUCCESS); // exit the program
    }
    else { 
        program();
    }
    cout << "Good bye! Enter to exit the program...";
    cin.ignore(INT_MAX, '\n');
    cin.get();
    // all done; exit the program!
    return 0;
}

void program() {
     // variables to store data
    float length, width, area, perimeter;
    // print description
    displayTitle();
    // 1.a get length
    length = getLength();
    // 1.b get width
    width = getWidth();
    // 2. find perimeter
    perimeter = findPerimeter(length, width);
    // 3. find area
    area = findArea(length, width);
    // 4. display results
    printResults(length, width, area, perimeter);
}

void displayTitle() {
    printf("%s\n", "Area and Perimeter of a Rectangle using Functions");
    printf("%s\n", "Program finds Area and Perimeter given length and width of a Rectangle");
    cout << setw(40) << setfill('=') << "\n";
    cout << setfill(' ');
}

float getLength() {
    float length;
    cout << "Enter length of a rectangle: ";
    cin >> length;
    return length;
}

float getWidth() {
    float width;
    cout << "Enter width of a rectangle: ";
    cin >> width;
    return width;
}

float findPerimeter(float length, float width) {
    return 2*(length+width);
}

float findArea(float length, float width) {
    return length * width;
}

void printResults(float length, float width, float area, float perimeter) {
    int colwidth = 50;
    // create output stream
    ostringstream output;
    output << setw(colwidth) << setfill('=') << '\n';
    output << setw(10) << setfill(' ') << " " << "Results on the Rectangle" << endl;
    output << setw(colwidth) << setfill('=') << '\n';
    output << fixed << setprecision(2);
    colwidth = 20;
    output << setfill(' ') << setw(colwidth) << "length: " << length << endl;
    output << setw(colwidth) << "width: " << width << endl;
    output << setw(colwidth) << "perimeter: " << perimeter << endl;
    output << setw(colwidth) << "area: " << area << endl;
    output << setw(50) << setfill('*') << '\n';
    // print the output result to console
    cout << output.str();
}

void testFindArea() {
    cerr << "Testing findArea function...\n";
    float length, width;
    length = 10; width=5;
    assert(findArea(length, width) == 50);
    assert(findArea(4, 3) == 12);
    // testing floating point answer; need to round to some decimal points
    length = 10.55; width = 3.99;
    float area = findArea(length, width);
    assert(fabs(area - 42.094) < ERROR_MARGIN);
    
    cerr << "All test cases passed...\n";
}

void testFindPerimeter() {
    cerr << "Testing findPerimeter function...\n";
    float length, width;
    length = 10; width=5;
    assert(findPerimeter(length, width) == 30);
    assert(findPerimeter(4, 3) == 14);

    // testing floating point answer; need to round to some decimal points
    length = 10.55; width = 3.99;
    float perimeter = findPerimeter(length, width);
    assert(fabs(perimeter - 29.08) < ERROR_MARGIN);

    cerr << "All test cases passed...\n";
}
