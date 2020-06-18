#ifndef COORDINATE_GUARD
#define COORDINATE_GUARD

#include <iostream>
#include <string>

using namespace std;

// Will be used to show the coord of the piece
class Coordinate {
    private:
        // x and y values
        int x;
        int y;

    public:
    
        // ================ Constructors ================
        // Build coord from given x and y
        Coordinate(int x, int y);

        // Build coord as origin
        Coordinate();

        // ================ Sets ================
        // Saves given x value
        void set_x(int x);

        // Saves given y value
        void set_y(int y);

        // Saves given x and y value
        void set_coord(int x, int y);

        // ================ Gets ================
        // Returns x value
        int get_x();

        // Returns x value
        int get_y();

        // ============ Methods ===============
        // Returns if this and b are equal
        bool equals(Coordinate b);
        void copy_from(Coordinate a);

        // ================ Debug ================
        // Prints pair in (x, y) format to the command line
        void print_pair();
};

#endif