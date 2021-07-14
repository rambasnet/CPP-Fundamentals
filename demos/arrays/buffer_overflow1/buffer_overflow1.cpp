// Buffer overflow Example 1
// a simple program to demonstrate buffer overflow vulnerability by corrupting data in memory
// Run the program with various length of passwords (any characters!) and notice the output of SSN
// TODO: 
// 1. compile and run the program with 7 characters
// 2. run the program with 8 characters
// 3. run the program with more than 8 characters
// You'll see the SSN being overwritten and corrupted with part of your password

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char social_security[] = "123-45-6789";
    char password[8]; // supposed to store only 8 characters or bytes including the null byte
    cout << "Enter your password: ";
    cin >> password;
    // cin doesn't check the boundry or size of password
    // and keeps coping the char until \n
    cout << "you entered: " << password << endl;
    cout << "your SSN = " << social_security << endl;
    return 0;
}