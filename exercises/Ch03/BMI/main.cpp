/*==================================================
BMI Calculator
Author: Ram Basnet
Copyright: MIT License

Program finds Body Mass Index (BMI) of a person

Algorithm steps:
1. get person's height
  - convert height into inches
2. get person's weight in pounds (lbs)
3. calculate BMI using formula: 
    - BMI = 703 x weight (lbs) / [height (in)]^2
4. display the result
5. interpret the result as:
    Underweight = <18.5
    Normal weight = 18.5–24.9
    Overweight = 25–29.9
    Obesity = BMI of 30 or greater

==================================================*/
#include <iostream>
#include <string>

using namespace std;

#define INCHES_IN_FOOT 12

int main() {
    // variables to store persons's info
    string f_name, l_name;
    int feet, inches, height_in_inches;
    float weight_in_pounds, BMI;
    // greet the user
    cout << "Hello there, what's your first and last name? ";
    cin >> f_name >> l_name;
    cout << "Nice meeting you, " << f_name << '!' << endl;
    // 1. get height
    cout << f_name << ", what is your height?\n"
        << "\tEnter feet inches, e.g. if you're 5'6\", enter 5 6: ";
    cin >> feet >> inches;
    // 1.a convert height into inches
    height_in_inches = feet*INCHES_IN_FOOT + inches;
    // 2. get weight in lbs
    cout << f_name << ", now enter your weight in lbs: ";
    cin >> weight_in_pounds;
    // 3. calculate BMI
    BMI = 703*weight_in_pounds/(height_in_inches*height_in_inches);
    cout << "Your BMI report card\n";
    cout << "=======================\n";
    cout << "Name: " << f_name << " " << l_name << endl;
    cout << "Height: " << feet << "'" << inches << "\"\n";
    cout << "Weight: " << weight_in_pounds << " lbs" << endl;
    cout << "BMI: " << BMI << endl;
    cout << "=======================\n";
    // FIXME: step #5

    cout << "Thank you for using my BMI Calculator, " << f_name << "!\nGood bye..." << endl;

    // all done!
    return 0;
}