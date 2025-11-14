/*
Menu-driven program demo
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

template<class T>
T add(T val1, T val2) {
    return val1 + val2;
}

template<class T>
T subtract(T val1, T val2) {
    return val1 - val2;
}

template<class T>
T larger(T val1, T val2) {
    return val1 >= val2?val1:val2;
}

template<class T>
double average(T val1, T val2) {
    return add(val1, val2)/2.0;
}

int getMenuOption() {
    // A Smiple CLI-based calculator
    int option;
    cout << "Enter one of the following menu options: [1-6]\n"
        << "1 -> Add\n"
        << "2 -> Subtract\n"
        << "3 -> Larger\n"
        << "4 -> Average\n"
        << "5 -> Multiply\n"
        << "6 -> Quit\n";
    cin >> option;
    return option;
}

void program() {
    float n1, n2;
    int option;
    option = getMenuOption();
    if (option == 6) {
        cout << "Good bye...\n";
        return;
    }
    cout << "Enter two numbers separated by space: ";
    cin >> n1 >> n2;
    switch(option) {
        case 1:
            cout << n1 << " + " << n2 << " = " << add<float>(n1, n2) << endl;
            break; // terminate switch
        case 2:
            cout << n1 << " - " << n2 << " = " << subtract<float>(n1, n2) << endl;
            break;
        case 3:
            cout << "larger between: " << n1 << " and " << n2 << " is " << larger<float>(n1, n2) << endl;
            break;
        case 4:
            cout << "average of " << n1 << " and " << n2 << " = " << average<float>(n1, n2) << endl;
            break;
        default:
            cout << n1 << " x " << n2 << " = " << n1*n2 << endl;
            break;
    }
}

int main() {
    program();
    return 0;
}