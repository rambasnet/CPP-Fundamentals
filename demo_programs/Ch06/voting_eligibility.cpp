/*==================================================
US Federal Election Voter Eligibility
Author: Ram Basnet
Copyright: MIT License

Program determines if someone is eligible to vote in the US Federal Election

Algorithm steps:
1. get person's citizenship status
2. get person's age
3. determine voter eligibility
    - if the person is US citizen and their age is 18 and above they're qualified to vote
==================================================*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // variables to store persons's info
    string f_name, l_name, us_citizen;
    int age;
    // greet the user
    cout << "Hello there, what's your first and last name? ";
    cin >> f_name >> l_name;
    cout << "Nice meeting you, " << f_name << '!' << endl;
    // 1. get citizenship status
    cout << f_name << ", are you a US citizen? Enter [y|yes] or [n|no]: ";
    cin >> us_citizen;
    // 2. get age
    cout << f_name << ", how old are you? ";
    cin >> age;
    // 3. determine the voting eligibility
    if ((us_citizen == "y" || us_citizen == "yes") && age >= 18)
        cout << "Congrats, " << f_name << "! You're qualified to vote in the US federal election.\n";
    else
        cout << "Sorry, " << f_name << "! You're NOT qualified to vote in the US federal election.\n";
        
    cout << "Good bye... " << endl;

    // all done!
    return 0;
}