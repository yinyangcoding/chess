#include "../../include/resources/BlandTools.hpp"

// Toupper and tolower for chars
char BTools::to_upper(char c) {
    if (c >= 97 && c <= 122) {
        return c - 32;
    }
    return c;
}
char BTools::to_lower(char c) {
    if (c >= 65 && c <= 90) {
        return c + 32;
    }
    return c;
}

// Easy debug step
void BTools::debug(std::string s) {
    if (DEBUG) {
        std::cout << s << std::endl;
    }
}