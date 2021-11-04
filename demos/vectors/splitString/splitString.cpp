#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

// Solution to Exercise 1
void splitString(vector<string> &words, string text) {
    string word;
    stringstream ss(text);
    while (ss >> word) {
        words.push_back(word);
    }
}

void test_splitString() {
    vector<string> answer;
    splitString(answer, "word");
    vector<string> actual = {"word"};
    assert(answer == actual);
    answer.clear();
    splitString(answer, "two word");
    vector<string> actual1 = {"two, word"};
    assert(answer == actual1);
    answer.clear();
    splitString(answer, "A sentence with multiple words!");
    vector<string> actual2 = {"A", "sentence", "with", "multiple", "words!"};
    assert(answer == actual2);
    answer.clear();
    cerr << "all test cases is passed for splitString()\n";
}

int main() {
    test_splitString();
    return 0;
}
