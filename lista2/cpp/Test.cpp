#include "GF_1234577.h"
#include <iostream>

int main()
{
    GF_1234577 n(100000);
    GF_1234577 k(20);

    if(n < k)
    {
        std::cout << n << "\n";
    }
    else 
    {
        std::cout << k << "\n";
    }
   
    return 0;
}