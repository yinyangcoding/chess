#include "../../../include/objects/pieces/Pawn.hpp"

Pawn::Pawn(char c) : Piece::Piece(1, c) {
    
}

void Pawn::update() {
    // increment (the y-direction pawn moves in) is set based on color
    int increment;
    if (color == 'b') {
        increment = 1;
    } else {
        increment = -1;
    }
    // for space directly in front of pawn
    // if (board[location.get_x()][location.get_y()+increment])

    // PROMBLEM: BOARD MUST BE WRITTEN IN MAIN
    // BOARD CANNOT BE ACCESSED THIS WAY BC NOT YET ACTUALLY DEFINED
    // MUST CHANGE STRUCTURE SOMEHOW

    // for space two spaces in front of pawn

    // for spaces to the right and left
}