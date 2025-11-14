// main program

#include <iostream>
#include "utility.h" //user-defined header file
using namespace std;

int main(int argc, char* argv[]) {
    int num1, num2;
    long ans;
    getData(num1, num2);
    ans = add(num1, num2);
    cout << "sum = ";
    print(ans);
    
    return 0;
}