/*
Map Lab
Kattis - Morse Code Palindromes

Updatd By: FIXME
Date: FIXME

Solution to Morse Code Palindromes Problem: https://open.kattis.com/problems/morsecodepalindromes
Algorithm steps:
1. Creae a map of char to morse code
2. Read in a string
3. Convert the string to morse code
   i. for each char in string, find its morse code in map
   ii. append morse code to a string if char key is found
4. Check if morse code is a palindrome
  i. compare first and last char
  ii. if they are the same, compare second and second last char
  iii. if they are the same, compare third and third last char
  iv. repeat until all chars are compared until mid index or a mismatch is found
5. Print 1 if morse code is a palindrome, 0 otherwise
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <map>
#include <string>
#include <cstring>

using namespace std;

// Algorithm step 1
map<char, string> morseCode = {
	{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
	{'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
	{'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
	{'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
	{'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
	{'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
	{'8', "---.."}, {'9', "----."}, 
};

// function prototypes
string convertToMorse(const string&);
bool isPalindrome(const string&);
void testConvertToMorse();
void testIsPalindrome();
void solve();
void unittest();

int main(int argc, char* argv[]) {
	if (argc == 2 and string(argv[1]) == "test")
		unittest();
	else
		solve();
}

// solving the problem for kattis
void solve() {
	string phrase, morse;
	// string is a phrase: with space, puncuation, lower and uppercase letters
	// FIXME1 - step 2
	// read english phrase into phrase variable
	// FIXME2 - step 3 
	// convert phrase to morse code
	// FIXME3 - step 4
	// check if morse code is a palindrome calling isPalindrome function
	// FIXME4 - step 5
	// print 1 if it is a palindrome, 0 otherwise
}

// function definitions
string convertToMorse(const string& phrase) {
	string morse = "";
	// convert phrase to morse code
	// for each char in phrase, convert char to uppercase, find its morse code in morseCode map
	// append morse code to a string if char key is found
	for (char c : phrase) {
		c = char(toupper(c));
		// FIXME5 - find morse code for char c in morseCode map and append it to morse string
	}
	return morse;
}

bool isPalindrome(const string& morse) {
	// FIXME6 - check if morse code is a palindrome
	// return true if it is a palindrome, false otherwise
	// Algorithm step: 
		// compare first and last char
		// if they are the same, compare second and second last char
		// if they are the same, compare third and third last char
		// repeat until all chars are compared until mid index or a mismatch is found
		// NOTE: empty morse code is not a palindrome!
	return true;
}

void testConvertToMorse() {
	assert(convertToMorse("A") == ".-");
	assert(convertToMorse("9") == "----.");
	assert(convertToMorse("Aa") == ".-.-");
	cerr << convertToMorse("AaBb") << endl;
	assert(convertToMorse("AaBb") == ".-.--...-...");
	assert(convertToMorse("Race car!") == ".-..--.-..-.-..-.-.");
	assert(convertToMorse("1881") == ".-------..---...----");
	// FIXME7 - add 3 more test cases
}

void testIsPalindrome() {
	string morse = convertToMorse("A");
	assert(isPalindrome(morse) == true);
	morse = convertToMorse("AaBb");
	assert(isPalindrome(morse) == false);
	morse = convertToMorse("Race car!");
	assert(isPalindrome(morse) == true);
	morse = convertToMorse("1881");
	assert(isPalindrome(morse) == true);
	// FIXME8 - add 3 more test cases
}

// unit testing all functions
void unittest() {
  // FIXME9 - call all unit test functions
  cerr << "All unittests passed!\n";
}