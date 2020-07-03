#include "../../include/objects/Player.hpp"

// ================ Constructors ================
// Default Constructor
Player::Player() {
    BTools::debug("Player::Player()");
    color = 'n';
    points = 0;
    king = nullptr;
}

// Sets given color: b or w / Sets points to 0
Player::Player(char c) {
    BTools::debug("Player::Player(char)");
    color = c;
    points = 0;
    king = nullptr;
}


// ============== Getters ================
// Returns color
char Player::get_color() const {
    return color;
}

// Returns points
int Player::get_points() const {
    return points;
}

// Returns pointer to king
Piece* Player::get_king() {
    return king;
}


// ============== Setters ================
// Sets color
void Player::set_color(char c) {
    color = c;
}

// Sets points
void Player::set_points(int p) {
    points = p;
}

// Set king
void Player::set_king(Piece& p) {
    king = &p;
}


// ================ Methods ================