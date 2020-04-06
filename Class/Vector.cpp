#include "Vector.h"

Vector::Vector() :elem{new double[0]}, sz{0}
{}

Vector::Vector(int s) :elem{new double[s]}, sz{s}
{}

Vector::Vector(std::initializer_list<double> list) :sz{static_cast<int>(list.size())}, elem{new double[list.size()]}
{
    std::copy(list.begin(), list.end(), elem);
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

void Vector::init_vector(int n)
{
    sz = n;

    for(int i = 0; i < n; i++)
        elem[i] = i;
}

void Vector::read_vector()
{
    for(int i = 0; i < sz; i++)
        std::cout << elem[i] << " ";
}