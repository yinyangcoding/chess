#include "../../include/resources/Move.hpp"

// ============= Methods =============
// pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
// Player specific updates
// void Move::update_player(Board& board, char color) {
//     vector<Piece>& alive = board.get_player(color).get_onBoard();
//     for (Piece& piece : alive) {
//         int y = 
//         Move::update_moves(board, board.get_piece())
//     }
// }

// Switch to decide which piece to operate on
void Move::update_moves(Board& b, Piece& p) {
    BTools::debug("void Move::update_moves(Board& b, Piece& p)");
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
void Move::update_pawn(Board& board, Piece& piece) {
    BTools::debug("void Move::update_pawn(Board& board, Piece& piece)");
    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 4 spots (MAX possible moves for pawn)
    moves.reserve(4);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();
    // increment (the y-direction pawn moves in) is set based on color
    int increment;
    if (piece.get_color() == 'b') {
        increment = 1;
    } else {
        increment = -1;
    }

    // if space in front of pawn is on board and is blank
    if (Move::on_board(y + increment) && (board.get_piece(y + increment, x).is_blank())) {
        // add space in front of pawn to hold
        moves.emplace_back(y + increment, x);
        // if pawn is still in starting position and space 2 spaces in front of pawn is blank
        if ((((increment == 1) && (y == 1)) || ((increment == -1) && (y == (SIZE - 2)))) // starting position
        && (board.get_piece(y + (2 * increment), x).is_blank())) { // is blank
            // add space 2 spaces in front of pawn to hold
            moves.emplace_back(y + (2 * increment), x);
        }
    }
    // if space in front of pawn to the left is on board and is not blank
    if (Move::on_board(y + increment, x - 1) // on board
        && (!board.get_piece(y + increment, x - 1).is_blank())) { // is not blank
        // add space in front of pawn to the left to hold
        moves.emplace_back(y + increment, x - 1);
    }
    // if space in front of pawn to the right is on board and is not blank
    if (Move::on_board(y + increment, x + 1) // on board
        && (!board.get_piece(y + increment, x + 1).is_blank())) { // is not blank
        // add space in front of pawn to the left to hold
        moves.emplace_back(y + increment, x + 1);
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_knight(Board& board, Piece& piece) {
    BTools::debug("void Move::update_knight(Board& board, Piece& piece)");

    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 8 spots (MAX possible moves for knight)
    moves.reserve(8);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();
    // stores piece color
    int color = piece.get_color();

    // i = -1, 1
    for (int i = -1; i < 2; i += 2) {
        // j = -2, 2
        for (int j = -2; j < 3; j += 4) {
            // checks if pos (x + i, y + j) is on board and the piece there is not the same color 
            if (Move::on_board(y + i, x + j) && board.get_piece(y + i, x + j).get_color() != color) {
                moves.emplace_back(y + i, x + j);
            }
            // checks if pos (x + j, y + i) is on board and the piece there is not the same color 
            if (Move::on_board(y + j, x + i) && board.get_piece(y + j, x + i).get_color() != color) {
                moves.emplace_back(y + j, x + i);
            }
        }
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_bishop(Board& board, Piece& piece) {
    BTools::debug("void Move::update_bishop(Board& board, Piece& piece)");

    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 13 spots (MAX possible moves for bishop)
    moves.reserve(13);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING UP-LEFT
    for (int i = y - 1, j = x - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j--) {
        moves.emplace_back(i, j);
    }
    // MOVING UP-RIGHT
    for (int i = y - 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j++) {
        moves.emplace_back(i, j);
    }
    // MOVING DOWN-LEFT
    for (int i = y + 1, j = x - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j--) {
        moves.emplace_back(i, j);
    }
    // MOVING DOWN-RIGHT
    for (int i = y + 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j++) {
        moves.emplace_back(i, j);
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_rook(Board& board, Piece& piece) {
    BTools::debug("void Move::update_rook(Board& board, Piece& piece)");
    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 14 spots (MAX possible moves for rook)
    moves.reserve(14);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING UP
    for (int i = y - 1; (Move::on_board(i) && board.get_piece(i, x).get_color() != color); i--) {
        moves.emplace_back(i, x);
    }
    // MOVING DOWN
    for (int i = y + 1; (Move::on_board(i) && board.get_piece(i, x).get_color() != color); i++) {
        moves.emplace_back(i, x);
    }
    // MOVING LEFT
    for (int i = x - 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i--) {
        moves.emplace_back(y, i);
    }
    // MOVING RIGHT
    for (int i = x + 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i++) {
        moves.emplace_back(y, i);
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_queen(Board& board, Piece& piece) {
    BTools::debug("void Move::update_queen(Board& board, Piece& piece)");

    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 27 spots (MAX possible moves for queen)
    moves.reserve(27);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();
    // stores piece color
    int color = piece.get_color();

    // Outline for all directions: 
    // if on board and the piece at location is not the same color -->
    // add that location and keep checking positions in that direction

    // MOVING UP
    for (int i = y - 1; (Move::on_board(i) && board.get_piece(i, x).get_color() != color); i--) {
        moves.emplace_back(i, x);
    }
    // MOVING DOWN
    for (int i = y + 1; (Move::on_board(i) && board.get_piece(i, x).get_color() != color); i++) {
        moves.emplace_back(i, x);
    }
    // MOVING LEFT
    for (int i = x - 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i--) {
        moves.emplace_back(y, i);
    }
    // MOVING RIGHT
    for (int i = x + 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i++) {
        moves.emplace_back(y, i);
    }
    // MOVING UP-LEFT
    for (int i = y - 1, j = x - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j--) {
        moves.emplace_back(i, j);
    }
    // MOVING UP-RIGHT
    for (int i = y - 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j++) {
        moves.emplace_back(i, j);
    }
    // MOVING DOWN-LEFT
    for (int i = y + 1, j = x - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j--) {
        moves.emplace_back(i, j);
    }
    // MOVING DOWN-RIGHT
    for (int i = y + 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j++) {
        moves.emplace_back(i, j);
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// STILL MUST COMPUTE FOR CHECK
void Move::update_king(Board& board, Piece& piece) {
    BTools::debug("void Move::update_king(Board& board, Piece& piece)");

    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    moves.clear();
    // reserves 8 spots (MAX possible moves for king)
    moves.reserve(8);
    // stores piece location so does not have to keep referencing for speed enhancements
    int y = piece.get_location().get_y();
    int x = piece.get_location().get_x();

    // Runs through y-position to the up, current, and down of current location
    for (int i = y - 1; i < y + 2; i++) {
        // Checks if y is on board
        if (Move::on_board(i)) {
            // Runs through x-position to the left, current, and to the right of current location
            for (int j = x - 1; j < x + 2; j++) {
                // Checks if x is on board
                    if (Move::on_board(j)) {
                    // Makes sure (i, j) is not current location
                    if ((i != y) || (j != x)) {
                        // MUST ALSO CHECK IF MOVE PUTS KING IN DANGER
                        // Add coordinate (y, x) to possible moves if it passed all checks
                        moves.emplace_back(i, j);
                    }
                }
            }
        } 
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


// checks if one pos is btwn -1 and SIZE
bool Move::on_board(int c) {
    BTools::debug("bool Move::on_board(int c)");
    return ((c > -1) && (c < SIZE));
}


// checks if both pos are btwn -1 and SIZE
bool Move::on_board(int y, int x) {
    BTools::debug("bool Move::on_board(int y, int x)");
    return ((y > -1) && (y < SIZE) && (x > -1) && (x < SIZE));
}

// Swaps two pieces
// From piece references
void Move::swap(Piece& a, Piece& b) {
    BTools::debug("void Move::swap(Piece& a, Piece& b)");

    // Make a temp holder
    Piece temp;
    Coordinate loc;

    temp.copy_from(b);
    loc.set_coord(b.get_location().get_y(), b.get_location().get_x());

    // Put a traits in b
    b.copy_from(a);
    b.set_location(a.get_location());

    // Put temp traits in a
    a.copy_from(temp);
    a.set_location(loc);

}

// From coords
void Move::swap(Board& board, Coordinate a, Coordinate b) {
    BTools::debug("void Move::swap(Board& board, Coordinate a, Coordinate b)");

    Piece& from = board.board[a.get_y()][a.get_x()];
    Piece& to = board.board[b.get_y()][b.get_x()];

    Move::swap(to, from);
}

// checks if king is in check, checkmate, or stalemate
// none = -1, stalemate = 0, check = 1, checkmate = 2
// int Move::check_position(Board& board, Coordinate king) {
//     BTools::debug("int Move::check_position(Board& board, Coordinate king)");

//     bool check = Move::in_check(board, king);
//     bool surround = Move::surrounding_check(board, king);
//     if (!check && !surround) {
//         return -1;
//     } else if (check && !surround) {
//         return 0;
//     } else if (!check && surround) {
//         return 1;
//     } else {
//         return 2;
//     }
// }


// returns true if in check
// bool Move::in_check(Board& board, Coordinate king) {
//     BTools::debug("bool Move::in_check(Board& board, Coordinate king)");

//     // holds the moves vector for each piece
//     vector<Coordinate> *moves;
//     // stores piece location so does not have to keep referencing for speed enhancements
//     int y = king.get_y();
//     int x = king.get_x();

//     // runs through all pieces on board 
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {            
//             // skips blank pieces
//             if (!board.get_piece(i, j)->is_blank()) {
//                 // makes sure it does not check the king
//                 if ((i != y) || (j != x)) {
//                     // grabs moves vector from piece
//                     moves = board.get_piece(i, j)->get_moves();
//                     // runs through all Coordinates in moves vector
//                     for (int m = 0; m < moves->size(); m++) {
//                         // sees if Coordinate king and the Coordinate from moves are the same
//                         if (king.equals(moves->at(m))) {
//                             return true;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }


// return true if Coordinates surrounding king are all in check
// bool Move::surrounding_check(Board& board, Coordinate king) {
//     BTools::debug("bool Move::surrounding_check(Board& board, Coordinate king)");
//     // stores piece location so does not have to keep referencing for speed enhancements
//     int y = king.get_y();
//     int x = king.get_x();

//     // Runs through y-position to the up, current, and down of current location
//     for (int i = y - 1; i <= y + 1; i++) {
//         // Checks if y is on board
//         if (Move::on_board(i)) {
//             // Runs through x-position to the left, current, and to the right of current location
//             for (int j = x - 1; j <= x + 1; j++) {
//                 // Makes sure (i, j) is not current location
//                 if ((i != y) || (j != x)) {
//                     // Checks if x is on board
//                     if (Move::on_board(j)) {
//                         // if (i,j) is not in check exit returning false
//                         if (!Move::in_check(board, Coordinate(i, j))) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         } 
//     }
//     return true;
// }

// A captures B
// From piece references
void Move::replace(Piece& a, Piece& b) {
    BTools::debug("void Move::replace(Piece& a, Piece& b)");

    b.copy_from(a);
    b.set_location(a.get_location());
    a.make_blank();
}

// From coords
void Move::replace(Board& board, Coordinate a, Coordinate b) {
    BTools::debug("void Move::replace(Board& board, Coordinate a, Coordinate b)");

    Piece *from = &board.board[a.get_y()][a.get_x()];
    Piece *to = &board.board[b.get_y()][b.get_x()];

    Move::replace(*from, *to);
}


// Main Move function that will consider all needed methods
// Returns a piece if captured. Returns blank if not
// Moves from a to b
Piece Move::move(Board& board, Coordinate a, Coordinate b) {
    BTools::debug("Piece Move::move(Board& board, Coordinate a, Coordinate b)");
    Piece blank; // Makes blank piece for future return needs
    bool capture = false; // True if the move is a capture
    bool canMove = false; // If it can move there

    // Exit if there's no piece to move
    if(!board.has_piece(a)) {
        return blank;
    }

    Piece& moving = board.get_piece(a);
    Piece& cap = board.get_piece(b);

    // Update the moving piece's moves
    Move::update_moves(board, moving);

    printf("ID = %d\n", cap.get_id());
    if(!cap.is_blank()) {
        capture = true;
        printf("RAN\n");

    }

    // Check if move is legal and within movese
    vector<Coordinate>& moves = moving.get_moves();
    for(int i = 0; i < moves.size(); i++) {
        // moves[i].print_pair();
        if(moves[i].equals(b)) {
            canMove = true;
            break;
        }
    }

    // Exit if it can't move
    if(!canMove) {
        return blank;
    }
    
    if(capture) {
        // Capture the piece
        Move::replace(moving, cap);

        // ADD IT TO CAPTURING PLAYER'S TAKEN AND OTHER PLAYER'S LOST



        return cap;

    }
    else {
        // Swap the piece if it doesn't need to capture
        // Move the piece
        Move::swap(moving, cap);

        return blank;
    }


}