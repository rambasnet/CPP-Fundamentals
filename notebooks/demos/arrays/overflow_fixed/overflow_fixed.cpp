// Authenticator program with fixed buffer overflow vulnearbility
// TODO: Compile and run the program using the given Makefile
// try to get the program print the password without providing the correct username and password
// goal is to display the social security without using the hidden password; but you shouldn't succeeed!

#include <iostream>
#include <cstring>

using namespace std;

// function reads data one character at a time upto size-1 length 
// or '\n' which ever comes first
void readData(char buffer[], unsigned int size) {
    char ch;
    int i = 0;
    bool newLineRead = false;
    while (i < size-1) {
        cin.get(ch);
        if (ch == '\n') {
            newLineRead = true;
            break;
        }
        buffer[i++] = ch;
    }
    buffer[i] = 0; // end the buffer with NULL character
    // read and discard the rest of the characters from std input stream upto '\n'
    if (not newLineRead) cin.ignore(INT_MAX, '\n');
}

int main(int argc, char* argv[]) {
    bool valid = false;
    char username[10]; //c-string; buffer
    char password[10]; //c-string; buffer
	
    cout << "Enter username: ";
    readData(username, 10); // read data checking bounds/size
	cout << "Enter password: ";
	readData(password, 10); // read data checking bounds/size

	if (string(username) == "backdoor" && strcmp(password, "123456") == 0)
		valid = true;
	
    if (valid) {
        cout << "You have now access to the top secret part of the program!" << endl;
        cout << "Your social is 123-45-5678\n";
    }
    else
        cout << "invalid username or password" << endl;
   
   return 0;
}