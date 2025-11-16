#include <cmath>
#include "my_math.h"
using namespace std;

float square_root(float x)
{
    return sqrt(x);
}

float cube_root(float x)
{
    return cbrt(x);
}

float power_of_ten(float x)
{
    return pow(10, x);
}

float log_base_2(float x)
{
    return log2(x);
}

float log_base_10(float x)
{
    // FIXME1 - implement function using standard library to find and return log base 10 of x
    return 0.0;
}

float degree_to_radian(float degree)
{
    return degree * (M_PI / 180.0);
}

float sine_of_radian(float radian)
{
    // FIXME2 - implement function using standard library to find and return sine of the given radian value
    return 0.0;
}

float cosine_of_radian(float radian)
{
    // FIXME3 - implement function using standard library to find and return cosine of the given radian value
    return 0.0;
}
