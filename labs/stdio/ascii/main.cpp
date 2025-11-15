/*
    StdIO Lab
    Printing ASCII Art Using Standard Input/Output

    Updated By: <FIXME>
    Date: <FIXME>

    This program produces an ASCII art on the console using C++ std IO.

    Algorithm steps:
    1. Declare variables to store data/values
    3. Write and use function to center text within a give column width
    3. Write a series of input/output statements to get data/values and print them on the console.
*/

#include <iostream> // C++ library for std IO
#include <iomanip>  // C++ library for formatting IO
#include <string>   // C++ library for string data
#include "util.h"   // include the utility header file for center_text function

using namespace std; // resolve cout, cin, endl, etc. identifiers for C++ stdio

// main entry point of the program
int main()
{
    const int middle_width = 60;
    const int tom_width = 20;
    const int jerry_width = 20;
    cout << center_text(100, "STD IO Lab using C and C++ libraries") << endl;
    // create a string with 75 = signs; center the string and print it out
    cout << center_text(100, string(50, '=')) << endl
         << endl;
    string lab_title; // declare a variable to store your name
    // prompt to enter your name from standard input
    cout << "Enter Lab Title: ";
    // store the entered data/title into lab_title variable
    getline(cin, lab_title);

    // FIXME1: declare a variable to store programmer's name
    // FIXME2: prompt to enter programer's name and store the entered data into the declared variable

    // FIXME3: prompt user to enter course name (e.g., CSCI 111) and store the data into a declared variable
    // FIXME4: prompt user to enter semester info (e.g., Fall 2022) and store the data into a declared variable

    const string tom1 = "|\\_/|";
    const string jerry1 = "(\\_/)";
    const string tom2 = "/  @  @ \\";
    const string jerry2 = "(='.'=)";
    string asterics = string(middle_width, '*'); // create a string with 50 asterics

    // create the first line of the ASCII art
    string tom_line1 = center_text(tom_width, tom1);
    string info_line1 = center_text(middle_width - 2, asterics);
    string jerry_line1 = center_text(jerry_width, jerry1);

    // Print the 1st line
    cout << tom_line1 << info_line1 << jerry_line1 << endl;

    // create the 2nd line of the ASCII art
    string tom_line2 = center_text(tom_width, tom2);
    string info_line2 = center_text(middle_width - 2, lab_title);
    string jerry_line2 = center_text(jerry_width, jerry2);

    // Print the 2nd line
    cout << tom_line2 << '*' << info_line2 << '*' << jerry_line2 << endl;

    // FIXME5: Create and print the 3rd line of the ASCII art
    // FIXME6: Create and print the 4th line of the ASCII art
    // FIXME7: Create and print the 5th line of the ASCII art

    // Note: You can add more lines or print more ASCII arts of your choice ... if you'd like to...

    cout << "\nGood bye... hit enter to exit the program.\n";
    // FIXME8: make the console wait for user input

    return 0; // exit program by returning 0 status to the system
}