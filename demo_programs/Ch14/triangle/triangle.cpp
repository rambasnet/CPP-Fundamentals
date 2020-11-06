#include <iostream>
#include <fstream>
#include <iomanip>

#include "utility.h"
#include "triangle.h"

using namespace std;

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

// function to check if 3 sides form a triangle
bool validTriangle(float s1, float s2, float s3) {
    // sum of every pair must be greater than the third
    return (s1+s2 > s3 && (s2+s3 > s1) && (s1+s3 > s2))? true: false;
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

// function to compute area of a triangle
float triangleArea(const Triangle & t) {
    // use heron's formula: https://www.mathsisfun.com/geometry/herons-formula.html
    float s = trianglePerimeter(t)/2;
    return sqrt(s*(s-t.side1)*(s-t.side2)*(s-t.side3));
}

// function to calculate and print the result on triangle
void computeAreaAndPerimeter(const Triangle & t) {
    cout << "Triangle info: \n"
         << "3 sides length: " << t.side1 << " " << t.side2 << " " << t.side3
         << "\narea: " << triangleArea(t) 
         << "\nperimeter: " << trianglePerimeter(t) << endl;        
}