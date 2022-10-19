/*
Kattis - Hissing Microphone Problem

Updated By: FIXME1
Date: FIXME2

Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read a string
2. Search for "ss" substring in the string
    i. if found, print "hiss"
    ii. otherwise, print "no hiss"
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
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

string answer(const string &line) {
    // FIXME3 - implement algorithm in step 2
    // return "hiss" if ss is found in line
    // otherwise, return "no hiss"
    return "hiss";
}

// unit testing answer()
void testAnswer() {
    // FIXME4 - write at least two test cases to test answer()
    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;
    // Note: string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5 - read string into line
    cout << answer(line) << endl;
}
