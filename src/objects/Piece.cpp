#include "../../include/objects/Piece.hpp"

using namespace std;

// ============= Constructors ==============
// Creates piece with given type
Piece::Piece(int t) {
    type = t;
    idCount++;
    id = idCount;

    assign_point();
}

// Creates piece with given type and given color
Piece::Piece(int t, char c) {
    type = t;
    idCount++;
    id = idCount;

    assign_point();
    color = c;
}

// Creates blank piece
Piece::Piece() {
    make_blank();
}

// ============= Setters ==============
void Piece::set_location(Coordinate a) {
    location.copy_from(a);
}
void Piece::set_id(int i) {
    id = i;
}
void Piece::set_point(int i) {
    point = i;
}
void Piece::set_type(int i) {
    type = i;
}
void Piece::set_color(char c) {
    color = c;
}

// ============== Getters ================
// Returns id
int Piece::get_id() {
    return id;
}

// Returns point val
int Piece::get_point() {
    return point;
}

// Returns type num
int Piece::get_type() {
    return type;
}

// Returns color char
char Piece::get_color() {
    return color;
}

// Returns location Coordinate
Coordinate Piece::get_location() {
    return location;
}

// Returns possible moves
vector<Coordinate> Piece::get_moves() {
    return moves;
}

// ============= Methods ==============
// Returns if a equals this by id
bool Piece::equals(Piece a) {
    if(id == a.get_id()) {
        return true;
    }
    return false;
}

// Sets point val with switch from type
void Piece::assign_point() {
    switch(type) {
        case 1: point = 1;
            break;
        case 2: point = 3;
            break;
        case 3: point = 3;
            break;
        case 4: point = 5;
            break;
        case 5: point = 9;
            break;
        case 6: point = 2147483647;
            break;
        default: point = -1;
            break;
    }
}

// Copies a traits to this
void Piece::copy_from(Piece a) {
    id = a.get_id();
    type = a.get_type();
    color = a.get_color();
    point = a.get_point();
}

// Returns if the piece is a blank placeholder
bool Piece::is_blank() {
    // Checks for all traits of a blank piece
    return id == -1;
}

// Makes the piece a blank placeholder
void Piece::make_blank() {
    id = -1;
    type = -1;
    color = 'n';
    point = -1;
}

// swaps pieces
void Piece::swap(Piece a) {
    Piece temp;
    temp.copy_from(a);

    // Set all of a's to this'
    a.set_id(id);
    a.set_point(point);
    a.set_type(type);
    a.set_color(color);

    // Set all of this' to a
    id = temp.get_id();
    point = temp.get_point();
    type = temp.get_type();
    color = temp.get_color();
    
}

// Sets idCount to 0 to allow incrementing
int Piece::idCount {};