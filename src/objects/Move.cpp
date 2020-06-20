#include "../../include/objects/Move.hpp"

// ============= Methods =============
// Switch to decide which piece to operate on
void Move::update_moves(Board b, Piece p) {
    if(DEBUG) {
        printf("Move::update_moves()\n");
    }
    switch(p.get_type()) {
        case 1:
            update_pawn(b, p);
            break;
        case 2:
            update_knight(b, p);
            break;
        case 3:
            update_bishop(b, p);
            break;
        case 4:
            update_rook(b, p);
            break;
        case 5:
            update_queen(b, p);
            break;
        case 6:
            update_king(b, p);
            break;
        default:
            return;
    }
}

// pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
// Piece specific updates, private
void Move::update_pawn(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_pawn()\n");
    }
}
void Move::update_knight(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_knight()\n");
    }
}
void Move::update_bishop(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_bishop()\n");
    }
}
void Move::update_rook(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_rook()\n");
    }
}
void Move::update_queen(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_queen()\n");
    }
}
// STILL MUST COMPUTE FOR CHECK
void Move::update_king(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_king()\n");
    }
    // stores piece location so does not have to keep referencing for speed enhancements
    Coordinate loc = piece.get_location();
    // makes holder vector for moves
    vector<Coordinate> hold;
    // Runs through x-position to the left, current, and to the right of current location
    for (int x = loc.get_x() - 1; x <= loc.get_x() + 1; x++) {
        // Proceeds to next x-position if current x-position is out of bounds
        if ((x > -1) && (x < SIZE)) {
            // Runs through y-position to the left, current, and to the right of current location
            for (int y = loc.get_y() - 1; y <= loc.get_y() + 1; y++) {
                // Proceeds to next y-position if current position is current location
                if ((x != loc.get_x()) || (y != loc.get_y())) {
                    // Proceeds to next y-position if current y-position is out of bounds
                    if ((y > -1) && (y < SIZE)) {
                        // MUST ALSO CHECK IF MOVE PUTS KING IN DANGER
                        // Add coordinate(x,y) to possible moves if it passed all checks
                        hold.push_back(Coordinate(x, y));
                    }
                }
            }
        } 
    }
    piece.set_moves(hold);
}