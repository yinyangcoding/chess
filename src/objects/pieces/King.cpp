#include "../../../include/objects/pieces/King.hpp"

King::King(char c) : Piece::Piece(6, c) {

}

/* For King especially, much more must be done to update possible moves considering check
void King::update() {
    // Resets possible moves
    moves.clear();
    // Runs through x-position to the left, current, and to the right of current location
    for (int x = location.get_x() - 1; x <= location.get_x() + 1; x++) {
        // Proceeds to next x-position if current x-position is out of bounds
        if ((x > -1) && (x < SIZE)) {
            // Runs through y-position to the left, current, and to the right of current location
            for (int y = location.get_y() - 1; y <= location.get_y() + 1; y++) {
                // Proceeds to next y-position if current position is current location
                if ((x != location.get_x()) || (y != location.get_y())) {
                    // Proceeds to next y-position if current y-position is out of bounds
                    if ((y > -1) && (y < SIZE)) {
                        // MUST ALSO CHECK IF MOVE PUTS KING IN DANGER
                        // Add coordinate(x,y) to possible moves if it passed all checks
                        moves.push_back(Coordinate(x, y));
                    }
                }
            }
        } 
    }
}
*/
