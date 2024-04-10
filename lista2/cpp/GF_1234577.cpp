#include "GF_1234577.h"
#include <iostream>

class gfException : public std::exception
{
    virtual const char* what() const throw() 
    { 
        return "GF field exception"; 
    }
};

GF_1234577::GF_1234577()
{
    this->value = 0;
}

GF_1234577::GF_1234577(int value)
{
    setValue(value);
}

unsigned GF_1234577::getValue()
{
    return value;
}

void GF_1234577::setValue(int value)
{
    while(value < 0)
    {
        value = characteristic + value;
    }

    this->value = value % characteristic;
}

unsigned GF_1234577::getCharacteristic()
{
    return characteristic;
}

GF_1234577 GF_1234577::findInverse(unsigned value)
{
    try
    {
        unsigned x, y;
        unsigned g = gcdExtended(value, characteristic, &x, &y);    
        if (g != 1)
        {
            throw new gfException;
        }
        else 
        {
            return GF_1234577((x % characteristic) % characteristic);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return GF_1234577();     
}

unsigned GF_1234577::gcdExtended(unsigned a, unsigned b, unsigned* x, unsigned* y)
{
    if (a == 0) 
    {
        *x = 0, *y = 1;
        return b;
    }
 
    unsigned x1, y1;
    unsigned gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

GF_1234577 GF_1234577::operator+(const GF_1234577& obj)
{
    return GF_1234577((this->value + obj.value) % characteristic);
}

GF_1234577 GF_1234577::operator-(const GF_1234577& obj)
{
    int result = this->value - obj.value;

    return (result < 0) ? GF_1234577(characteristic + result) : GF_1234577(result);  
}

GF_1234577 GF_1234577::operator*(const GF_1234577& obj)
{
    int temp = obj.value;

    GF_1234577 res(0);
    for(int i = 0; i < temp; i++)
    {
        res = (res + (*this));
    }
    
    return res;
}

GF_1234577 GF_1234577::operator/(const GF_1234577& obj)
{
    GF_1234577 res = findInverse(obj.value);
    return (*this) * res;
}

GF_1234577& GF_1234577::operator=(const GF_1234577& obj)
{
    this->value = obj.value;
    return *this;
}

GF_1234577& GF_1234577::operator*=(const GF_1234577& obj)
{
    (*this) = (*this) * obj;
    return *this;
}

GF_1234577& GF_1234577::operator/=(const GF_1234577& obj)
{
    (*this) = (*this) / obj;
    return *this;
}

GF_1234577& GF_1234577::operator+=(const GF_1234577& obj)
{
    (*this) = (*this) + obj;
    return *this;
}

GF_1234577& GF_1234577::operator-=(const GF_1234577& obj)
{
    (*this) = (*this) - obj;
    return *this;
}

bool GF_1234577::operator!=(const GF_1234577& obj)
{
    return this->value != obj.value;
}

bool GF_1234577::operator==(const GF_1234577& obj)
{
    return this->value == obj.value;
}

bool GF_1234577::operator<=(const GF_1234577& obj)
{
    return this->value <= obj.value;
}

bool GF_1234577::operator>=(const GF_1234577& obj)
{
    return this->value >= obj.value;
}

bool GF_1234577::operator<(const GF_1234577& obj)
{
    return this->value < obj.value;
}

bool GF_1234577::operator>(const GF_1234577& obj)
{
    return this->value > obj.value;
}

std::ostream& operator<<(std::ostream& out, const GF_1234577& obj)
{
    out << obj.value;
    return out;
}

std::istream& operator>>(std::istream& in, GF_1234577& obj)
{
    try
    {
        int value;
        if(!(in >> value))
        {
            throw new gfException;
        }
        else
        {
            obj.setValue(value);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return in;
}