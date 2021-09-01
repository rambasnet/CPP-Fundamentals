/*
    Demonstrating ops on strings i.e. checks for equivalence etc.
	
	Sherine M Antoun
    CMU 2021 Spring
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name1;

	cout << "Enter name1: ";
	cin>> name1;

	const char* ptr = name1.c_str();// return me a new pointer to a c string representing name1
								
	cout << "Pointer to a C string " << ptr << endl;
	
	return 0;
}
