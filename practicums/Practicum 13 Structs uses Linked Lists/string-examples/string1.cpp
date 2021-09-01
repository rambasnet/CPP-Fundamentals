/*
    Introduction to C++ string type
    Sherine M Antoun
    CMU 2021 Spring
*/

#include <string>
#include <iostream>
using namespace std;

int main()
{
	string foo;
	string boo;

	foo = "Hello";
	boo = ", get out";

	string moo = foo + boo;		// concatenates strings 

	cout << moo << endl;
	return 0;
}

