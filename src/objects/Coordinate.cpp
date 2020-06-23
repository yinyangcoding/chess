#include "../../include/objects/Coordinate.hpp"

// ================ Constructors ================
// Build coord from given x and y
Coordinate::Coordinate(int y, int x) {
    this->y = y;
    this->x = x;
}

// Takes proper chess coord structure
Coordinate::Coordinate(char c, int y) {
    // Process coords from standard chess
    c = BTools::to_upper(c);
    int x = c - 65;
    
    // build standard coord
    this->y = SIZE - y;
    this->x = x;
}

// Build coord as origin
Coordinate::Coordinate() {
    y = 0;
    x = 0;
}

// ================ Sets ================
// Saves given y value
void Coordinate::set_y(int y) {
    this->y = y;
}

// Saves given x value
void Coordinate::set_x(int x) {
    this->x = x;
}

// Saves given x and y value
void Coordinate::set_coord(int y, int x) {
    this->y = y;
    this->x = x;
}

// ================ Gets ================
// Returns y value
int Coordinate::get_y() const {
    return y;
}

// Returns x value
int Coordinate::get_x() const {
    return x;
}

// ============ Methods ===============
// Returns if this and b are equal
bool Coordinate::equals(Coordinate b) {
    if(this->y == b.get_y() && this->x == b.get_x()) {
        return true;
    }
    return false;
}

// Copies from a to this
void Coordinate::copy_from(Coordinate a) {
    y = a.get_y();
    x = a.get_x();
}

// ================ Debug ================
// Prints pair in (x, y) format to the command line
void Coordinate::print_pair() {
    printf("(%d, %d)\n", y, x);
}