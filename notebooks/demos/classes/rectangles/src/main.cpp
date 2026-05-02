#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
    // Create a Rectangle object
    Rectangle rect(5.0, 3.0);
    // Display the rectangle's properties
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    cout << "Length: " << rect.get_length() << endl;
    cout << "Width: " << rect.get_width() << endl;

    // Overload the stream insertion operator to display the rectangle
    cout << rect << endl;
    // TODO - create dynamic objects using new and delete, and demonstrate operator overloading for equality and stream insertion.
    Rectangle *rect1 = new Rectangle(5.0, 3.0);
    if (*rect1 == rect)
    {
        cout << "rect1 is equal to rect" << endl;
    }
    else
    {
        cout << "rect1 is not equal to rect" << endl;
    }
    cout << *rect1 << endl;
    cout << rect1->area() << endl;
    cout << rect1->perimeter() << endl;

    delete rect1;
    return 0;
}