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

// STILL MUST COMPUTE FOR CHECK
void Move::update_pawn(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_pawn()\n");
    }
    // stores piece location so does not have to keep referencing for speed enhancements
    Coordinate loc = piece.get_location();
    // makes holder vector for moves
    vector<Coordinate> hold;
    // increment (the y-direction pawn moves in) is set based on color
    int increment;
    if (piece.get_color() == 'b') {
        increment = 1;
    } else {
        increment = -1;
    }
    // if space in front of pawn is on board and is blank
    if (((loc.get_y() + increment) < SIZE) && ((loc.get_y() + increment) > -1)  // on board
        && (board.get_piece(loc.get_x(), loc.get_y() + increment).is_blank())) { // is blank
        // add space in front of pawn to hold
        hold.push_back(Coordinate(loc.get_x(), loc.get_y() + increment));
        // if pawn is still in starting position and space 2 spaces in front of pawn is blank
        if ((((increment == 1) && (loc.get_y() == 1)) || ((increment == -1) && (loc.get_y() == (SIZE - 2)))) // starting position
        && (board.get_piece(loc.get_x(), loc.get_y() + (2 * increment)).is_blank())) { // is blank
            // add space 2 spaces in front of pawn to hold
            hold.push_back(Coordinate(loc.get_x(), (loc.get_y() + (2 * increment))));
        }
    }
    // if space in front of pawn to the left is on board and is not blank
    if (((loc.get_y() + increment) < SIZE) && ((loc.get_y() + increment) > -1) // on board (y)
        && ((loc.get_x() - 1) < SIZE) && ((loc.get_x() - 1) > -1) // on board (x)
        && (!board.get_piece(loc.get_x() - 1, loc.get_y() + increment).is_blank())) { // is not blank
        // add space in front of pawn to the left to hold
        hold.push_back(Coordinate(loc.get_x() - 1, loc.get_y() + increment));
    }
    // if space in front of pawn to the right is on board and is not blank
    if (((loc.get_y() + increment) < SIZE) && ((loc.get_y() + increment) > -1) // on board (y)
        && ((loc.get_x() + 1) < SIZE) && ((loc.get_x() + 1) > -1) // on board (x)
        && (!board.get_piece(loc.get_x() + 1, loc.get_y() + increment).is_blank())) { // is not blank
        // add space in front of pawn to the right to hold
        hold.push_back(Coordinate(loc.get_x() + 1, loc.get_y() + increment));
    }
    piece.set_moves(hold);
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