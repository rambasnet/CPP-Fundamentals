/*
    CS1 - File IO Lab

    Updated by: FIXME
    Date: FIXME

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application.
    Statistical value's definitions for mean, median, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const float EPSILON = 1e-4; // accuracy upto 4 decimal points

// function prototypes
void read_data(vector<int> &, const string);
int find_max(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); // average
int findRange(const vector<int> &);
float findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void write_data(const vector<int> &numbers);
void test();

int main(int argc, char *argv[])
{
    if (argc == 2 && string(argv[1]) == "test")
    {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    read_data(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void read_data(vector<int> &numbers, const string inputFileName)
{
    // FIXME1: Open inputFileName for reading data
    // read the data until eof marker and store each num into numbers vector
    int num;
}

void write_data(const vector<int> &numbers)
{
    // FIXME2
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
}

int find_max(const vector<int> &nums)
{
    int max = nums[0];
    for (int n : nums)
        max = (n > max) ? n : max;
    return max;
}

int find_min(const vector<int> &nums)
{
    // FIXME3 - implement function to find and return min value in nums vector
    return 0;
}

float find_mean(const vector<int> &nums)
{
    // same as average
    long long int sum = 0;
    for (int n : nums)
        sum += n;
    return sum / float(nums.size());
}

int find_range(const vector<int> &nums)
{
    // FIXME6 - implement function that finds and returns the range value
    // range = max - min
    return 0;
}

float find_median(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0)
    { // even set
        median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / float(2);
    }
    else
    { // odd set
        median = nums[nums.size() / 2];
    }
    return median;
}

void test()
{
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    // cout << find_mean(numbers) << " " << find_mean(numbers)-17.857142 << endl;
    assert(fabs(find_mean(numbers) - 17.857142) <= EPSILON);
    assert(find_max(numbers) == 100);
    assert(find_median(numbers) == 10);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(find_mean(numbers1) - 1.6667) <= EPSILON);
    assert(find_max(numbers1) == 10);
    assert(find_median(numbers1) == 5);
    // FIXME7: Write at least two test cases for other functions

    cerr << "all test cases passed!\n";
}