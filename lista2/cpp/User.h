#pragma once
#include "DHSetup.h"

template <class T>
class User
{
public:
    User(DHSetup<T>& setup);
    T getPublicKey();
    void setKey(T a);
    T encrypt(T m);
    T decrypt(T c);

private:
    unsigned long secret;
    DHSetup<T> setup;
    T key;
};