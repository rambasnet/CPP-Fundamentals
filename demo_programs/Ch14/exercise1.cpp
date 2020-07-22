// Sample solution for Exercise 1
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// linear search function that searches given key in given map
// returns true if key is found; false otherwise
bool searchMap(const map<char, int> m, char key) {
    auto find = m.find(key);
    return (find != m.end());
}

void test_searchMap() {
    assert(searchMap({{'a', 1}, {'b', 5}, {'!', 1}}, 'a') == true);
    assert(searchMap({{'q', 2}, {'Z', 1}}, 'm') == false);
    cerr << "all test cases passed for searchMap\n";
}

// function finds and returns frequency of each character
void letterFrequency(string text, map<char, int> & freq) {
    for (char ch: text) {
        ch = char(tolower(ch)); // make case insensitive
        // find each c in freq map
        if (searchMap(freq, ch)) // found
            freq[ch] += 1; // update frequency by 1
        else
            freq[ch] = 1; // add new element
    }
}

void test_letterFrequency() {
    map<char, int> ans;
    letterFrequency("Hi!", ans);
    map<char, int> expected = {{'!', 1}, {'h', 1}, {'i', 1}};
    assert(ans == expected);
    ans.clear();
    letterFrequency("Yo yO", ans);
    map<char, int> expected1 = {{' ', 1}, {'o', 2}, {'y', 2}};
    assert(ans == expected1);
    ans.clear();
    letterFrequency("Mississippi", ans);
    map<char, int> expected2 = {{'i', 4}, {'m', 1}, {'p', 2}, {'s', 4}};
    assert(ans == expected2);
    cerr << "all test cases passed for letterFrequency()\n";
}


int main(int argc, char * argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test_searchMap();
        test_letterFrequency();
    }
    else {
        cout << "Enter some text: ";
        string input;
        getline(cin, input);
        map<char, int> freqency;
        letterFrequency(input, freqency);
        // print elements of frequency map
        for(auto element:freqency) {
            cout << element.first << " => " << element.second << endl;
        }
    }

    return 0;
}