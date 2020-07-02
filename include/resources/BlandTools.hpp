#ifndef BLANDTOOLS_GUARD
#define BLANDTOOLS_GUARD

#include <iostream>
#include <string>

#include "Constants.h"


// Contains tools that are needed universally throughout code
class BTools {
    public:
        // Toupper and tolower for chars
        static char to_upper(char c);
        static char to_lower(char c);

        // Trim functions for strings
        static std::string trim(std::string str);
        static std::string ltrim(std::string str);
        static std::string rtrim(std::string str);

        // Easy debug step
        static void debug(std::string s);

};

#endif