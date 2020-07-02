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
    
    // Build standard coord
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
// Returns true if this and b are equal
bool Coordinate::equals(Coordinate b) {
    BTools::debug("bool Coordinate::equals(Coordinate)");
    if (this->y == b.get_y() && this->x == b.get_x()) {
        return true;
    }
    return false;
}

// Copies from a to this
void Coordinate::copy_from(Coordinate a) {
    BTools::debug("void Coordinate::copy_from(Coordinate)");
    y = a.get_y();
    x = a.get_x();
}

// Returns true if Coordinate is (-1, -1)
bool Coordinate::is_blank() {
    return (y == -1 && x == -1);
}
// ================ Debug ================
// Prints pair in (x, y) format to the command line
void Coordinate::print_pair() {
    BTools::debug("void Coordinate::print_pair()");
    printf("(%d, %d)\n", y, x);
}