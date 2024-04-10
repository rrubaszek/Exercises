#pragma once
#include <iostream>

class GF_1234577
{
friend std::ostream& operator<<(std::ostream& out, const GF_1234577& obj);
friend std::istream& operator>>(std::istream& in, GF_1234577& obj);

public:
    GF_1234577();
    GF_1234577(int value);

    unsigned getValue();
    unsigned getCharacteristic();

    void setValue(int value);

    GF_1234577 operator + (const GF_1234577&  obj);
    GF_1234577 operator - (const GF_1234577& obj);
    GF_1234577 operator * (const GF_1234577& obj);
    GF_1234577 operator / (const GF_1234577& obj);

    GF_1234577& operator = (const GF_1234577& right);
    GF_1234577& operator -= (const GF_1234577& obj);
    GF_1234577& operator *= (const GF_1234577& obj);
    GF_1234577& operator += (const GF_1234577& obj);
    GF_1234577& operator /= (const GF_1234577& obj);

    bool operator == (const GF_1234577& obj);
    bool operator != (const GF_1234577& obj);
    bool operator >= (const GF_1234577& obj);
    bool operator <= (const GF_1234577& obj);
    bool operator > (const GF_1234577& obj);
    bool operator < (const GF_1234577& obj);

private:
    GF_1234577 findInverse(unsigned value);
    unsigned gcdExtended(unsigned a, unsigned b, unsigned* x, unsigned* y);

private:
    unsigned value;
    unsigned static const characteristic = 1234577;
};