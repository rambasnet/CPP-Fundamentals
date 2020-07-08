// A C++ program that demonstrates the function prototypes

#include <iostream>
using namespace std;

// function prototypes
// TODO: uncomment these out for the program to compile
//float average(int, int);
//int addInts(int, int);

int main() {
    int n1 = 10;
    int n2 = 20;
    cout << "average of " << n1 << " and " << n2 << " = " << average(n1, n2);
    
    return 0;
}

// function computes and returns average of two integers
float average(int a, int b) {
    // average can call addInts,
    // eventhough it has not beed defined yet
    long sum = addInts(a, b);
    return sum/2.0;
}

// function computes and returns sum of two integers
int addInts(int a, int b) {
    return a+b;
}