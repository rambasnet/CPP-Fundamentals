// working with triangle using vector
// using functions to divide the solution to the problem
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// function prototypes
bool validTriangle(float side1, float side2, float side3);
void test_validTriangle();
float trianglePerimeter(const float side1, const float side2, const float side3);
void test_trianglePerimeter();
float triangleArea(const float side1, const float side2, const float side3);
void assertAlmostEqual(float value1, float value2, int precision);
void test_triangleArea();
void readTriangles(vector<vector<float> > & triangles);
void createReport(const vector< vector<float> > & tris);

void program();

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
    // store all the entered triangles into a vector
    vector< vector<float> > triangles;
    // read triangles data from file and store them into triangles vector
    readTriangles(triangles);
    createReport(triangles);
    cout << "Good bye...\n";
}

// function to check if 3 sides form a triangle
bool validTriangle(float side1, float side2, float side3) {
    // sum of every pair must be greater than the third
    return (side1+side2 > side3 && (side2+side3 > side1) && (side1+side3 > side2))? true: false;
}

void test_validTriangle() {
    assert(validTriangle(2, 3, 4) == true);
    assert(validTriangle(1, 2, 3) == false);
    assert(validTriangle(4, 5, 10) == false);
    cerr << "all test cases passed for validTriangle()\n";
}

// function prompts user to enter 3 sides of a triangle
// creates and returns a triangle
void getTriangle(float & side1, float & side2, float & side3) {
    // input validation
    do {
        cout << "Enter three sides of a triangle separated by space: ";
        cin >> side1 >> side2 >> side3;
        // check if three sides form a triangle
        if (!validTriangle(side1, side2, side3))
            cout << "3 sides do not form a traingle.\n"
                << "Sum of any 2 sides must be greater than the third!\n";
        else
            break;
    } while(true);
}

float trianglePerimeter(const float side1, const float side2, const float side3) {
    return side1 + side2 + side3;
}

// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    assert(trianglePerimeter(2, 3, 4) == 9);
    assert(trianglePerimeter(3, 4, 5) == 12);
    assert(trianglePerimeter(2.5, 3.5, 4.5) == 10.5);
    cerr << "all test cases passed for trianglePerimeter()\n";
}

// function to compute area of a triangle
float triangleArea(const float side1, const float side2, const float side3) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(side1, side2, side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

// wrapper function to test if two floating numbers are equal upto precision decimal points
void assertAlmostEqual(float value1, float value2, int precision) {
    ostringstream oss;
    // create output string stream with precision for floating-point values
    oss << fixed << setprecision(precision) << value1 << " " << value2;
    // create input string stream from output string stream
    istringstream iss(oss.str());
    float v1, v2;
    // extract the values as float
    iss >> v1 >> v2;
    assert(v1 == v2);
}

// write 3 test cases for triangleArea
void test_triangleArea() {
    assert(triangleArea(3, 4, 5) == 6.0);
    float area = triangleArea(2, 4, 5); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    assertAlmostEqual(triangleArea(3, 4, 6), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}

// function to calculate and print the result on triangle
void printAreaAndPerimeter(const float side1, const float side2, const float side3) {
    cout << "Triangle info: \n"
         << "3 sides length: " << side1 << " " << side2 << " " << side3
         << "\narea: " << triangleArea(side1, side2, side3) 
         << "\nperimeter: " << trianglePerimeter(side1, side2, side3) << endl;        
}

// function reads the triangles' information from a given fileName
// stores data into triangles vector
void readTriangles(vector<vector<float> > & triangles) {
    cout << "Enter databae file name that contains triangles' info: ";
    string fileName;
    getline(cin, fileName);
    // open the given file and read the data
    ifstream fin(fileName.c_str());
    if (! fin) {
        cerr << "File couldn't be opened\n"
            << "make sure " << fileName << " exists and you've permision to read it.";
        exit(EXIT_FAILURE);
    }
    // read and discard first line - header
    float side1, side2, side3;
    // read and discard the first line or heading
    string heading;
    getline(fin, heading);
    //cout << "heading = " << heading << endl;
    int count = 0;
    while(fin >> side1 >> side2 >> side3) {
        // check data was read correctly
        //printResult(temp);
        // check if the three sides form a triangle
        count++;
        if (! validTriangle(side1, side2, side3)) {
            cout << "Skipping invalid triangle with sides: " 
            << side1 << " " << side2 << " " << side3 << endl;
            continue;
        }
        // find area and perimeter of each triangle
        float area = triangleArea(side1, side2, side3);
        float perimeter = trianglePerimeter(side1, side2, side3);
        triangles.push_back(vector<float>{side1, side2, side3, area, perimeter});
    }
    cout << "Read " << triangles.size() << " out of " << count << " triangles from the file.\n";
    fin.close();
}

// print all the triangles on to the console
void createReport(const vector< vector<float> > & tris) {
    string fileName;
    cout << "Enter file name to write report to: ";
    getline(cin, fileName);
    ofstream fout(fileName.c_str());
    if (! fout) {
        cerr << "File couldn't be opened\n"
            << "make sure " << fileName << " exists and you've permision to read it.";
        exit(EXIT_FAILURE);
    }
    // write headers
    int colWidth = 65;
    fout << fixed << setprecision(2);
    fout << setw(colWidth) << setfill('=') << " " << setfill(' ') << endl;
    fout << "               Triangles Report \n";
    fout << setw(colWidth) << setfill('=') << " " << setfill(' ') << endl;
    colWidth = 10;
    fout << setw(colWidth) << "ID" << setw(colWidth) << "side 1"
        << setw(colWidth) << "side 2" << setw(colWidth) << "side 3" 
        << setw(colWidth) << "area" << setw(colWidth) << "perimeter" << endl;
    colWidth = 65;
    fout << setw(colWidth) << setfill('*') << " " << setfill(' ') << endl;
    // write data
    colWidth = 10;
    int ID = 1;
    for(const vector<float> & t: tris) {
        fout << setw(colWidth) << ID++;
        for(const float val: t)
            fout << setw(colWidth) << val;
        fout << endl;
    }
    colWidth = 65;
    fout << setw(colWidth) << setfill('*') << " " << setfill(' ') << endl;
    fout.close();
    cout << "the report file created successfully!\n";
}