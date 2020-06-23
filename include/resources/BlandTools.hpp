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

        // Easy debug step
        static void debug(std::string s);

};

#endif