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
#include "helper.h"

using namespace std;

int main()
{
	string input = "input";
	// step1. read data
	input = read_data();
	// FIXME1: Call twilight function passing input as an argument
	// store the returned result into answer variable
	string answer = twilight(input);
	// print answer
	printf("%s\n", answer.c_str());
	return 0;
}

// Function implementation
string read_data()
{
	string input;
	// FIXME2: using getline read and store the data into input variable
	// FIXME3 return input data
	return "FIXME";
}
