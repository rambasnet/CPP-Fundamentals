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

using namespace std;

// clear function that is system independent
// NOTE: system call is not a best practice
void clear() {
    #ifdef _WIN32 // if running on Windows system
    system("cls"); // not a good security best-practice!
    #else 
    system("clear"); // not recommended
    #endif
}

// use struct to represent Triangle
struct Triangle {
    int ID;
    float side1, side2, side3;
};

// function prototypes
bool validTriangle(float s1, float s2, float s3);
void test_validTriangle();
Triangle getTriangle();
float trianglePerimeter(const Triangle & t);
void test_trianglePerimeter();
float triangleArea(const Triangle & t);
void assertAlmostEqual(float value1, float value2, int precision);
void test_triangleArea();
void computeAreaAndPerimeter(const Triangle & t);
void program();
void menu();
void readTriangles(vector<Triangle> &, const string &);
void writeTriangles(const vector<Triangle> &, const string &);

int searchTriangle(const vector<Triangle> &, int);
bool smaller(const Triangle & t1, const Triangle & t2);
bool larger(const Triangle & t1, const Triangle & t2);
void printTriangles(const vector<Triangle> & tris);

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

// function to check if 3 sides form a triangle
bool validTriangle(float s1, float s2, float s3) {
    // sum of every pair must be greater than the third
    return (s1+s2 > s3 && (s2+s3 > s1) && (s1+s3 > s2))? true: false;
}

void test_validTriangle() {
    assert(validTriangle(2, 3, 4) == true);
    assert(validTriangle(1, 2, 3) == false);
    assert(validTriangle(4, 5, 10) == false);
    cerr << "all test cases passed for validTriangle()\n";
}

// function prompts user to enter 3 sides of a triangle
// creates and returns a triangle
Triangle getTriangle() {
    float s1, s2, s3;
    // input validation
    do {
        cout << "Enter three sides of a triangle separated by space: ";
        cin >> s1 >> s2 >> s3;
        // check if three sides form a triangle
        if (!validTriangle(s1, s2, s3))
            cout << "3 sides do not form a traingle.\n"
                << "Sum of any 2 sides must be greater than the third!\n";
        else
            break;
    } while(true);
    return Triangle({0, s1, s2, s3});
}

float trianglePerimeter(const Triangle & t) {
    return t.side1 + t.side2 + t.side3;
}

// write 3 test cases for trianglePerimeter
void test_trianglePerimeter() {
    assert(trianglePerimeter(Triangle({0, 2.0f, 3.0f, 4.0f})) == 9.0f);
    assert(trianglePerimeter(Triangle({0, 3.0f, 4.0f, 5.0f})) == 12.0f);
    assert(trianglePerimeter(Triangle({0, 2.5f, 3.5f, 4.5f})) == 10.5f);
    cerr << "all test cases passed for trianglePerimeter()\n";
}

// function to compute area of a triangle
float triangleArea(const Triangle & t) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(t)/2;
    return sqrt(s*(s-t.side1)*(s-t.side2)*(s-t.side3));
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
    assert(triangleArea(Triangle({0, 3, 4, 5})) == 6.0);
    float area = triangleArea({0, 2, 4, 5}); // coersion of 3 values into Triangle type
    assertAlmostEqual(area, 3.799671038392666, 4); // accuracy upto 4 decimal points
    assertAlmostEqual(triangleArea({0, 3, 4, 6}), 5.3326822, 4);
    cerr << "all test cases passed for triangleArea()\n";
}

// function to calculate and print the result on triangle
void computeAreaAndPerimeter(const Triangle & t) {
    cout << "Triangle info: \n"
         << "3 sides length: " << t.side1 << " " << t.side2 << " " << t.side3
         << "\narea: " << triangleArea(t) 
         << "\nperimeter: " << trianglePerimeter(t) << endl;        
}

