// a simple program to demonstrate buffer overflow vulnerability
// TODO: compile and run the program with 7 characters
// run the program with 8 characters
// run the program with more than 8 characters

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char social_security[] = "123-45-6789";
    char password[8]; // supposed to store only 5 characters or bytes
    cout << "Enter your password: ";
    cin >> password;
    // cin doesn't check the boundry or size of password
    // and keeps coping the char until \n
    cout << "you entered: " << password << endl;
    cout << "your SSN = " << social_security << endl;
    return 0;
}