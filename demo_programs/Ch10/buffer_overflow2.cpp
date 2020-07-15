// bufferflow example 2
// TODO: Compile and run the program using g++
// if yo see Abort trap for long password, use -fno-stack-protector
// compilers provide way to detect stack-overflow so must disable!
// enter 10 As or more for passoword
// goal is to display the social security without using the hidden password

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int valid = 0;
    char passBuffer[8];
	
	cout << "Enter password: " << endl;
	cin >> passBuffer;
	//strcpy(passBuffer, password);

	if (strcmp(passBuffer, "1234567") == 0)
		valid = 1;
	
    //cout << valid << endl;
    if(valid) {
        cout << "You have now access to top secret part of the program!" << endl;
        cout << "Your social is 456-67-5678\n";
    }
    else
        cout << "invalid password" << endl;
   
   return 0;
}