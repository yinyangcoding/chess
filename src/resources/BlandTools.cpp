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

const std::string WHITESPACE = " \n\r\t\f\v";

std::string BTools::trim(std::string str) {
    return BTools::ltrim(BTools::rtrim(str));
}

std::string BTools::ltrim(std::string str) {
    auto begin = str.find_first_not_of(WHITESPACE);
    return (begin == std::string::npos) ? "" : str.substr(begin);
}

std::string BTools::rtrim(std::string str) {
    auto end = str.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}


// Easy debug step
void BTools::debug(std::string s) {
    if (DEBUG) {
        std::cout << s << std::endl;
    }
}