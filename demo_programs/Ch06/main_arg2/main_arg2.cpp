// program demonstrates passing arguments to main
// TODO: compile and run the program 
#include <iostream>
#include <cstring> //strncmp
#include <string>
#include <cstdlib> //atof
#include <cassert>

using namespace std;

// templated function computes and returns sum of two numbers
template<class T1, class T2>
T2 sum(T1 n1, T2 n2) {
    return n1+n2;
}

// function prototypes

// templated function to find product of two numbers
template<class T1, class T2>
T2 product(T1, T2);

void test();
void help(string);

// main takes arguments
int main(int argc, char* argv[]) {
    cout << "program adds or multiplies two given numbers.\n";
    string programName = string(argv[0]);
    if (argc == 4) {
        // program must run with 3 additional arguments, e.g.
        // program.exe sum 3 10.5
        float arg2, arg3; // block scope variables
        arg2 = atof(argv[2]);
        arg3 = atof(argv[3]);
        // or convert to string type and easily compare using ==
        if (string(argv[1]) == "sum")
            cout <<  arg2 << " + " << arg3 << " = " << sum<float, float>(arg2, arg3) << endl;
        else if(string(argv[1]) == "product")
            cout << arg2 << " * " << arg3 << " = " << product<float, float>(arg2, arg3) << endl;
        else {
            cout << "Error: " << argv[1] << " is an invalid argument!\n";
            help(programName);
        }
    }
    // comparing c_string using strncmp function
    else if(argc == 2 && strncmp(argv[1], "test", 4) == 0)
        test();
    else
       help(programName);
    
    return 0;
}

// templated function computes and returns product of two numbers
template<class T1, class T2>
T2 product(T1 n1, T2 n2) {
    return n1*n2;
}

void test() {
    cerr << "running test cases...\n";
    // NOTe: template parameters don't work in assert()
    // type parameters are not required for fundamental types!
    assert(sum(10, 20) == 30);
    assert(sum(10.5f, 3.5f) == 14);
    assert(product(10, 20) == 200);
    assert(product(3.5f, 2.0f) == 7);
    cerr << "all test cases passed for sum() and product()\n";
}

void help(string programName) {
    cout << "Usage examples...\n";
    cout << programName << " sum 10 20.5\n";
    cout << programName << " product 15 100\n";
    cout << programName << " test\n";
}