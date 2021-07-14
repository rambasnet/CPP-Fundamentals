#include <cstdlib> //system()
#include <sstream>
#include <iomanip>
#include <cassert>

#include "utility.h"

using namespace std;

// clear function that is system independent
// NOTE: system call is not a best practice
void clear() {
    #ifdef _WIN32 // if running on Windows system
    system("cls"); // not a good security best-practice!
    #else 
    system("clear"); // not recommended
    #endif
}

// wrapper function to test if two floating numbers are equal upto precision decimal points
void assertAlmostEqual(float value1, float value2, int precision) {
    ostringstream oss;
    // create output string stream with precision for floating-point values
    oss << fixed << setprecision(precision) << value1 << " " << value2;
    // create input string stream from output string stream
    istringstream iss(oss.str());
    float v1, v2;
    // extract the values as float
    iss >> v1 >> v2;
    assert(v1 == v2);
}