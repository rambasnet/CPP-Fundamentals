// Define a Point class with methods to calculate distance from origin
#include <iostream>
#include <cmath>
#include "point.hpp"
using namespace std;

// Constructor
Point::Point(double xCoord, double yCoord)
{
    this->x = new double(xCoord);
    this->y = new double(yCoord);
}

// Method to calculate distance from origin
double Point::distance_from_origin() const
{
    return sqrt((*x) * (*x) + (*y) * (*y));
}
// overload + operator to add two points
Point Point::operator+(const Point &p) const
{
    return Point((*this->x + *p.x), (*this->y + *p.y));
}
// overload == operator to compare two points
bool Point::operator==(const Point &p) const
{
    return (*this->x == *p.x) && (*this->y == *p.y);
}

// Destructor
Point::~Point()
{
    delete x;
    delete y;
}

// overload << operator to print point
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    return os << "(" << *(p.x) << ", " << *(p.y) << ")";
}