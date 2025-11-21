/*
Kattis M-Climb Road Problem
Function and Unit Testing with Doctest
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve M-Climb Road problem from Kattis: https://open.kattis.com/problems/mclimbroad
Algorithm:
    1. Read the number of miles to be climbed and number of students
    2. Convert miles to feet using the conversion factor (1 mile = 5280 feet)
    3. Calculate the number of times each student will be squirted with a water gun
       by dividing total feet by number of students
    4. Print the result
    5. Write test functions to test the conversion and calculation functions
*/

#include <iostream>
#include "util.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int road_len = 0, stu_gun = 0;
    // FIXME1: Read input values into road_len and stu_gun
    road_len = convert_miles_to_feet(road_len);
    cout << calculate_answer(road_len, stu_gun) << endl;
    return 0;
}
