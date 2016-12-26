#include <string>
#include <sstream>

#pragma once
// please note that extending namespace is actually undefined behaviour
// (because the implementation can extend this namespace)
// but in that case we are doing it intentionally.
namespace std {
template <typename T>
std::string to_string(const T &value)
{
        std::ostringstream os;
        os << value;
        return os.str();
}

inline int stoi(const std::string &s, size_t *idx = 0, int base = 10)
{
        char *endptr = 0;
        int v = strtol(s.c_str(), &endptr, base);
        if (idx) {
                *idx = endptr - s.c_str();
        }
        return v;
}

// fixes for lame android ndks and some mingws
inline float strtof (const char* str, char** endptr)
{
        return ::strtof(str, endptr);
}

inline long double strtold(const char* str, char** endptr)
{
        return ::strtold(str, endptr);
}

}
