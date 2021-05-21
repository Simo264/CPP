#include <iostream>
#include "../header/MathLibrary.h"
#include "../header/Utilities.h"

int main()
{
    double a = 7.4;
    int b = 99;

    std::cout << "a + b = " <<
        MathLibrary::Add(a, b) << std::endl;
    std::cout << "a - b = " <<
        MathLibrary::Subtract(a, b) << std::endl;
    std::cout << "a * b = " <<
        MathLibrary::Multiply(a, b) << std::endl;
    std::cout << "a / b = " <<
        MathLibrary::Divide(a, b) << std::endl;

    MathLibrary::__print();
    Utilities::log("Hello world (DLL) ");
    Utilities::log("Hello world (DLL) ");

    std::cin.get();
    return 0;
}