/*
    StdIO Lab
    ASCII Art - using C and C++ Standard Input/Output
    
    Updated By: <FIXME>
    Date: <FIXME>
    
    This program produces an ASCII art on the console using C and C++ std IO.

    Algorithm steps: 
    1. Declare variables to store data/values
    3. Write and use function to center text within a give column width
    3. Write a series of input/output statements to get data/values and print them on the console.
*/

#include <iostream> // C++ library for std IO
#include <iomanip> // C++ library for formatting IO
#include <string> // C++ library for string data
#include <cstdio> // C library for std IO
 
using namespace std; //resolve cout, cin, endl, etc. identifiers for C++ stdio

// function to center string
// given width of the column and the string, function returns centered string within the column
// https://stackoverflow.com/questions/14861018/center-text-in-fixed-width-field-with-stream-manipulators-in-c
string centerText(int width, const string& str) {
    int len = str.length();
    if(width < len) { 
        return str; 
    }
    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' ');
}
 
//main entry point of the program
int main()
{
    const int middleWidth = 60;
    const int tomWidth = 20;
    const int jerryWidth = 20;
    cout << centerText(100, "STD IO Lab using C and C++ libraries") << endl;
    cout << centerText(100, string(50, '=')) << endl << endl; // create a string with 75 =
    string labTitle; // declare a variable to store your name
    // prompt to enter your name from standard input
    cout << "Enter Lab Title: ";
    // store the entered data/title into labTitle variable
    getline(cin, labTitle);
   
    //FIXME1: declare a variable to store programmer's name
    //FIXME2: prompt to enter programer's name and store the entered data into the declared variable

    //FIXME3: prompt user to enter course name (e.g., CSCI 111) and store the data into a declared variable
    //FIXME4: promput user to enter semester info (e.g., Fall 2022) and store the data into a declared variable

    const string tom1 = "|\\_/|";
    const string jerry1 = "(\\_/)";
    const string tom2 = "/  @  @ \\";
    const string jerry2 = "(='.'=)";
    string asterics = string(middleWidth, '*'); // create a string with 50 asterics
    
    // Using C++, print first line
    cout << centerText(tomWidth, tom1)
         << centerText(middleWidth, asterics)
         << centerText(jerryWidth, jerry1) << endl;

    // Using C, print 2nd line
    printf("%s*%s*%s\n", centerText(tomWidth, tom2).c_str(), centerText(middleWidth-2, labTitle).c_str(), centerText(jerryWidth, jerry2).c_str());

    //FIXME5: Using C++, print 3rd line
    //FIXME6: Using C, print 4th line
    //FIXME7: Print the rest of the ASCII art using either C or C++ output statements

    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout << "\nGood bye... hit enter to exit the program.\n";
    //FIXME8: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}