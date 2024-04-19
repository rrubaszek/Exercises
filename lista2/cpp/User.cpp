#include "User.h"
#include <random>

template <class T> 
User<T>::User(DHSetup<T>& setup)
{
    this->setup = setup;

    auto seed = std::mt19937(std::random_device()());
    auto distribution = std::uniform_int_distribution<int>(0, 100);
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
    if(key != NULL)
        return c /= key;
    else 
        return key;
}

template <class T>
T User<T>::encrypt(T m)
{
    if(key != NULL)
        return m *= key;
    else 
        return key;
}