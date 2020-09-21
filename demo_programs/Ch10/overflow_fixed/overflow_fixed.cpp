// Authenticator program with fixed buffer overflow vulnearbility
// TODO: Compile and run the program using given Makefile
// try to get the program print the password without providing the correct username and password
// goal is to display the social security without using the hidden password; but you shouldn't succeeed!

#include <iostream>
#include <cstring>

using namespace std;

// function reads data one character at a time upto size-1 length 
// or '\n' which ever comes first
void readData(char buffer[], unsigned int size){
    char ch;
    for(int i=0; i<size-1; i++) {
        cin.get(ch);
        if (ch == '\n') break;
        buffer[i] = ch;
    }
    buffer[size-1] = 0; // end the buffer with NULL character
}

int main()
{
    bool valid = false;
    char username[10]; //c-string
    char password[10]; //c-string
	
    cout << "Enter username: ";
    readData(username, 10);
	cout << "Enter password: ";
	readData(password, 10);

	if (string(username) == "backdoor" && strcmp(password, "123456") == 0)
		valid = true;
	
    //cout << boolalpha << valid << endl;
    if(valid) {
        cout << "You have now access to top secret part of the program!" << endl;
        cout << "Your social is 123-45-5678\n";
    }
    else
        cout << "invalid password" << endl;
   
   return 0;
}