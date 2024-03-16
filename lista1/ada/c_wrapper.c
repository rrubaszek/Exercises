#include <stdio.h>

extern int factorial_c(int n);
extern int gcd_c(int a, int b);
extern void diophantine_c(int a, int b, int c, int* x, int* y);

int main()
{
    int x, y;

    printf("Factorial: %d\n", factorial_c(5));
    printf("GCD: %d\n", gcd_c(30, 25));
    diophantine_c(4, 7, 8, &x, &y);
    printf("X=%d Y=%d\n", x, y);
}