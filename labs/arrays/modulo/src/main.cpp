/*
Kattis - Module
Arrays Lab
Updated By: FIXME
CSCI 111
Date: FIXME

Read and solve the Kattis problem: https://open.kattis.com/problems/modulo

Algorithm Steps:
    1. Read 10 numbers into an array
    2. Create boolean array of size 42 to store the modulo 42 values (0-41)
      - initialize the array with false values
    3. For each of the 10 numbers:
      3.a find the number modulo 42 as an index and set the flag of the array at that index to true
    4. Go through the boolean array and count all true values
    5. Print the count of the true values to find the unique modulo 42 values
*/

#include <iostream>
#include <cassert>
#include "modulo.h"

using namespace std;
using ui = unsigned int;

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // create a dynamic unsigned int array of size 10 to store numbers
  ui *nums = new ui[10];
  // read 10 numbers into nums array
  read_data(nums, 10);
  // create a dynamic boolean array of size 42 to store num % 42 flags
  bool *flags = new bool[42];
  init_flags(flags, 42);
  update_flags(nums, flags, 10);
  // FIXME3 - call count_flags function passing proper
  // argument and print the result
  
  return 0;
}