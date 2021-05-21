#include "../header/Utilities.h"

#include <iostream>

namespace Utilities
{
    void log(const char* str)
    {
        std::cout << "[LOG] " << str << std::endl;
    }
    void log_error(const char* str)
    {
        std::cout << "[Error] " << str << std::endl;
    }
}