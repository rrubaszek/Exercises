#include "GaloisField.h"
#include <iostream>

class gfException : public std::exception
{
    virtual const char* what() const throw() 
    { 
        return "GF field exception"; 
    }
};

GaloisField::GaloisField()
{
    this->value = 0;
}

GaloisField::GaloisField(int value)
{
    setValue(value);
}

unsigned GaloisField::getValue()
{
    return value;
}

void GaloisField::setValue(int value)
{
    while(value < 0)
    {
        value = characteristic + value;
    }

    this->value = value % characteristic;
}

unsigned GaloisField::getCharacteristic()
{
    return characteristic;
}

GaloisField GaloisField::findInverse(unsigned value)
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
            return GaloisField((x % characteristic) % characteristic);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return GaloisField();     
}

unsigned GaloisField::gcdExtended(unsigned a, unsigned b, unsigned* x, unsigned* y)
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

GaloisField GaloisField::operator+(const GaloisField& obj)
{
    return GaloisField((this->value + obj.value) % characteristic);
}

GaloisField GaloisField::operator-(const GaloisField& obj)
{
    int result = this->value - obj.value;

    return (result < 0) ? GaloisField(characteristic + result) : GaloisField(result);  
}

GaloisField GaloisField::operator*(const GaloisField& obj)
{
    int temp = obj.value;

    GaloisField res(0);
    for(int i = 0; i < temp; i++)
    {
        res = (res + (*this));
    }
    
    return res;
}

GaloisField GaloisField::operator/(const GaloisField& obj)
{
    GaloisField res = findInverse(obj.value);
    return (*this) * res;
}

GaloisField& GaloisField::operator=(const GaloisField& obj)
{
    this->value = obj.value;
    return *this;
}

GaloisField& GaloisField::operator*=(const GaloisField& obj)
{
    (*this) = (*this) * obj;
    return *this;
}

GaloisField& GaloisField::operator/=(const GaloisField& obj)
{
    (*this) = (*this) / obj;
    return *this;
}

GaloisField& GaloisField::operator+=(const GaloisField& obj)
{
    (*this) = (*this) + obj;
    return *this;
}

GaloisField& GaloisField::operator-=(const GaloisField& obj)
{
    (*this) = (*this) - obj;
    return *this;
}

bool GaloisField::operator!=(const GaloisField& obj)
{
    return this->value != obj.value;
}

bool GaloisField::operator==(const GaloisField& obj)
{
    return this->value == obj.value;
}

bool GaloisField::operator<=(const GaloisField& obj)
{
    return this->value <= obj.value;
}

bool GaloisField::operator>=(const GaloisField& obj)
{
    return this->value >= obj.value;
}

bool GaloisField::operator<(const GaloisField& obj)
{
    return this->value < obj.value;
}

bool GaloisField::operator>(const GaloisField& obj)
{
    return this->value > obj.value;
}

std::ostream& operator<<(std::ostream& out, const GaloisField& obj)
{
    out << obj.value;
    return out;
}

std::istream& operator>>(std::istream& in, GaloisField& obj)
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