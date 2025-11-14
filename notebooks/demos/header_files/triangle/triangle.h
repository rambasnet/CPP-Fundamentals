// Triangle struct and function prototypes

#pragma once // include guard; tells the compiler to only include this file once

#include <vector>
using namespace std;

// use struct to represent Triangle
struct Triangle {
    int ID;
    float side1, side2, side3;
};

// function prototypes
bool validTriangle(float s1, float s2, float s3);
void test_validTriangle();
Triangle getTriangle();
float trianglePerimeter(const Triangle & t);
void test_trianglePerimeter();
float triangleArea(const Triangle & t);
void assertAlmostEqual(float value1, float value2, int precision);
void test_triangleArea();
void computeAreaAndPerimeter(const Triangle & t);
void program();
void menu();
void readTriangles(vector<Triangle> &, const string &);
void writeTriangles(const vector<Triangle> &, const string &);

int searchTriangle(const vector<Triangle> &, int);
bool smaller(const Triangle & t1, const Triangle & t2);
bool larger(const Triangle & t1, const Triangle & t2);
void printTriangles(const vector<Triangle> & tris);

