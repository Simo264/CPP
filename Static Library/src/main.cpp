#include <iostream>
#include "../header/MathLibrary.h"
#include "../header/Utilities.h"

int main()
{
    double a = 7.4;
    int b = 99;

    std::cout << "a + b = " <<
        MathLibrary::Arithmetic::Add(a, b) << std::endl;
    std::cout << "a - b = " <<
        MathLibrary::Arithmetic::Subtract(a, b) << std::endl;
    std::cout << "a * b = " <<
        MathLibrary::Arithmetic::Multiply(a, b) << std::endl;
    std::cout << "a / b = " <<
        MathLibrary::Arithmetic::Divide(a, b) << std::endl;

    Utilities::log("Hello world (info)");
    Utilities::log_error("Hello world (error)");

    std::cin.get();
    return 0;
}