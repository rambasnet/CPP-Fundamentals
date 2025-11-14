// A Simple count down to Blast Off program
// Demonstrates count down using both For and While loops

#include <iostream>
#include <unistd.h> //usleep
#include <string>

using namespace std;

// function to clear the screen
void clear() {
    // Note: system call is not recommended security best practices in real-world!
    #ifdef _WIN32 // if 32 or 64 bit Windows
        system("cls"); 
    #else // assuming mac or linux
        system("clear");
    #endif
}

void pause(float seconds) {
    #ifdef _WIN32 // if 32 or 64 bit Windows
        Sleep(seconds*1000); // milliseconds
    #else // assuming mac or linux
        usleep(seconds*1000000); // microseconds
    #endif
}

void countDownForLoop(int N) {
    cout << "For Loop Countdown demo...\n";
    cout << "Starting countdown from " << N << endl;
    pause(1);
    for(int i=N; i>=0; i--) {
        clear();
        if (i == 0) {
            cout << "Blast Off!!!" << endl;
            pause(1);
            cout << "#$%@$#RAET$#%#$%EDFAsdf$^@^@#$^FD\n";
            pause(0.5);
            cout << "^%$#$@#$^&$^%&$%^#%#$!@*&)!@!@#!DFGSFG%^$GAG\n";
            pause(1);
            clear();
            cout << "#$%@$#RAET$#%#$%EDFA$#%@#GAGQ!#%#FD\n";
            pause(1);
            clear();
        }
        else {
            cout << i << endl;
            pause(1);
        }
    }
}

void countDownWhileLoop(int N) {
    cout << "While Loop Countdown demo...\n";
    cout << "Starting countdown from " << N << endl;
    pause(2);
    while(N >=0) {
        clear();
        if (N == 0) {
            cout << "Blast Off!!!" << endl;
            pause(1.0);
            cout << "#$%@$#RAET$#%#$%EDFAsdf$^@^@#$^FD\n";
            pause(0.5);
            cout << "^%$#$@#$^&$^%&$%^#%#$!@*&)!@!@#!DFGSFG%^$GAG\n";
            pause(1);
            clear();
            cout << "#$%@$#RAET$#%#$%EDFA$#%@#GAGQ!#%#FD\n";
            pause(1);
            clear();
        }
        else {
            cout << N << endl;
            pause(1);
        }
        N--;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "for")
        countDownForLoop(10);
    else
        countDownWhileLoop(10);
    return 0;
}