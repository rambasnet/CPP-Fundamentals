/*
    ASCII Lab
    ASCII Art and Standard Ouput
    
    Updated By: Your name #FIXME1
    Date: ... #FIXME2
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Write a series of cout statements to print the ASCII art.
*/

#include <iostream> //library for input and output
#include <string>
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    string name; // variable to store user's name
    cout << "Hi there, what's your full name? ";
    getline(cin, name);
    cout << "Nice meeting you, " << name << "!" << endl;
    cout << "Hope you'll like my ascii art...\n";

    cout << "  |\\_/|   ******************    (\\_/)" << endl;
    cout << " / @ @ \\  *       Lab 1    *   (=\'.\'=)" << endl;

    //FIXME3: print the third row
    //FIXME4: print the fourth row
    //FIXME5: print the final row

    // the following code may be required to make your console pause...
    cout << "Hit enter to exit the program!" << '\n';
    // make the console wait for user input
    cin.get();
    cout << "Good bye...\n";
    return 0; //exit program by returning 0 status to the system
}