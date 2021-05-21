#include "../header/MathLibrary.h"

#include <iostream>

namespace MathLibrary
{
    double Add(double a, double b)
    {
        return a + b;
    }

    double Subtract(double a, double b)
    {
        return a - b;
    }

    double Multiply(double a, double b)
    {
        return a * b;
    }

    double Divide(double a, double b)
    {
        return a / b;
    }

    void __print()
    {
        std::cout << "DLL Library success!" << std::endl;
    }
}