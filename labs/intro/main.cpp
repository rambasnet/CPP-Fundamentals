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

    // Declare line1 variable of string type and assign the art for line1
    string line1 = "  |\\_/|   **********************    (\\_/)";
    // Declare line2 variable of string type and assign the art for line2
    string line2 = " / @ @ \\  *       ASCII Lab    *   (=\'.\'=)";
    // print line1
    cout << line1 << endl;
    // print line2
    cout << line2 << endl;

    //FIXME3: Declare line3 variable, assign the art for the 3rd line and print the variable
    //FIXME4: Declare line4 variable, assign the art for the 4th line and print the variable
    //FIXME5: Declare line5 variable, assign the art for the 5th line and print the variable

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    // make the console wait for user input
    cin.get();
    return 0; //exit program by returning 0 status to the system
}