/*
    CS1 - File IO Lab

    Updated by: FIXME1
    Date: FIXME2s 

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application. 
    Statistical value's definitions for mean, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const float EPSILON = 1e-6;

// function prototypes
void readData(vector<int> &);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
int findAverage(const vector<int> &); // mean
int findRange(const vector<int> &);
int findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, string inputFileName) {
    // FIXME: Open inputFileName for reading data
    // read the data until eof marker and store each num into numbers vector
    int num;
}

void writeData(const vector<int> & numbers) {
    // FIXME
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
}

int findMax(const vector<int> & nums) {
    int max = nums[0];
    for(int n: nums)
        max = (n>max) ? n : max;
}

int findMin(const vector<int> & nums) {
    // FIXME - implement function to find and return min value from nums vector
    return 0;
} 

int findAverage(const vector<int> & nums) {
    // same as mean
    long long int sum = 0;
    for(int n: nums)
        sum += n;
    return sum/float(nums.size());
}

int findRange(const vector<int> & nums) {
    // FIXME - implement function that finds and returns the range value
    // range = max - min
}

int findMedian(vector<int> nums) {
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0) {  // even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { // odd set
        median = nums[nums.size()/2];
    }
    return median;
}

void test() {
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    assert(abs(findMean(numbers)-125) <= EPSILON );
    assert(findMax(nums) == 100);
    // FIXME: Write test cases for other functions

    cerr << "all test cases passed!\n";
}