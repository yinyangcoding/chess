#include "../../include/objects/Player.hpp"

// ================ Constructors ================
// Default Constructor
Player::Player() {
    color = 'n';
    points = 0;
}

// Sets given color: b or w / Sets points to 0
Player::Player(char c) {
    color = c;
    points = 0;
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

// // Returns captured vector
// vector<Piece>& Player::get_captured() {
//     return captured;
// }

// // Returns onBoard vector
// vector<Piece>& Player::get_onBoard() {
//     return onBoard;
// }

// // Returns lost vector
// vector<Piece>& Player::get_lost() {
//     return lost;
// }


// ============== Setters ================
// Sets color
void Player::set_color(char c) {
    color = c;
}

// Sets points
void Player::set_points(int p) {
    points = p;
}


// ================ Methods ================
// Removes piece from onBoard and puts it in taken. Returns if successful
// bool Player::lose(Piece& a) {
//     if(Tools::contains(onBoard, a)) {
//         int index = Tools::index(onBoard, a);

//         Piece temp;
//         temp.copy_from(onBoard[index]);

//         vector<Piece>::iterator it = onBoard.begin() + index;

//         onBoard.erase(it);
//         lost.push_back(temp);

//         return true;
//     }
//     return false;
// }