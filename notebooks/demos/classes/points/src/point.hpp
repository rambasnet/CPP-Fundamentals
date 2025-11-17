#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class Point
{
private:
    double *x;
    double *y;

public:
    Point(double xCoord, double yCoord);
    double distance_from_origin() const;
    Point operator+(const Point &p) const;
    bool operator==(const Point &p) const;
    friend ostream &operator<<(ostream &os, const Point &p);
    ~Point();
};