/*==================================================
US Federal Election Voter Eligibility, v2
Author: Ram Basnet
Copyright: MIT License

Program determines if someone is eligible to vote in the US Federal Election

Algorithm steps:
1. get person's citizenship status
2. get person's age
3. determine voter eligibility
    - if the person is US citizen and their age is 18 or above they're eligible to vote
==================================================*/
#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

// function prototypes
void get_full_name(string &, string &);
string get_citizenship_status(const string &);
int get_age(const string &);
bool is_eligible_to_vote(const string &, const int &);
void test_is_eligible_to_vote();
void solution();

int main(int argc, char* argv[]) {
    // run test if test argument is passed to main
    if (argc == 2 && strncmp(argv[1], "test", 4) == 0)
        test_is_eligible_to_vote();
    else
        solution();

    // all done!
    return 0;
}

// function prompts user to enter their first name and last name
void get_full_name(string & fname, string & lname) {
    cout << "Hi there, enter your first name and last name: ";
    cin >> fname >> lname;
}

// function prompts user to enter and return their US citizenship status
string get_citizenship_status(const string & fname) {
    string status;
    cout << fname << ", are you a US citizen? Enter [y|yes] or [n|no]: ";
    cin >> status;
    return status;
}

// function prompts fname to enter their age and returns the same
int get_age(const string & fname) {
    int age;
    cout << fname << ", how old are you? ";
    cin >> age;
    return age;
}

// function determines whether someone is eligible to vote 
// in the US federal election
// return true if eligible, false otherwise
bool is_eligible_to_vote(const string & citizen, const int & age) {
    return ((citizen == "y" || citizen == "yes") && age >= 18) ? true : false;
}

// function to test is_eligible_to_vote()
void test_is_eligible_to_vote() {
    cerr << "running test cases...\n";
    assert(is_eligible_to_vote("y", 16) == false);
    assert(is_eligible_to_vote("no", 30) == false);
    assert(is_eligible_to_vote("y", 18) == true);
    assert(is_eligible_to_vote("yes", 100) == true);
    cerr << "all test cases passed for is_eligible_to_vote()\n";
}

void solution() {
    // variables to store persons's info
    string f_name, l_name, us_citizen;
    int age;
    // get user's full name
    get_full_name(f_name, l_name);
    cout << "Nice meeting you, " << f_name << '!' << endl;
    // 1. get citizenship status
    us_citizen = get_citizenship_status(f_name);
    // 2. get age
    age = get_age(f_name);
    // 3. determine the voting eligibility
    bool eligible = is_eligible_to_vote(us_citizen, age);
    if (eligible)
        cout << "Congrats, " << f_name << "! You're qualified to vote in the US federal election.\n";
    else
        cout << "Sorry, " << f_name << "! You're NOT qualified to vote in the US federal election.\n";
        
    cout << "Good bye... " << endl;
}