// Expected Output (input: "3.5, 4.5" followed by "Alice\n"):
// ============================================================
// Enter two numbers separated by comma: 3.5 + 4.5 = 8.00
// Hi, what's your name?: Nice meeting you, Alice
// Good bye!
// Press enter to quit the program...

// Known Issue: getline after >> leaves '\n' in buffer - name will be empty
// unless cin >> ws is uncommented at line 21.

// demonstrates standard input and output
// specifically >> and getline
// compile and run the program as it is
// TODO: fix it by uncommenting cin >> ws; line, so the getline works propertly!

#include <iostream>
#include <string>

using namespace std;

int main() {
    float n1, n2;
    char ch;
    string name;
    cout << "Enter two numbers separated by comma: ";
    // parse the input stream
    // >> reads and discards leading whitespace until printable character is found
    cin >> n1 >> ch >> n2; // leaves behind \n
    cout << n1 << " + " << n2 << " = " << n1+n2 << endl;
    cout << "Hi, what's your name?: ";
    // cin >> ws; // discard any whitespace character and stop at the character
    // ws makes the input wait until non-whitespace character is found
    // need to use it carefully!
    getline(cin, name);
    cout << "Nice meeting you, " << name << endl;
    cout << "Good bye!\n";
    cout << "Press enter to quit the program...";
    cin.get();
    return 0;
}