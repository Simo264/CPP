#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

namespace MathLibrary{

    // Returns a + b
    extern "C" MATHLIBRARY_API double Add(double a, double b);

    // Returns a - b
    extern "C" MATHLIBRARY_API double Subtract(double a, double b);

    // Returns a * b
    extern "C" MATHLIBRARY_API double Multiply(double a, double b);

    // Returns a / b
    extern "C" MATHLIBRARY_API double Divide(double a, double b);

    extern "C++" MATHLIBRARY_API void __print();
}