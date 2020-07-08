/*=================================================
  Hello World program
  By: Ram Basnet
  Date: June 24, 2020
  Copyright: MIT License
  
  The program prints "Hello World!" on the console
  - provides automated testing
===================================================*/

// include required libraries/header files
#include <iostream>
#include <string>
#include <cassert> // assert()

using namespace std;

// function prototypes
string hello();
void test_hello();

int main() // main entry to the program 
{
    // run test cases
    test_hello();
    // output/print Hello World!
    cout << hello() << endl;
    return 0;
}

// function returns Hello World!
string hello() {
    return "Hello World!";
}

// function that tests hello function
void test_hello() {
    assert(hello() == "Hello World!");
    cerr << "all test cases passed!\n";
}