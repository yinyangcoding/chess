#include "../../include/objects/Coordinate.hpp"

// ================ Constructors ================
// Build coord from given x and y
Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

// Build coord as origin
Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

// ================ Sets ================
// Saves given x value
void Coordinate::set_x(int x) {
    this->x = x;
}

// Saves given y value
void Coordinate::set_y(int y) {
    this->y = y;
}

// Saves given x and y value
void Coordinate::set_coord(int x, int y) {
    this->x = x;
    this->y = y;
}

// ================ Gets ================
// Returns x value
int Coordinate::get_x() {
    return x;
}

// Returns y value
int Coordinate::get_y() {
    return y;
}

// ============ Methods ===============
// Returns if this and b are equal
bool Coordinate::equals(Coordinate b) {
    if(this->x == b.get_x() && this->y == b.get_y()) {
        return true;
    }
    return false;
}

// Copies from a to this
void Coordinate::copy_from(Coordinate a) {
    x = a.get_x();
    y = a.get_y();
}

// ================ Debug ================
// Prints pair in (x, y) format to the command line
void Coordinate::print_pair() {
    printf("(%d, %d) ", x, y);
}