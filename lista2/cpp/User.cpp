#include "User.h"
#include <random>
#include <iostream>

template <class T> 
User<T>::User(DHSetup<T>& setup)
{
    this->setup = setup;

    auto seed = std::mt19937(std::random_device()());
    auto distribution = std::uniform_int_distribution<int>(1, 50);
    secret = distribution(seed);
}

template <class T>
T User<T>::getPublicKey()
{
    T generator = setup.getGenerator();
    return setup.power(generator, secret);
}

template <class T>
void User<T>::setKey(T a)
{
    key = setup.power(a, secret);
}

template <class T>
T User<T>::decrypt(T c)
{
    try
    {
        if(key != 0)
            return c = (c / key);
        else 
            throw std::runtime_error("Key has not been set up!");
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

   return 0;
}

template <class T>
T User<T>::encrypt(T m)
{
    try
    {
        if(key != 0)
            return m = (m * key);
        else 
            throw std::runtime_error("Key has not been set up!");
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   return 0;
}