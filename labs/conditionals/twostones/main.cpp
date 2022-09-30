/*
Kattis - Take Two Stones
Conditional Logic Lab
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve the Kattis problem: https://open.kattis.com/problems/twostones 

Algorithm Steps:
  1. Read the number of stones
  2. Check if the number of stones is odd or even
  3.a. If the number is odd, Alice wins.
  3.b. Otherwise, Bob wins.
*/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// Function prototypes
// given a positive integer, the function finds and returns 'even' or 'odd'
string oddOrEven(const int unsigned);
// function to test oddOrEven function
void testOddOrEven();
// given a positive integer, function returns the answer as expected by Kattis
string answer(const int unsigned);

int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == string("test")) {
    // FIXME1: call testOddOrEven function that unit tests oddOrEven function
    // FIXME2: call the test function that unit tests answer function
  }
  else {
    unsigned int stones=0;
    // FIXME3: readin the stones
    cout << answer(stones) << endl;
  }
  return 0;
}

string oddOrEven(const int unsigned number) {
  // FIXME4: if the number divided by 2 has 0 remainder, return 'even'
  // otherwise, return 'odd'
  return "odd";
}

string answer(const int unsigned stone) {
  string evenorodd = oddOrEven(stone);
  if (evenorodd == "odd") return "Alice";
  else return "Bob";
}

void testOddOrEven() {
  int unsigned number;
  number = 99999;
  assert(oddOrEven(number) == "odd");
  // FIXME5: Write 2nd test case
  // FIXME6: Write 3rd test case
  cerr << "All test cases passed for oddOrEven() !\n";
}

// FIXME7: Write a function to test answer function
// Write at least 3 test cases
