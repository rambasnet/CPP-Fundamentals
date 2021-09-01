// Exception example

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int x;

	try
	{
		cout << "Enter a number less than 100: ";
		cin >> x;
		if ( x >= 100)
			throw 1;

		cout << "Congratulations, you entered good data\n\n";
	}
	catch (int i)
	{
		cout << "Exception " << i << " thrown\n\n";
		//system("PAUSE"); // uncoment for DevC++
		exit(1);
	}

	cout<<"Now lets get on with the resemainder of the program\n\n";

	/* remainder of program */

	
	return 0;
}
