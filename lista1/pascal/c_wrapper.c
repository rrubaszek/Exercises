#include <stdio.h>

extern int factorial(int n);
extern int gcd(int a, int b);
extern void diophantine(int a, int b, int c, int* x, int* y);

int main()
{
    int x, y;

    printf("Factorial: %d\n", factorial(5));
    printf("GCD: %d\n", gcd(30, 25));

    diophantine(4, 7, 8, &x, &y);

    printf("X=%d Y=%d\n", x, y);
}