#ifndef COORDINATE_GUARD
#define COORDINATE_GUARD

#include <iostream>
#include <string>

#include "../resources/Constants.h"
#include "../resources/BlandTools.hpp"

using namespace std;

// Will be used to show the coord of the piece
class Coordinate {
    private:
        // y and x values
        int y;
        int x;

    public:
    
        // ================ Constructors ================
        // Build coord from given x and y
        Coordinate(int y, int x);

        // Takes proper chess coord structure
        Coordinate(char c, int i);

        // Build coord as origin
        Coordinate();

        // ================ Sets ================
        // Saves given y value
        void set_y(int y);

        // Saves given x value
        void set_x(int x);

        // Saves given y and x value
        void set_coord(int y, int x);

        // ================ Gets ================
        // Returns x value
        int get_x() const;

        // Returns y value
        int get_y() const;

        // ============ Methods ===============
        // Returns true if this and b are equal
        bool equals(Coordinate b);

        // Copies from a to this
        void copy_from(Coordinate a);

        // Returns true if Coordinate is (-1, -1)
        bool is_blank();

        // ================ Debug ================
        // Prints pair in (x, y) format to the command line
        void print_pair();
};

#endif