// unittesting fruitful functions
#include <iostream>
#include <cassert>

using namespace std;

// function adds two numbers and returns the sum
int addfunc(int num1, int num2) {
    return num1 + num2;
}

int main() {
  int answer;
  int num1, num2;
  num1 = 100;
  num2 = 1199;
  answer = addfunc(10, 5);
  cout << "answer = " << answer << endl;
  assert(answer == 15);
  cerr << "first assertion passed\n";
  // directly calling and testing function
  assert(addfunc(3, 7) == 10);
  cerr << "2nd assertion passed\n";
  // write 2 more test cases...
  assert(addfunc(-10, -5) == -15);
  assert(addfunc(-5, 5) == 0);
  assert(addfunc(num1, num2) == 1299);
  cerr << "all test cases passed!\n"; 
  return 0;
}