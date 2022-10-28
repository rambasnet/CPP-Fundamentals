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
using namespace std;

void readData(unsigned int *, size_t);
unsigned int getModulo42(const unsigned int);
void updateFlags(const unsigned int *, bool *, size_t);
size_t countFlags(const bool[], size_t);
void initFlags(bool *, size_t);
void testGetModulo42();
void testCountFlags();

int main(int argc, char* argv[])
{
  if (argc == 2 and string(argv[1]) == string("test")) {
    // FIXME1: call testGetModulo42()
    // FIXME2: call testCountFlags()
  }
  else {
    // create a dynamic unsigned int array of size 10 to store numbers
    unsigned int * nums = new unsigned int[10];
    // read 10 numbers into nums array
    readData(nums, 10); 
    // create a dynamic boolean array of size 42 to store num % 42 flags
    bool * flags = new bool[42];
    initFlags(flags, 42);
    updateFlags(nums, flags, 10);
    //FIXME3 - call countFlags function passing proper argument and print the result
  }
	return 0;
}

void readData(unsigned int * data, size_t arr_len) {
  for(int i=0; i<arr_len; i++) {
    cin >> data[i];
  }
}

void updateFlags(const unsigned int * numbers, bool * flags, size_t num_len) {
  unsigned int mod;
  for(int i=0; i<num_len; i++) {
    mod = getModulo42(numbers[i]);
    cerr << "mod = " << mod << endl;
    flags[mod] = true;
  }
}

unsigned int getModulo42(unsigned int num) {
  // FIXME4: return num modulo 42
  return 0;
}

void initFlags(bool * flags, size_t flags_len) {
  for(int i=0; i<flags_len; i++) {
    flags[i] = false;
  }
}

size_t countFlags(const bool flags[], size_t flags_len) {
  size_t count = 0;
  for (int i=0; i< flags_len; i++) {
    // FIXME5: if the flags at index i is set to true, increment count by 1
  }
  return count;
}

void testGetModulo42() {
  assert(getModulo42(41) == 41);
  assert(getModulo42(42) == 0);
  assert(getModulo42(43) == 1);
  // FIXME6: Write 3 more test cases
  cerr << "getModulo42(): All test cases passed!" << endl;
}

void testCountFlags() {
  bool * flags = new bool[42];
  initFlags(flags, 42);
  flags[getModulo42(42)] = true;
  flags[getModulo42(10)] = true;
  assert(countFlags(flags, 42) == 2);
  // reinitialize the flags array
  initFlags(flags, 42);
  flags[getModulo42(1)] = true;
  flags[420%42] = true;
  flags[43%42] = true;
  assert(countFlags(flags, 42) == 2);
  // FIXME7: write 3 more test cases
  cerr << "countFlags(): All test cases passed!" << endl;
}