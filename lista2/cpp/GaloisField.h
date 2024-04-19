#pragma once
#include <iostream>

class GaloisField
{
friend std::ostream& operator<<(std::ostream& out, const GaloisField& obj);
friend std::istream& operator>>(std::istream& in, GaloisField& obj);

public:
    GaloisField();
    GaloisField(int value);

    unsigned getValue();
    unsigned getCharacteristic();

    void setValue(int value);

    GaloisField operator + (const GaloisField&  obj);
    GaloisField operator - (const GaloisField& obj);
    GaloisField operator * (const GaloisField& obj);
    GaloisField operator / (const GaloisField& obj);

    GaloisField& operator = (const GaloisField& right);
    GaloisField& operator -= (const GaloisField& obj);
    GaloisField& operator *= (const GaloisField& obj);
    GaloisField& operator += (const GaloisField& obj);
    GaloisField& operator /= (const GaloisField& obj);

    bool operator == (const GaloisField& obj);
    bool operator != (const GaloisField& obj);
    bool operator >= (const GaloisField& obj);
    bool operator <= (const GaloisField& obj);
    bool operator > (const GaloisField& obj);
    bool operator < (const GaloisField& obj);

private:
    GaloisField findInverse(unsigned value);
    unsigned gcdExtended(unsigned a, unsigned b, unsigned* x, unsigned* y);

private:
    unsigned value;
    unsigned static const characteristic = 1234577;
};