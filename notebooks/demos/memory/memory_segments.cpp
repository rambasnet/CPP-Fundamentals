// Program that demonstrates various memory semgments
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int globalNum = 100;                   // Data segment
static double globalStaticNum = 100.1; // data segment
int globalNum1;                        // bss segment

void myFunction() // code segment
{
    int num = 10;            // stack segment
    int nums[3] = {1, 2, 3}; // stack segment
    int *ptr = new int;      // p is in stack but point to a address in heap segment
    cout << "\nLocal Variables in myFunction:" << endl;
    printf("\theap: value of pointer p= %p\n", ptr);
    printf("\tstack: address of a= %p\n", &num);
    printf("\tstack: base address of nums= %p\n", nums);
    printf("\tstack: address of pointer ptr= %p\n", &ptr);
}

int main() // code segment
{
    int num = 100;      // stack segment
    int *ptr = new int; // Heap segment
    printf("Code segment: \n \taddress of main= %p\n", &main);
    printf("\taddress of myFunction= %p\n", &myFunction);
    printf("Data segment: \n\taddress of globalNum= %p\n", &globalNum);
    printf("\taddress of globalStaticNum= %p\n", &globalStaticNum);
    printf("bss segment: \n\taddress of globalNum1= %p\n", &globalNum1);
    cout << "\nLocal variabiles in main:" << endl;
    printf("\theap: value of pointer ptr= %p\n", ptr);
    printf("\tstack: address of a= %p\n", &num);
    printf("\tstack: address of ptr= %p\n", &ptr);
    myFunction();
    return 0;
}