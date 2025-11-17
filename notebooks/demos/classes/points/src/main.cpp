#include <iostream>
#include "point.hpp"

using namespace std;

int main()
{
    Point p1(3.0, 4.0);
    Point p2(1.0, 2.0);
    Point p3 = p1 + p2;

    cout << p3 << endl;
    Point p4(3.0, 4.0);
    if (p1 == p4)
    {
        cout << "p1 is equal to p4" << endl;
    }
    else
    {
        cout << "p1 is not equal to p4" << endl;
    }

    return 0;
}