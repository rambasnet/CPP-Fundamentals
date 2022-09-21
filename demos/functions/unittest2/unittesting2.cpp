// unittesting fruitful functions, v.2
// a better way using function to write all the test cases
#include <iostream>
#include <cassert>

using namespace std;

// templated add function
template<class T1, class T2, class T3>
T1 add(T2, T3);

void test_add();

int main() {
  // do automatic testing of addfunc
  test_add();
  // manual testing
  long answer;
  int n1, n2;
  cout << "Enter two integers separated by space: ";
  cin >> n1 >> n2;
  // calculate answer
  answer = add<long, int, long>(n1, n2);
  cout << n1 << " + " << n2 << " = " << answer << endl;
  cout << "All done... Good bye!\n";
  return 0;
}

// function adds two numbers and returns the sum
template<class T1, class T2, class T3>
T1 add(T2 para1, T3 para2) {
  return para1 + para2;
}

void test_add() {
  // test add
  // Note: cannot call template function directly inside the assert
  long ans = add<long, int, long>(10, 20);
  assert(ans == 30);
  ans = add<long, int, int>(99, 1);
  assert(ans == 100);
  float ans2 = add<float, int, float>(10, 20.5);
  assert(ans2 == 30.5); 
  string ans3 = add<string, string, string>("Hello", " World");
  assert(ans3 == "Hello World");
  cerr << "all test cases passed!\n";
}