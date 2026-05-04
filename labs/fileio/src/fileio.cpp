#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iterator>
#include <algorithm>
#include "fileio.hpp"
using namespace std;

int read_data(int *numbers, const string input_file)
{
    // FIXME1: Open input_file for reading data
    // read the data until eof marker and store each num into numbers array
    // return the number of integers read from the file or the first integer
    // in the file which represents the number of integers to read
    
    int array_len = 0;
    return array_len;
}

void write_data(const int *numbers, size_t array_len)
{
    // FIXME2
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
    
}

int find_max(const int *nums, size_t array_len)
{
    // Implement function to find and return maximum value in nums array
    int max = nums[0];
    for (int i = 0; i < array_len; ++i)
        max = (nums[i] > max) ? nums[i] : max;
    return max;
}

int find_min(const int *nums, size_t array_len)
{
    // FIXME3 - implement function to find and return minimum value in nums array
    return 0;
}

float find_mean(const int *nums, size_t array_len)
{
    // same as average
    long long int sum = 0;
    for (int i = 0; i < array_len; ++i)
        sum += nums[i];
    return sum / float(array_len);
}

int find_range(const int *nums, size_t array_len)
{
    // FIXME6 - implement function that finds and returns the range of the numbers in nums array.
    // Range is defined as the difference between maximum and minimum values in the array.
    return 0;
}

float find_median(int *nums, size_t array_len)
{
    // Find the median of the numbers in nums array.
    // Median is defined as the middle value when the numbers are sorted in order.
    // If there is an even number of values, the median is the average of the two middle values.
    sort(nums, nums + array_len);
    float median;
    if (array_len % 2 == 0)
    { // even set of numbers
      // median = average of middle two numbers
        median = (nums[array_len / 2 - 1] + nums[array_len / 2]) / 2.0;
    }
    else
    { // odd set
        median = nums[array_len / 2];
    }
    return median;
}
