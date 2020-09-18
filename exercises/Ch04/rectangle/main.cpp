/*=====================================================
Area and Perimeter of a Rectangle
By: Ram Basnet
Date: 07/06/2020
License: MIT - Feel free to use it however you want.

Program finds area and perimeter of a Rectangle using as many libraries as possible.

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

using namespace std;

int main() {
    // variables to store 2 sides of a rectangle
    float length, width;
    // variables to store results
    float area, perimeter;
    string input;
    // print description
    printf("%s\n", "Area and Perimeter of a Rectangle");
    cout << setw(40) << setfill('=') << "\n";
    cout << setfill(' ');
    cout << "Program finds area and perimeter of a rectangle given length and width.\n";
    //1. prompt user
    cout << "Enter length and width of a rectangle separated by space: ";
    // i. read data as a string line and then parse! instead of ...
    //cin >> length >> width;
    getline(cin, input);
    // create input string stream
    istringstream inputstream(input);
    // parse into three sides
    inputstream >> length >> width;
    // 2.
    perimeter = 2*(length + width);
    // 3. 
    area = length * width;
    // 4.
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

    // all done; successfully exit the program!
    return 0;
}