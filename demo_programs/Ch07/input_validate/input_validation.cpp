/*
  do-while demo
  Author: Ram Basnet
  Date: 7/11/2020
  License: MIT - Feel free to use anyhow

  This program validates user input using do-while loop
  - valdite if the user input is an integer between 1 and 20.
*/

#include <iostream>

using namespace std;

int getNumber() {
    int input; // variable to store user input

    do {
        cout << "Enter a whole number between 1 and 20: ";
        cin >> input;
        if (cin.fail()) { // somehow cin failed 
            cout << "Invalid input. Try again!\n";
            cin.clear(); // clear the error flag
            cin.ignore(INT_MAX, '\n'); // ignore upto INT_MAX bytes in std input stream or '\n'
        }
        else if (input < 1 || input > 20) {
            cout << "input must be a whole number between 1 and 20\n";
        }
        else break;
    } while (true);
    
    return input;
}

int main(int argc, char* argv[]) {
    // declare and intialize variables;
    int num = getNumber();
    cout << "Great! you entered: " << num << endl;
    return 0;
}