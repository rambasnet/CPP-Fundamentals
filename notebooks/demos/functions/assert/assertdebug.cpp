// a program to demonstrate assert statement
// demonstrates debugging and unittesting concept 
// TODO: compile and run the program redirecting the output to a text file
// a.out > output.txt

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
using namespace std; 

int main()
{
    assert(2+2 == 4);
    // output to stdout stream;
    // can redirect the result to a output.txt file
    cout << "2+2 equals to 4 is true!\n";
    // output to stderr stream; still see the output on console
    // can't redirect the cerr output
    cerr << "Execution continues past the first assert\n";
    assert(2+3 == 4);
    cerr << "Execution continues past the second assert\n";
    assert(3%2 == 1);
    cerr << "Yet another assert message\n";

    return 0;
}
