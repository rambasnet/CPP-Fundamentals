/* Handling Exceptions within a program */
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double conversion = 2.54;

const int inchesInFoot = 12;

double getLength();

int main ()
{
    double feet;
	double inches;
	double centimeters;

	cout << fixed << showpoint << setprecision(2);

	cout << "Feet: ";
	feet = getLength();
	cout << endl;

	cout << "Inches: ";
	inches = getLength();
	cout << endl;

	centimeters = (inchesInFoot * feet + inches ) * conversion;

	cout << "Centimeter: " << centimeters << endl;

    return 0;
}

double getLength()
{
	bool done = false;
	double number = 0;

    string str =
           "The input stream is in the fail state.";

    do
    {
        try
        {
            cout << "Enter a nonnegative number: ";
            cin >> number;
            cout << endl;

			if(number < 0)
				throw -1;

            if (!cin)
                throw str;
            done = true;

        }
		catch(int)
		{
			cout << "A non positive number is entered" << endl;
			number = 0;
		}
        catch(string messageStr)
        {
            cout << messageStr << endl << "Restoring the input stream."
                 << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (!done);


	return number;
}
