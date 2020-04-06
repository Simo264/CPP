#include "Vector.h"

Vector::Vector(int s) 
{
    if(s < 0) throw std::length_error
    {
        "Vector error length"
    };
    
    elem = new double[s];
    sz = s;
}

double& Vector::operator[](int i)
{
    if( (i < 0) || (size() < i) ) throw std::out_of_range 
    {
        "Vector::operator[]"
    };

    return elem[i];
}

int Vector::size() const
{
    return sz;
}