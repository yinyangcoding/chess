#ifndef TOOLS_GUARD
#define TOOLS_GUARD

#include <iostream>
#include <vector>

#include "../objects/Piece.hpp"
#include "../objects/Coordinate.hpp"

// Contains tools that are needed universally throughout code
class Tools {
    public:
        // Checks if a Piece vector contains a piece
        static bool contains(vector<Piece> v, Piece p);

        // Grabs the index of a piece from a piece vector
        static int index(vector<Piece> v, Piece p);

        // Toupper and tolower for chars
        static char to_upper(char c);
        static char to_lower(char c);

};

#endif