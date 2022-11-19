#include <iostream>
using namespace std;

long add(int x, int y) {
    return x+y;
}

void print(long x) {
    cout << x << endl;
}

void getData(int & x, int & y) {
    cout << "Enter two numbers separated by space: ";
    cin >> x >> y;
}