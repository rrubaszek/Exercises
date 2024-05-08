#include "DHSetup.h"
#include "GaloisField.h"

#include <vector>
#include <iostream>
#include <random>

template <class T>
DHSetup<T>::DHSetup()
{
    auto seed = std::mt19937(std::random_device()());

    T num;

    std::cout << "Initializing...\n";
    
    unsigned p = num.getCharacteristic(); //C++ jest kurwa swietny XDDDD
    primes = findPrimes(p-1);

    std::cout << "Done\n";

    unsigned long exponent;
    unsigned ctr;
    int a;
    while(true)
    {
        auto distribution = std::uniform_int_distribution<int>(0, p-1);
        a = distribution(seed);

        num.setValue(a);

        ctr = 0;
        for(int i : primes)
        {
            exponent = (p - 1) / i;

            if(power(num, exponent) != 1)
            {
                ctr++;          
            }
        }

        if(ctr == primes.size())
        {
            break;
        }

    }
    generator = num;
}

template <class T>
T DHSetup<T>::power(T a, unsigned long b)
{
    T result = 1;
    while(b > 0) 
    {
        if(b % 2 == 1) 
        {
            result = (result*a);
        }
        a = (a * a);
        b = b / 2; 
    }

    return result;
}

template <class T>
T DHSetup<T>::getGenerator()
{
    return this->generator;
}

template <class T>
std::vector<int> DHSetup<T>::findPrimes(unsigned characteristic)
{
    std::vector<int> res;
    unsigned n = characteristic - 1;

    if(n % 2 == 0)
    {
        res.push_back(2);
        while(n % 2 == 0)
        {
            n /= 2;
        }
    }

    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            res.push_back(i);
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }

    if(n > 2)
    {
        res.push_back(n);
    }

    return res;
}