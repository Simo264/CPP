#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

namespace Utilities
{
    extern "C++" MATHLIBRARY_API void log(const char* str);
    extern "C++" MATHLIBRARY_API void log_error(const char* str);
}