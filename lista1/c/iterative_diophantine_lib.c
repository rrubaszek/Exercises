#include "diophantine_lib.h"

int factorial(int n)
{
    int result = 1;
    while(n > 1)
    {
        result = result * n;
        n--;
    }
    return result;
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    } 
    else if (b == 0)
    {
        return a;
    }
        
    while (a != b) 
    {
        if (a > b)
        {
            a = a - b;
        }   
        else
        {
            b = b - a;
        }   
    }
    return a;
}

void diophantine(int a, int b, int c, int* x, int* y)
{
    int x_prev = 1, y_prev = 0, x_next = 0, y_next = 1;

    while (b != 0) 
    {
        int quotient = a / b;

        int temp = x_prev;
        x_prev = x_next;
        x_next = temp - quotient * x_next;

        temp = y_prev;
        y_prev = y_next;
        y_next = temp - quotient * y_next;

        int remainder = a % b;
        a = b;
        b = remainder;
    }

    if (c % a != 0) 
    {
        *x = -1;
        *y = -1;
    } 
    else 
    {
        *x = x_prev * (c / a);
        *y = y_prev * (c / a);
    }

}