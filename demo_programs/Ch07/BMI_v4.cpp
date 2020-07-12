/*==================================================
BMI Calculator, v4 - calculates for multiple clients
Author: Ram Basnet
Copyright: MIT License

Program finds Body Mass Index (BMI) of a person.

Algorithm steps:
1. get person's height
  - convert height into inches
2. get person's weight in pounds (lbs)
3. calculate BMI using formula: 
    - BMI = 703 x weight (lbs) / [height (in)]^2
4. display the result
5. interpret the result as:
    Underweight <18.5
    Normal weight 18.5–24.9
    Overweight 25–29.9
    Obesity BMI of 30 or greater

==================================================*/
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define INCHES_IN_FOOT 12

// function prototypes
int feet_to_inches(int, int);
float compute_BMI(int height_in_inches, float weight_in_lbs);
void test_feet_to_inches();
void test_compute_BMI();
string BMI_result(float);
void test_BMI_result();
void test_all();
void compute();

int main(int argc, char* argv[]) {
    // run automated tests for most functions that compute
    if (argc == 2 && string(argv[1]) == "test") {
       test_all();
    }
    else {
        string ans;
        do {
            compute();
            cout << "Would you like to enter another patient's info?\n"
                << "Enter [y|yes] to continue; anything else to quit the program: \n";
            cin >> ans;
            if (ans == "yes" or ans == "y") continue;
            else break;

        } while(true);
        cout << "Thank you for using BMI Calculator!\nGood bye..." << endl;
    }

    // all done!
    return 0;
}

// function converts given feet and inches into inches
// returns inches
int feet_to_inches(int feet, int inches) {
    int total_inches = feet*INCHES_IN_FOOT + inches;
    return total_inches;
}

// function that computes and returns BMI given height(in) and weight(lbs)
float compute_BMI(int height_in_inches, float weight_in_lbs) {
    return 703*weight_in_lbs/(height_in_inches*height_in_inches);
}

// function to test feet_to_inches()
void test_feet_to_inches() {
    assert(feet_to_inches(5, 0) == 60);
    assert(feet_to_inches(5, 6) == 66);
    assert(feet_to_inches(5, 11) == 71);
    assert(feet_to_inches(6, 1) == 73);
    cerr << "all test cases for feet_to_inches() passed.\n";
}

// unittesting for compute_BMI
// since BMI is a float value; we'll accept answer as valid upto 1 decimal point
void test_compute_BMI() {
    float BMI = compute_BMI(66, 160);
    // round BMI to 2 decimal points using string stream library
    ostringstream oss;
    // manipulate the floating point value
    oss << fixed << setprecision(1);
    oss << BMI;
    assert(oss.str() == "25.8");
    // clear oss with empty string
    oss.str("");
    oss << compute_BMI(60, 125);
    //cout << oss.str() << endl;
    assert(oss.str() == "24.4");
    oss.str("");
    oss << compute_BMI(72, 180);
    assert(oss.str() == "24.4");
    cerr << "all test cases for compute_BMI() passed.\n";
}

// given BMI the function returns the iterpretation in English
string BMI_result(float BMI) {
    if (BMI < 18.5)
        return "Underweight";
    else if(BMI >= 18.5 && BMI <= 24.9)
        return "Normal weight";
    else if(BMI >= 25 && BMI <= 29.9)
        return "Overweight";
    else
        return "Obesity";
}

// function that test BMI_result()
void test_BMI_result() {
    assert(BMI_result(18) == "Underweight");
    assert(BMI_result(22.9) == "Normal weight");
    assert(BMI_result(29.9) == "Overweight");
    assert(BMI_result(30) == "Obesity");
    cerr << "all test cases passed for BMI_result()\n";
}

// function that calls all individual test functions
void test_all() {
    test_feet_to_inches();
    test_compute_BMI();
    test_BMI_result();
}

void compute() {
    // variables to store persons's info
    string f_name, l_name;
    int feet, inches, height_in_inches;
    float weight_in_pounds, BMI;
    // greet the user
    cout << "Enter patient's first and last name? ";
    cin >> f_name >> l_name;
    // 1. get height
    cout << f_name << ", what is their height?\n"
        << "\tEnter feet inches, e.g. if you're 5' 6\", enter 5 6: ";
    cin >> feet >> inches;
    // 1.a convert height into inches
    height_in_inches = feet_to_inches(feet, inches);
    // 2. get weight in lbs
    cout << f_name << ", now enter their weight in lbs: ";
    cin >> weight_in_pounds;
    // 3. calculate BMI
    BMI = compute_BMI(height_in_inches, weight_in_pounds);
    cout << "BMI report card\n";
    cout << "=======================\n";
    cout << fixed << setprecision(1);
    cout << "Name: " << f_name << " " << l_name << endl;
    cout << "Height: " << feet << "' " << inches << "\"\n";
    cout << "Weight: " << weight_in_pounds << " lbs" << endl;
    cout << "BMI: " << BMI << " -> " << BMI_result(BMI) << endl;
    cout << "=======================\n";
}