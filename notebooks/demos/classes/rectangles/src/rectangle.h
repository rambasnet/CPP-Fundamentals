#include <iostream>
using namespace std;
// Define a Rectangle class with methods to calculate area and perimeter
class Rectangle
{
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w)
    {
        this->length = l;
        this->width = w;
    }

    // Method to calculate area
    double area()
    {
        return this->length * this->width;
    }

    // Method to calculate perimeter
    double perimeter()
    {
        return 2 * (this->length + this->width);
    }

    // getter for length
    double get_length()
    {
        return this->length;
    }
    // getter for width
    double get_width()
    {
        return this->width;
    }

    // setter for length
    void set_length(double l)
    {
        this->length = l;
    }
    // setter for width
    void set_width(double w)
    {
        this->width = w;
    }

    // == Overloading the equality operator
    bool operator==(const Rectangle &other)
    {
        return (this->length == other.length) && (this->width == other.width);
    }
    // Destructor
    // / << Overloading the stream insertion operator for easy output
    // << Overloading the stream insertion operator for easy output
    friend ostream &operator<<(ostream &os, const Rectangle &rect)
    {
        os << "Rectangle(length: " << rect.length << ", width: " << rect.width << ")";
        return os;
    }
    ~Rectangle() {}
};