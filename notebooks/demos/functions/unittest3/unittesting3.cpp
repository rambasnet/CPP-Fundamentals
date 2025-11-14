// unittesting void functions and floating point results
// void function that writes result to a reference parameter
// NOTE - floating point computation may not be precisely accurate!
// Run the program as it is (test fails!)
// FIXME: change type of paramter in product function to double for double precision!
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// function prototypes
void product(float, float, float &);
void test_product(void);

const double tolerance = 1e-1;

int main() {
  // call test function
  test_product();
  // FIXME: make the program useable by any user...
  return 0;
}

// function multiplies given two numbers and finds the product
// stores the result in product reference variable 
void product(float n1, float n2, float &result) {
  result = n1 * n2;
  // no return!
}

void test_product(void) {
  float answer;
  float num1, num2;
  num1 = 10.0;
  num2 = 20.0;
  product(10.0, 20.0, answer);
  assert(answer == 200);
  num1 = 100.1234;
  num2 = 1199.14556;
  double expected = 120062.530562;
  product(num1, num2, answer);
  // let's print the answer to see what it is
  // let's print some decimal values
  cerr << "answer = " << fixed << setprecision(6) << answer << endl;
  assert(fabs(answer-expected) <= tolerance);
  // the following assert will fail!
  // try: https://www.wolframalpha.com/input/?i=100.1234+*+1199.14556
  // try: https://www.google.com/search?q=100.1234*1199.14556&oq=100.1234*1199.14556
  // expected answer is provided by google and wolfram alpha
  assert(answer == expected);

  cerr << "all test cases passed!\n"; 
}