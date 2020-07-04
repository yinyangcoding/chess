#ifndef BLANDTOOLS_GUARD
#define BLANDTOOLS_GUARD

#include <iostream>
#include <string>

#include "Constants.h"


// Contains tools that are needed universally throughout code
namespace BTools {
    // Toupper and tolower for chars
    char to_upper(char c);
    char to_lower(char c);

    // Trim functions for strings
    std::string trim(std::string str);
    std::string ltrim(std::string str);
    std::string rtrim(std::string str);

    // Easy debug step
    void debug(std::string s);

};

#endif