/*
    ASCII Lab
    ASCII Art - Using variables
    
    Updated By: <Your name> #FIXME1
    Date: ... #FIXME2
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the values.
*/

#include <iostream> //library for input and output
#include <string>
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    // FIXME3: declare a variable to store name
    // FIXME4: assign "your full name" to the variable declared in FIXME3
    //FXIME5: greet the name using the variable as the following output
    //must output: Nice meeting you, <name>!

    string line1 = "  |\\_/|   **********************    (\\_/)\n";
    cout << line1;

    //FIXME6: use variable to print the 2nd line
    //FIXME7: use variable to print the 3rd line
    //FIXME8: use variable to print the 4th line
    //FIXME9: use variable to print the 5th line

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    // FIXME10: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}