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
    vector<string> actual1 = {"two", "word"};
    assert(answer == actual1);
    answer.clear();
    splitString(answer, "A sentence with multiple words!");
    vector<string> actual2 = {"A", "sentence", "with", "multiple", "words!"};
    assert(answer == actual2);
    answer.clear();
    cerr << "Congrats! all test cases passed for splitString()\n";
}

// printVector function
template<class T>
void printVector(const vector<T>& v) {
    char comma[3] = {'\0', ' ', '\0'};
    cout << '[';
    for (const auto& e: v) {
        cout << comma << e;
        comma[0] = ',';
    }
    cout << "]\n";
}

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        test_splitString();
    else
    {
        string data;
        cout << "Enter some text: ";
        getline(cin, data);
        vector<string> tokens;
        splitString(tokens, data);
        printf("Resulting vector of words:\n");
        printVector<string>(tokens);
    }
    return 0;
}
