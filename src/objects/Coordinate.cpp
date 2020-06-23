#include "../../include/objects/Coordinate.hpp"

// ================ Constructors ================
// Build coord from given x and y
Coordinate::Coordinate(int y, int x) {
    BTools::debug("Coordinate::Coordinate(int, int)");
    this->y = y;
    this->x = x;
}

// Takes proper chess coord structure
Coordinate::Coordinate(char c, int y) {
    BTools::debug("Coordinate::Coordinate(char, int)");
    // Process coords from standard chess
    c = BTools::to_upper(c);
    int x = c - 65;
    
    // build standard coord
    this->y = SIZE - y;
    this->x = x;
}

// Build coord as origin
Coordinate::Coordinate() {
    BTools::debug("Coordinate::Coordinate()");
    y = 0;
    x = 0;
}

// ================ Sets ================
// Saves given y value
void Coordinate::set_y(int y) {
    BTools::debug("Coordinate::Coordinate()");
    this->y = y;
}

// Saves given x value
void Coordinate::set_x(int x) {
    BTools::debug("void Coordinate::set_x(int)");
    this->x = x;
}

// Saves given x and y value
void Coordinate::set_coord(int y, int x) {
    BTools::debug("void Coordinate::set_coord(int, int)");
    this->y = y;
    this->x = x;
}

// ================ Gets ================
// Returns y value
int Coordinate::get_y() const {
    BTools::debug("int Coordinate::get_y() const");
    return y;
}

// Returns x value
int Coordinate::get_x() const {
    BTools::debug("int Coordinate::get_x() const");
    return x;
}

// ============ Methods ===============
// Returns if this and b are equal
bool Coordinate::equals(Coordinate b) {
    BTools::debug("bool Coordinate::equals(Coordinate)");
    if(this->y == b.get_y() && this->x == b.get_x()) {
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

// ================ Debug ================
// Prints pair in (x, y) format to the command line
void Coordinate::print_pair() {
    BTools::debug("void Coordinate::print_pair()");
    printf("(%d, %d)\n", y, x);
}