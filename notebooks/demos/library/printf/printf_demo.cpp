/*
Program to demonstrate printf function
*/

#include <cstdio>

using namespace std;

int main() {
    // format printf( ) demo
    printf("Printing integer numbers: %d %u %i\n", -100, 85, -999);
    printf("Printing characters:\tc %c\n", 65);
    printf("Printing c-string: %s\n", "Hello World");
    printf("Printing floating points: %.2f\n", 1.99999); // round it to 2 decimal points

    printf("\n\n");
    printf("Printing Hexadecimal: %x %X %#x %#X\n", 10, 10, 10, 10);
    printf("Printing Octal: %o %#o\n", 10, 10);
    printf("Printing Scientific: %e %E\n", 1.5, 1.5);

    printf("\n\n");
    printf("Column Width & Right Justification: '%10s'\n", "Hi");
    printf("Column Width & Left Justification: '%-10s'\n", "Hi");

    return 0;
}