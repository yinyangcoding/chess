#include "../../include/resources/Tools.hpp"

// Checks if a Piece vector contains a piece
bool Tools::contains(vector<Piece> v, Piece p) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i].equals(p)) {
            return true;
        }
    }
    return false;
}

// Grabs the index of a piece from a piece vector
int Tools::index(vector<Piece> v, Piece p) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i].equals(p)) {
            return i;
        }
    }
    return -1;
}

// Toupper and tolower for chars
char Tools::to_upper(char c) {
    if(c >= 97 && c <= 122) {
        return c - 32;
    }
    return c;
}
char Tools::to_lower(char c) {
    if(c >= 65 && c <= 90) {
        return c + 32;
    }
    return c;
}