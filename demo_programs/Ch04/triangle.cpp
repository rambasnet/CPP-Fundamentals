/*=====================================================
Area and Perimeter of a Triangle
By: Ram Basnet
Date: 07/06/2020
License: MIT - Feel free to use it however you want. 

Program finds area and perimeter of a Triangle.
Algorithm steps:
1. prompt user to enter 3 sides of a triangle
  - sum of 2 any two sides must be greater than the third
2. store the the values of 3 sides
3. calculate perimeter by summing all three sides
  - perimeter = a + b + c
4. calculate area using Heron's formula
  - https://www.mathsisfun.com/geometry/herons-formula.html 
  i. calculate s (half the perimeter)
    s = (a + b + c)/2
  ii. area = squareroot(s(s-a)(s-b)(s-c))
======================================================*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    // variables to store 3 sides of a triangle
    float a, b, c;
    // variables to store intermediate and final results
    float s, area, perimeter;
    string input;
    // print description
    cout << "Area and Perimeter of a Triangle\n";
    cout << setw(40) << setfill('=') << "\n";
    cout << setfill(' ');
    cout << "Program finds area and perimeter of a triangle given length of three sides.\nThree sides form a traingle iff sum of the two is greater than the third.\n";
    //1. prompt user
    cout << "Enter length of 3 sides that form a triangle: ";
    // 2. read data as a string line and then parse! instead of ...
    //cin >> a >> b >> c;
    getline(cin, input);
    // create input string stream
    istringstream inputstream(input);
    // parse into three sides
    inputstream >> a >> b >> c;
    // 3.
    perimeter = a+b+c;
    // 4.i
    s = perimeter/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    int width = 50;
    // create output stream
    ostringstream output;
    output << setw(width) << setfill('=') << '\n';
    output << setw(10) << setfill(' ') << " " << "Results on the triangle" << endl;
    output << setw(width) << setfill('=') << '\n';
    output << fixed << setprecision(2);
    width = 20;
    output << setfill(' ') << setw(width) << "side a: " << a << endl;
    output << setw(width) << "side b: " << b << endl;
    output << setw(width) << "side c: " << c << endl;
    output << setw(width) << "perimeter: " << perimeter << endl;
    output << setw(width) << "area: " << area << endl;
    output << setw(50) << setfill('*') << '\n';
    // print the output result to console
    cout << output.str();

    // all done; successfully exit the program!
    return 0;
}