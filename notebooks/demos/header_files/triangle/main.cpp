// working with triangle using vector and fileio
// using functions as possible to break the problem
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>

// user-defined header files
#include "triangle.h"
#include "test.h"
#include "utility.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test" ) {
        // run all test cases
        test_validTriangle();
        test_trianglePerimeter();
        test_triangleArea();
        cerr << "all test cases passed!\n";
    }
    else
        program();
    
    return 0;
}

// complete program
void program() {
    Triangle t;
    string fileName;
    // store all the entered triangles into a vector
    vector<Triangle> triangles;
    int ID, option;
    cout << "Enter databae file name that contains triangles' info: ";
    getline(cin, fileName);
    // read data from file
    readTriangles(triangles, fileName);
    bool cont = true;
    int index;
    char ch;
    do {
        cout << "Enter C or c to continue...: ";
        cin >> ch;
        //clear();
        menu();
        cin >> option;
        switch (option) {
        case 1: // read triangle from a keyboard
            t = getTriangle();
            ID = triangles.size()+1;
            t.ID = ID;
            triangles.push_back(t);
            printTriangles(triangles);
            break;
        case 2: // display data
            printTriangles(triangles);
            break;
        case 3: // calculate area and perimeter
            printTriangles(triangles);
            cout << "Enter ID of the triangle: ";
            cin >> ID;
            index = searchTriangle(triangles, ID);
            if (index >= 0) // found
                computeAreaAndPerimeter(triangles[index]);
            else
                cout << "Triangle NOT found with the given ID " << ID << endl;
            break;
        case 4: // write data to file
            writeTriangles(triangles, fileName);
            break;
        case 5: // sort data
            sort(triangles.begin(), triangles.end(), smaller);
            printTriangles(triangles);
            break;
        case 6: // sort in non-increasing order
            sort(triangles.begin(), triangles.end(), larger);
            printTriangles(triangles);
            break;
        case 7:
            cont = false;
            break;
        default:
            cont = false;
            break;
        }
    } while(cont);
    cout << "Would you like to save database? Enter [y|n] ";
    cin >> ch;
    if (ch == 'y') {
        writeTriangles(triangles, fileName);
    }
    cout << "Good bye...\n";
}

void menu() {
    cout << "Menu options to work with Triangles:\n"
        << "1. Read triangle from keyboard\n"
        << "2. Display all triangles\n"
        << "3. Calculate area and perimeter\n"
        << "4. Update database\n"
        << "5. Sort triangles based on area in increasing order\n"
        << "6. Sort triangles based on area in non-increasing order\n"
        << "7. Exit the program\n"
        << "Enter your choice [1-7]: ";
}