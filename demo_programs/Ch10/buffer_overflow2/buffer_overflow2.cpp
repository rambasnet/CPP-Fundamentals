// bufferflow example 2
// TODO: Compile and run the program using given Makefile
// enter whatever username and about 20 As or more for passoword
// goal is to display the social security without using the hidden password

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    bool valid = false;
    char username[10];
    char password[10];
	
    cout << "Enter username: ";
    cin >> username;
	cout << "Enter password: ";
	cin >> password;
	//strcpy(passBuffer, password);

	if (string(username) == "backdoor" && strcmp(password, "123456") == 0)
		valid = true;
	
    //cout << valid << endl;
    if(valid) {
        cout << "You have now access to top secret part of the program!" << endl;
        cout << "Your social is 123-45-5678\n";
    }
    else
        cout << "invalid password" << endl;
   
   return 0;
}