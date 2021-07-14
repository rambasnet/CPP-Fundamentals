/*
Program converts 13 decimal to binary

Algorithm step:
    1. repeteadly divide the decimal number by base 2 until the quotient becomes 0
    2. collect the remainders in reverse order
        - the first remainder is the last (least significant) digit in binary
*/

#include <iostream> // cin, cout
#include <string> // string, to_string

using namespace std; // std::cin, std::cout, std::endl, etc.

int main () {
    // decimal to binary conversion requires to calculate both quotient and remainder
    const int divisor = 2; // divisor is contant name whose value can't be changed once initialized with
    int dividend;
    int quotient, remain;
    string answer; // collect remainders by prepending as a string

    answer = "";
    quotient = 13; //start with the decimal 13

    // Div 1
    // divide quotient
    dividend = quotient;
    remain = dividend%divisor;
    quotient = dividend/divisor;
    // print intermediate results; help us see and plan further computation
    cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
    answer = to_string(remain) + answer; // prepend remainder to answer
    // is quotient 0? No!

    // Div 2
    // further divide quotient
    dividend = quotient;
    remain = dividend%divisor;
    quotient = dividend/divisor;
    // print intermediate results; help us see and plan further computation
    cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
    answer = to_string(remain) + answer; // prepend remainder to answer
    // is quotient 0? No!
    
    // Div 3
    // further divide quotient
    dividend = quotient;
    remain = dividend%divisor;
    quotient = dividend/divisor;
    // print intermediate results; help us see and plan further computation
    cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
    answer = to_string(remain) + answer; // prepend remainder to answer
    // is quotient 0? No!

    // Div 4
    // further divide quotient
    dividend = quotient;
    remain = dividend%divisor;
    quotient = dividend/divisor;
    // print intermediate results; help us see and plan further computation
    cout << dividend << '/' << divisor << " => quotient: " << quotient << " remainder: " << remain << endl;
    answer = to_string(remain) + answer; // prepend remainder to answer
    // is quotient 0? Yes!

    // no more division; display the answer
    cout << "13  decimal = " << answer << " binary " << endl;

    return 0;
}