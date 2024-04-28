#pragma once 
#include <vector>
#include "GaloisField.h"

template <class T>
class DHSetup
{
private:
    std::vector<int> primes;
    T generator;

public:
    DHSetup();
    T getGenerator();
    T power(T a, unsigned long b);

private:
    std::vector<int> findPrimes(unsigned characteristic);
};