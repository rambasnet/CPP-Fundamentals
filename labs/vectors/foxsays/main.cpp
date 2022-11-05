/*
Kattis - What does the fox say?
Vector Lab
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve the Kattis problem: https://open.kattis.com/problems/whatdoesthefoxsay   

Algorithm Steps:
	1. For each test case do the following:
    i. Read all the recorded sounds into a vector
    ii. Read individual animal sound until 'What does the fox say?' line
      a) Erase all the matching animal sounds from the recorded sounds vector
    iv. Print the sounds that's left in the recorded sounds vector
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// function prototypes
void solve();
// function splits given string into vector of words
void splitString(vector<string> &, string);
// function erases sound from recordings vector
void eraseAnimalSound(vector<string> &, string);
// function returns what the fox says
string foxSays(vector<string> &);
// function tests eraseAnimalSound function
void test_eraseAnimalSound();
// function tests splitString function
void test_splitString();
// function tests foxSays function
void test_foxSays();
// function calls all test functions
void unit_test();

int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == string("test")) {
    // FIXME1: call unit_test function
  }
  // read the total number of test cases
  else
    solve();
  return 0;
}

void solve() {
  size_t T;
  cin >> T >> ws; // read the number of test cases and discard the newline
  
  while(T--) {
    cerr << "T = " << T << endl;
    vector<string> recordings;
    string sounds, animal_sound;
    getline(cin, sounds);
    cerr << sounds << endl;
    splitString(recordings, sounds);
    // read and parse animal sounds
    // don't know how many animals are there
    
    while (true) {
      getline(cin, animal_sound);
      // check for the question
      if (animal_sound == "what does the fox say?") break;
      istringstream iss(animal_sound);
      string animal, goes, sound;
      // parse three words
      iss >> animal >> goes >> sound;
      eraseAnimalSound(recordings, sound);
    }
    // FIXME2: call foxSays function and print the returned answer
  }
}

string foxSays(vector<string> &recordings) {
  // return the answer string
  ostringstream oss;
  bool first = true;
  for(int i=0; i<recordings.size(); i++) {
    if (first) {
      oss << recordings[i];
      first = false;
    }
    else
      oss << " " << recordings[i];
  }
  return oss.str();
}

void splitString(vector<string> &words, string text) {
    string word;
    stringstream ss(text);
    while (ss >> word) {
        words.push_back(word);
    }
}

void eraseAnimalSound(vector<string> &recordings, string sound) {
  // see how erase works here: https://en.cppreference.com/w/cpp/container/vector/erase 
  // FIXME3 - use iterator to erase all matching sound
  // if iterator points to sound, erase it and update it with the next element pointer
  // otherwise, just increment the iterator
}

void test_splitString() {
  vector<string> answer;
  splitString(answer, "word");
  vector<string> expected = {"word"};
  assert(answer == expected);
  answer.clear();
  splitString(answer, "two word");
  vector<string> expected1 = {"two", "word"};
  assert(answer == expected1);
  // FIXME4: add 2 more test cases
  cerr << "splitString(): All test cases passed!)\n";
}

void test_eraseAnimalSound() {
  vector<string> recordings = {"bo", "boo", "meow", "bo", "ba", "wooon", "bo"};
  eraseAnimalSound(recordings, "bo");
  vector<string> expected = {"boo", "meow", "ba", "wooon"};
  assert(recordings == expected);
  // FIXME5: add 2 more test cases
  cerr << "eraseAnimalSound(): All test cases passed!" << endl;
}

void test_foxSays() {
  vector<string> recordings = {"bo", "boo", "meow", "bo", "ba", "wooon", "bo"};
  eraseAnimalSound(recordings, "bo");
  // after animal sounds are deleted
  string ans = foxSays(recordings);
  cerr << "ans = " << ans << endl;
  assert(ans == "boo meow ba wooon");
  // FIXME6: add 2 more test cases
  cerr << "foxSays(): All test cases passed!" << endl;
}

void unit_test() {
  test_splitString();
  test_eraseAnimalSound();
  test_foxSays();
  cerr << "All unit tests passed!" << endl;
}