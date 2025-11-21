/*
Kattis No Stragglers Problem
Loops and Unit Testing with Doctest
Updated By: FIXME
CSCI 111
Date: FIXME
Read and solve No Stragglers problem from Kattis: https://open.kattis.com/problems/nostragglers
Algorithm:
    1. Read the number of entries/exits to process
    2. For each entry, read the type student/visitor/faculty, in/out, and count
    3. Update the respective counts based on type and in/out using update_count function
    4. Calculate the total number of stragglers using total_stragglers function
    5. Print "NO STRAGGLERS" if total is zero, otherwise print the total
    6. Write test functions to test the utility fruitful functions
*/

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int main()
{
    // FIXME1: Fast input/output; try with and without these two lines
    // comment out and run to observe any difference in execution time
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n = 0, count = 0;
    int stu = 0, vis = 0, fac = 0;
    string type, in_out;
    cin >> n;
    char t, io;
    // FIXME2: Read n entries using a loop and update counts accordingly
    {
        cin >> type >> in_out >> count;
        t = type[0];    // use first character of the string
        io = in_out[0]; // use first character of the string
        // FIXME3: Call update_count function to update the counts
    }

    int total = 0; // FIXME4: Call total_stragglers function to get the total count
    if (total == 0)
        cout << "NO STRAGGLERS" << endl;
    else
        cout << total << endl;
    return 0;
}