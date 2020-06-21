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
    if (Move::on_board(loc.get_x() + increment) // on board
        && (board.get_piece(loc.get_y(), loc.get_x() + increment).is_blank())) { // is blank
        // add space in front of pawn to hold
        hold.push_back(Coordinate(loc.get_y(), loc.get_x() + increment));
        // if pawn is still in starting position and space 2 spaces in front of pawn is blank
        if ((((increment == 1) && (loc.get_x() == 1)) || ((increment == -1) && (loc.get_x() == (SIZE - 2)))) // starting position
        && (board.get_piece(loc.get_y(), loc.get_x() + (2 * increment)).is_blank())) { // is blank
            // add space 2 spaces in front of pawn to hold
            hold.push_back(Coordinate(loc.get_y(), (loc.get_x() + (2 * increment))));
        }
    }
    // if space in front of pawn to the left is on board and is not blank
    if (Move::on_board(loc.get_y() - 1, loc.get_x() + increment) // on board
        && (!board.get_piece(loc.get_y() - 1, loc.get_x() + increment).is_blank())) { // is not blank
        // add space in front of pawn to the left to hold
        hold.push_back(Coordinate(loc.get_y() - 1, loc.get_x() + increment));
    }
    // if space in front of pawn to the right is on board and is not blank
    if (Move::on_board(loc.get_y() + 1, loc.get_x() + increment) // on board
        && (!board.get_piece(loc.get_y() + 1, loc.get_x() + increment).is_blank())) { // is not blank
        // add space in front of pawn to the right to hold
        hold.push_back(Coordinate(loc.get_y() + 1, loc.get_x() + increment));
    }
    piece.set_moves(hold);
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_knight(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_knight()\n");
    }
    // makes holder vector for moves
    vector<Coordinate> hold;
    // stores piece location so does not have to keep referencing for speed enhancements
    int x = piece.get_location().get_x();
    int y = piece.get_location().get_y();
    // stores piece color
    int color = piece.get_color();

    // i = -1, 1
    for (int i = -1; i <= 1; i += 2) {
        // j = -2, 2
        for (int j = -2; j <= 2; j += 4) {
            // checks if pos (x + i, y + j) is on board and the piece there is not the same color 
            if (Move::on_board(x + i, y + j) && board.get_piece(x + i, y + j).get_color() != color) {
                hold.push_back(Coordinate(x + i, y + j));
            }
            // checks if pos (x + j, y + i) is on board and the piece there is not the same color 
            if (Move::on_board(x + j, y + i) && board.get_piece(x + j, y + i).get_color() != color) {
                hold.push_back(Coordinate(x + j, y + i));
            }
        }
    }
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_bishop(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_bishop()\n");
    }
    // stores piece location so does not have to keep referencing for speed enhancements
    Coordinate loc = piece.get_location();
    // makes holder vector for moves
    vector<Coordinate> hold;
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING UP-LEFT
    for (int i = loc.get_y() - 1, j = loc.get_x() - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j--) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING UP-RIGHT
    for (int i = loc.get_y() + 1, j = loc.get_x() - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j--) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING DOWN-LEFT
    for (int i = loc.get_y() - 1, j = loc.get_x() + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j++) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING DOWN-RIGHT
    for (int i = loc.get_y() + 1, j = loc.get_x() + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j++) {
        hold.push_back(Coordinate(i, j));
    }
    piece.set_moves(hold);
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_rook(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_rook()\n");
    }
    // stores piece location so does not have to keep referencing for speed enhancements
    Coordinate loc = piece.get_location();
    // makes holder vector for moves
    vector<Coordinate> hold;
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING LEFT
    for (int i = loc.get_y() - 1; (Move::on_board(i) && board.get_piece(i, loc.get_x()).get_color() != color); i--) {
        hold.push_back(Coordinate(i, loc.get_x()));
    }
    // MOVING RIGHT
    for (int i = loc.get_y() + 1; (Move::on_board(i) && board.get_piece(i, loc.get_x()).get_color() != color); i++) {
        hold.push_back(Coordinate(i, loc.get_x()));
    }
    // MOVING UP
    for (int i = loc.get_x() - 1; (Move::on_board(i) && board.get_piece(loc.get_y(), i).get_color() != color); i--) {
        hold.push_back(Coordinate(loc.get_y(), i));
    }
    // MOVING DOWN
    for (int i = loc.get_x() + 1; (Move::on_board(i) && board.get_piece(loc.get_y(), i).get_color() != color); i++) {
        hold.push_back(Coordinate(loc.get_y(), i));
    }
    piece.set_moves(hold);
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_queen(Board board, Piece piece) {
    if(DEBUG) {
        printf("Move::update_queen()\n");
    }
    // stores piece location so does not have to keep referencing for speed enhancements
    Coordinate loc = piece.get_location();
    // makes holder vector for moves
    vector<Coordinate> hold;
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING LEFT
    for (int i = loc.get_y() - 1; (Move::on_board(i) && board.get_piece(i, loc.get_x()).get_color() != color); i--) {
        hold.push_back(Coordinate(i, loc.get_x()));
    }
    // MOVING RIGHT
    for (int i = loc.get_y() + 1; (Move::on_board(i) && board.get_piece(i, loc.get_x()).get_color() != color); i++) {
        hold.push_back(Coordinate(i, loc.get_x()));
    }
    // MOVING UP
    for (int i = loc.get_x() - 1; (Move::on_board(i) && board.get_piece(loc.get_y(), i).get_color() != color); i--) {
        hold.push_back(Coordinate(loc.get_y(), i));
    }
    // MOVING DOWN
    for (int i = loc.get_x() + 1; (Move::on_board(i) && board.get_piece(loc.get_y(), i).get_color() != color); i++) {
        hold.push_back(Coordinate(loc.get_y(), i));
    }
    // MOVING UP-LEFT
    for (int i = loc.get_y() - 1, j = loc.get_x() - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j--) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING UP-RIGHT
    for (int i = loc.get_y() + 1, j = loc.get_x() - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j--) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING DOWN-LEFT
    for (int i = loc.get_y() - 1, j = loc.get_x() + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j++) {
        hold.push_back(Coordinate(i, j));
    }
    // MOVING DOWN-RIGHT
    for (int i = loc.get_y() + 1, j = loc.get_x() + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j++) {
        hold.push_back(Coordinate(i, j));
    }
    piece.set_moves(hold);
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
    for (int x = loc.get_y() - 1; x <= loc.get_y() + 1; x++) {
        // Proceeds to next x-position if x is not on board
        if (Move::on_board(x)) {
            // Runs through y-position to the left, current, and to the right of current location
            for (int y = loc.get_x() - 1; y <= loc.get_x() + 1; y++) {
                // Proceeds to next y-position if current position is current location
                if ((x != loc.get_y()) || (y != loc.get_x())) {
                    // Proceeds to next y-position if y is not on board
                    if (Move::on_board(y)) {
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


// checks if one pos is btwn -1 and SIZE
bool Move::on_board(int c) {
    return ((c > -1) && (c < SIZE));
}


// checks if both pos are btwn -1 and SIZE
bool Move::on_board(int x, int y) {
    return ((x > -1) && (x < SIZE) && (y > -1) && (y < SIZE));
}

// Swaps two pieces
// From piece references
void Move::swap(Piece &a, Piece &b) {
    // Make a temp holder
    Piece temp;
    temp.copy_from(b);

    // Put a traits in b
    b.set_id(a.get_id());
    b.set_color(a.get_color());
    b.set_point(a.get_point());
    b.set_type(a.get_color());

    // Put temp traits in a
    a.set_id(temp.get_id());
    a.set_color(temp.get_color());
    a.set_point(temp.get_point());
    a.set_type(temp.get_color());


}
// From coords
void Move::swap(Board &board, Coordinate a, Coordinate b) {
    
}
