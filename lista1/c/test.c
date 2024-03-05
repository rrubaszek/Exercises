#include <stdio.h>
#include "diophantine_lib.h"

int main()
{
    int n, a, b, c, d, e;
    int x = 0;
    int y = 0;

    scanf("%d\n", &n);
    scanf("%d%d\n", &a, &b);
    scanf("%d%d%d", &c, &d, &e);

    printf("Factorial: %d\n", factorial(n));

    printf("GCD: %d\n", gcd(a, b));

    diophantine(c, d, e, &x, &y);

    if(x == -1)
    {
        printf("No solutions to this diophantine equation\n");
    }
    else
    {
        printf("Diophantine x: %d\n", x);
        printf("Diophantine y: %d\n", y);
    }
    
    return 0;
}