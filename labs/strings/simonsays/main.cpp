/*
Kattis - Simon Says

Updated By: FIXME
Date: FIXME

Problem Statement: https://open.kattis.com/problems/simonsays 
Algorithm steps:
1. Read N
2. Loop N times:
  i. Read a line
  ii. If the line starts with "Simon says",
    print the rest of the string. Note: print the leading space after says as well!
  iii. Otherwise, skip the line
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == "test") {
    // FIXME1: call testAnswer function
  }
  else
    solve();
}

string answer(const string &line) {
  // FIXME2: If the line starts with "Simon says", return rest of the line after says
  // including the space after says, otherwise return empty string ""
  // Hint: use find method on line object
  return "";
}

// unit testing answer()
void testAnswer() {
  string ans = answer("Simon says laugh!");
  // let's double check what the returned answer is
  cerr << "ans = " << ans << endl;
  assert(ans == " laugh!"); 
  assert(answer("Write more programs.") == "");
  // FIXME3: write at least two test cases to test answer()
  cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
  string ans="", line="";
  int N;
  cin >> N;
  //FIXME4 : read and discard \n left behind
  while (N--) {
    // Note: i. string consists of phrase with spaces
    // ii. don't print an empty line if the line doesn't start with "Simon says"
    // FIXME5: read the whole line into line 
    // FIXME6: call answer function and store the returned value into ans
    if (ans == "") continue;
    // FIXME7: print ans
  }
}