void menu() {
    cout << "Menu options to work with Triangles:\n"
        << "1. Read triangle from keyboard\n"
        << "2. Display all triangles\n"
        << "3. Calculate area and perimeter\n"
        << "4. Write triangles' data to a file\n"
        << "5. Sort triangles based on area in increasing order\n"
        << "6. Sort triangles based on area in non-increasing order\n"
        << "7. Exit the program\n"
        << "Enter your choice [1-7]: ";
}


// function reads the triangles' information from a given fileName
// stores data into triangles vector
void readTriangles(vector<Triangle> & triangles, const string & fileName) {
    // open the given file and read the data
    ifstream fin(fileName.c_str());
    if (! fin) {
        cerr << "File couldn't be opened\n"
            << "make sure " << fileName << " exists and you've permision to read it.";
        return;
    }
    // read and discard first line - header
    Triangle temp;
    int ID = 1;
    // read and discard the first line or heading
    string heading;
    getline(fin, heading);
    //cout << "heading = " << heading << endl;
    int count = 0;
    while(fin >> temp.side1 >> temp.side2 >> temp.side3) {
        // check data was read correctly
        //printResult(temp);
        // check if the three sides form a triangle
        count++;
        if (! validTriangle(temp.side1, temp.side2, temp.side3)) {
            cout << "Skipping invalid triangle: " 
            << temp.side1 << " " << temp.side2 << " " << temp.side3 << endl;
            continue;
        }
        temp.ID = ID;
        triangles.push_back(temp);
        ID++;
    }
    fin.close();
    cout << "Read " << triangles.size() << " out of " << count << " triangles from the file.\n";
}

// linear search function
// given id, and vector or triangles, the function searches and finds
// the index of the triangle in the vector
// if triangle is not found, returns -1
int searchTriangle(const vector<Triangle> & tris, int id) {
    for(int i=0; i< tris.size(); i++) {
        if (tris[i].ID == id) // triangle is found
            return i;
    }
    return -1; // triangle is not found
}

// function compares two triangles based on their area
// returns true if t1 is smaller than t2; false otherwise
bool smaller(const Triangle & t1, const Triangle & t2) {
    return (triangleArea(t1) < triangleArea(t2));
}

// function compares two triangles based on their area
// returns true if t1 is larger than t2; false otherwise
bool larger(const Triangle & t1, const Triangle & t2) {
    return (triangleArea(t1) > triangleArea(t2));
}

// function writes triangles data to the given file
void writeTriangles(const vector<Triangle> & tris, const string & fileName) {
    // open out file stream to write data to
    ofstream fout(fileName.c_str());
    if (! fout) {
        cerr << "File couldn't be opened to write data to.\n"
            << "Make sure file is not locked and you've write permission to the folder\n";
        return;
    }
    // write header just like in the original input file
    fout << "Triangle's side1, side2, side3\n";
    for(Triangle t: tris) {
        fout << t.side1 << " " << t.side2 << " " << t.side3 << endl;
    }
    fout.close();
    cout << "Database successfully updated...\n";
}


// print all the triangles on to the console
void printTriangles(const vector<Triangle> & tris) {
    // write headers
    int colWidth = 45;
    cout << setw(colWidth) << setfill('=') << " " << setfill(' ') << endl;
    cout << "     All the triangles information \n";
    cout << setw(colWidth) << setfill('=') << " " << setfill(' ') << endl;
    colWidth = 10;
    cout << setw(colWidth) << "ID" << setw(colWidth) << "side 1" << 
        setw(colWidth) << "side 2" << setw(colWidth) << "side 3" << endl;
    colWidth = 45;
    cout << setw(colWidth) << setfill('*') << " " << setfill(' ') << endl;
    // write data
    colWidth = 10;
    for(const Triangle & t: tris) {
        cout << setw(colWidth) << t.ID
            << setw(colWidth) << t.side1
            << setw(colWidth) << t.side2
            << setw(colWidth) << t.side3 << endl;
    }
    colWidth = 45;
    cout << setw(colWidth) << setfill('*') << " " << setfill(' ') << endl;
}