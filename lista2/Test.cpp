#include "GF_1234577.h"
#include <iostream>

int main()
{
    GF_1234577 n(100000);
    GF_1234577 k(20);

    n *= k;
   
    std::cout << n << "\n";

    return 0;
}