// Implementation of fruitful functions for demonstration of doctest
#include <cmath>
using namespace std;

// Function that returns the sum of two integers
int add(int a, int b)
{
    return a + b;
}
// Function that returns the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Function that returns the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}
// Function that returns the factorial of a non-negative integer
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
// Function that returns the nth Fibonacci number
int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Function that returns the nth Fibonacci number using iteration
int fibonacci_iterative(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; ++i)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}
