/*
Kattis - The Last Problem
User-defined functions and Library Functions Lab
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve The Last Problem: https://open.kattis.com/problems/thelastproblem

Algorithm:
		1. Read the input string
		3. Create the output as asked and print it
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
using namespace std;

// Function prototypes
// Function finds the answer from given string and restuns the result as a string
string twilight(const string&);
// Function reads the data from standard input and returns the data
string readData();

int main()
{
	string input = "input";
	// step1. read data
	input = readData();
	// FIXME1: Call twilight function passing input as an argument
	// store the returned result into answer variable
	string answer = input;
	// print answer
	printf("%s\n", answer.c_str());
	return 0;
}

// Function implementation
string readData() {
	string input;
	// FIXME2: using getline reade and store the data into input variable
	// FIXME3 return input data
	return "FIXME";
}

// Function implementation
string twilight(const string& input) {
	string ans = "Thank you, " + input + ", and farewell!";
	return ans;
} 
