/*
Composition Example
Author: Ram Basnet
CS1 at Colorado Mesa University
Copyright: MIT - Feel free to use the code.

The program finds area and perimeter of a rectangle.

Algorithm steps:

1. get values for length and width of a rectangle
2. calculate area and perimeter using the following equations
    - area = length x width
    - perimeter = 2 x (length + width)
3. display the results

*/

#include <iostream>

using namespace std;

int main() {
  // 1. variables to store length and width
  float rect_length, rect_width;
  // 1. prompt user to enter length and width of a rectangle
  cout << "Enter length and width of a rectangle separated by space: ";
  // 1. read length and width values from keyboard
  cin >> rect_length >> rect_width;
  // 2 and 3 calculate and display area and perimeter
  // 2 and 3: calculate and display the area and perimeter
  cout << "area of the rectangle: " << rect_length * rect_width << endl;
  cout << "perimeter of the rectangle: " << 2*(rect_length+rect_width) << endl;
  
  return 0;
}