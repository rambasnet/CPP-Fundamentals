/*
    ASCII Lab
    ASCII Art and Standard Input/Ouput
    
    Updated By: <Your name> #FIXME1
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

    cout << "Hi there!" << endl;
    cout << "Hope you like my Tom & Jerry ASCII art...\n\n";

    cout << "  |\\_/|   **********************    (\\_/)" << endl;
    cout << " / @ @ \\  *       ASCII Lab    *   (=\'.\'=)" << endl;

    //FIXME3: print the third line
    //FIXME4: print the fourth line
    //FIXME5: print the final line

    // the following code may be required to make your console pause...
    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    // make the console wait for user input
    cin.get();
    return 0; //exit program by returning 0 status to the system
}