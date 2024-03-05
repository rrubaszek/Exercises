#include "diophantine_lib.h"

int factorial(int n)
{
    if(n > 1)
    {
        return n * factorial(n-1);
    }
    else
    {
        return 1;
    }
}

int gcd(int a, int b)
{
    if(b != 0)
    {
        return gcd(b, a % b);
    }
    else 
    {
        return a;
    }
}

void diophantine(int a, int b, int c, int *x, int *y)
{
    if(c % gcd(a, b) != 0)
    {
        *x = -1;
        *y = -1;
        return;
    }
    else if(a % b == 0)
    {
        *x = 0;
        *y = c / b;
        return;
    }
    else
    {
        diophantine(b, a % b, c, x, y);
        int temp = *y;
        *y = *x - ((a / b) * (*y));
        *x = temp;
        return;
    }
}