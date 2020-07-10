// program demonstrates passing arguments to main
// TODO: compile the program 
// run the program with arguments
// e.g. programName
// e.g. programName hello "john smith" 10
#include <iostream>
#include <cstring> //strncmp
#include <string>

using namespace std;

void test() {
    cout << "running test function!\n";
}

// main takes arguments
int main(int argc, char* argv[]) {
    // 1 argument is always available
    cout << "total argument count = " << argc << endl;
    // there'll always be one argument; the name of the program
    cout << "value at argv[0] = " << argv[0] << endl;

    // can convert each argument captured in argv[] array to string type
    string arg0 = string(argv[0]); // program name
    
    if (argc >= 2) {
        cout << "value at argv[1] = " << argv[1] << endl;
        string arg1 = string(argv[1]);
        if (arg1 == "test")
            test();
    }

    if (argc >= 3) 
        cout << "value at argv[2] = " << argv[2] << endl;
    if (argc >= 4) 
        cout << "value at argv[3] = " << argv[3] << endl;
    // so on..
    return 0;
}