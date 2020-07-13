#include "../../include/resources/Move.hpp"

// Saves all moves
std::vector<Displace> turns;

// En Passant resources
bool enPassant = false;
Piece* passantVic = NULL;
Coordinate passantVicLoc;

// ============= Methods =============
// pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
// Player specific updates
void Move::update_player(Board& board, char color) {
    BTools::debug("void Move::update_player(Board& board, char color)");
    // Stores either aliveWhite or aliveBlack based on color indicated
    Coordinate* alive = board.get_alive(color);
    
    //for (int i = 0; i < 16; i++) {
    //    alive[i].print_pair();
    //}

    // Runs through alive (length of alive will always be 16)
    for (int i = 0; i < 16; i++) {
        // Checks if alive[i] holds a blank Coordinate (-1, -1)
        if (!alive[i].is_blank()){
            // Updates appropriate piece by Coordinate if alive[i] is not blank
            Move::update_moves(board, board.get_piece(alive[i]));
        }
    }
}

// Switch to decide which piece to operate on
void Move::update_moves(Board& b, Piece& p) {
    BTools::debug("void Move::update_moves(Board& b, Piece& p)");
    switch (p.get_type()) {
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
    return;
}


// pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
// Piece specific updates, private


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
    }
    else {
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


void Move::update_bishop(Board& board, Piece& piece) {
    BTools::debug("void Move::update_bishop(Board& board, Piece& piece)");

    // gets address of moves and clears it
    vector<Coordinate>& moves = piece.get_moves();
    // Only clear if it's a bishop, this lets queen work
    if (piece.get_type() == 3) {
        moves.clear();
    }
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
        if (!board.get_piece(i, j).is_blank()) {
            break;
        }
    }
    // MOVING UP-RIGHT
    for (int i = y - 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i--, j++) {
        moves.emplace_back(i, j);
        if (!board.get_piece(i, j).is_blank()) {
            break;
        }
    }
    // MOVING DOWN-LEFT
    for (int i = y + 1, j = x - 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j--) {
        moves.emplace_back(i, j);
        if (!board.get_piece(i, j).is_blank()) {
            break;
        }
    }
    // MOVING DOWN-RIGHT
    for (int i = y + 1, j = x + 1; (Move::on_board(i, j) && board.get_piece(i, j).get_color() != color); i++, j++) {
        moves.emplace_back(i, j);
        if (!board.get_piece(i, j).is_blank()) {
            break;
        }
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


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
        if (!board.get_piece(i, x).is_blank()) {
            break;
        }
    }
    // MOVING DOWN
    for (int i = y + 1; (Move::on_board(i) && board.get_piece(i, x).get_color() != color); i++) {
        moves.emplace_back(i, x);
        if (!board.get_piece(i, x).is_blank()) {
            break;
        }
    }
    // MOVING LEFT
    for (int i = x - 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i--) {
        moves.emplace_back(y, i);
        if (!board.get_piece(y, i).is_blank()) {
            break;
        }
    }
    // MOVING RIGHT
    for (int i = x + 1; (Move::on_board(i) && board.get_piece(y, i).get_color() != color); i++) {
        moves.emplace_back(y, i);
        if (!board.get_piece(y, i).is_blank()) {
            break;
        }
    }
    // readjusts moves to its correct size
    moves.shrink_to_fit();
}


void Move::update_queen(Board& board, Piece& piece) {
    BTools::debug("void Move::update_queen(Board& board, Piece& piece)");

    // Add rook moves
    Move::update_rook(board, piece);

    // Add bishop moves
    Move::update_bishop(board, piece);

}


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


// Checks if one pos is btwn -1 and SIZE
bool Move::on_board(int c) {
    BTools::debug("bool Move::on_board(int c)");

    return ((c > -1) && (c < SIZE));
}


// Checks if both pos are btwn -1 and SIZE
bool Move::on_board(int y, int x) {
    BTools::debug("bool Move::on_board(int y, int x)");

    return ((y > -1) && (y < SIZE) && (x > -1) && (x < SIZE));
}


// Checks if both pos are btwn -1 and SIZE from Coordinate
bool Move::on_board(Coordinate loc) {
    BTools::debug("bool Move::on_board(Coordinate loc)");

    return Move::on_board(loc.get_y(), loc.get_x());
}


// checks if king of color c is in check, checkmate, or stalemate
// neutral = -1, stalemate = 0, check = 1, checkmate = 2
int Move::game_status(Board& board, char c) {
    BTools::debug("int Move::game_status(Board& board, char c)");

    // Stores location of king
    Coordinate king = board.get_king(c)->get_location();

    //printf("King location: "); king.print_pair();

    // Holds whether king is in check
    bool check = Move::in_check(board, c, king, false);
    // Holds whether all locations around king are in check
    bool surround = Move::surrounding_check(board, c, king, check);

    //printf("Check: %d\nSurround: %d\n", check, surround);

    // Returns -1 (neutral) if king is not in check nor surrounding check
    if (!check && !surround) {
        return -1;
    // Returns 0 (stalemate) if king is in surrounding check but not in check
    } else if (!check && surround) {
        return 0;
    // Returns 1 (check) if king is in check but not in surrounding check
    } else if (check && !surround) {
        return 1;
    // Checkmate possibility if king is in check and surrounding check
    } else {
        // Returns 2 (checkmate) if king cannot eat pieces putting it in check
        if (Move::in_check(board, c, king, true)) {
            return 2;
        }
        // Returns 1 (check) if king can eat pieces putting it in check
        return 1;
    }
}


// returns true if in check
bool Move::in_check(Board& board, char color, Coordinate king, bool end) {
    BTools::debug("bool Move::in_check(Board& board, char color, Coordinate king, bool end)");

    // Stores piece location so does not have to keep referencing for speed enhancements
    int y = king.get_y();
    int x = king.get_x();

    // Stores enemy color
    char enemy;
    if (color == 'w') {
        enemy = 'b';
    }
    else {
        enemy = 'w';
    }
    
    // Holds Coordinates of every alive piece of the opposite color of king
    Coordinate* alive = board.get_alive(enemy);
    // Holds pointers to moves vectors for each piece of the opposite color of king
    vector<Coordinate>** moves = board.get_moves(enemy);

    // Runs through all Coordinates in alive 
    for (int i = 0; i < 16; i++) {
        // Makes sure alive[i] is not blank
        if (!alive[i].is_blank()) {
            //alive[i].print_pair();
            //king.print_pair();
            //if (alive[i].equals(king)) {
            //    continue;
            //}
            // Sets piece to the piece at Coordinate alive[i]
            Piece& piece = board.get_piece(alive[i]);
            // Runs through moves[i]

            //printf("Type: %d\t\t", piece.get_type());
            //alive[i].print_pair();

            for (int j = 0; j < moves[i]->size(); j++) {

                //moves[i]->at(j).print_pair();

                //  Checks if Coordinate king and the Coordinate from moves are the same
                if (king.equals(moves[i]->at(j))) {
                    
                    // Returns true if no end game possibility
                    if (!end) {
                        return true;
                    }

                    // Checks if the piece that is putting king in check can be eaten if end game possibility
                    if (!Move::in_check(board, enemy, alive[i], false)) {
                        
//BIG LOGIC NOTE FOR LATER: if king is the only one who can eat then eat update everything if king is in check checkmate
                        //alive[i].print_pair();
                        //moves[i]->at(j).print_pair();
                        //printf("Is Piece Putting King In Check, In Check: %d\n", Move::in_check(board, enemy, alive[i], false));
                        
                        return true;
                    }
                    
                }
            }
        }
    }
    return false;
}


// return true if Coordinates surrounding king are all in check
bool Move::surrounding_check(Board& board, char color, Coordinate king, bool centerCheck) {
    BTools::debug("bool Move::surrounding_check(Board& board, Coordinate king)");

    // stores piece location so does not have to keep referencing for speed enhancements
    int y = king.get_y();
    int x = king.get_x();

    // Runs through y-position to the up, current, and down of current location
    for (int i = y - 1; i < y + 2; i++) {
        // Checks if y is on board
        if (Move::on_board(i)) {
            // Runs through x-position to the left, current, and to the right of current location
            for (int j = x - 1; j < x + 2; j++) {
                // Makes sure (i, j) is not current location
                if ((i != y) || (j != x)) {
                    // Checks if x-position is on board
                    if (Move::on_board(j)) {

                        //printf("Surround:  ");
                        //Coordinate(i, j).print_pair();
                        //printf("In Check: %d\n", Move::in_check(board, color, Coordinate(i, j), false));

                        // Exit returning false if (i,j) is not in check 
                        if (!Move::in_check(board, color, Coordinate(i, j), false)) {
                            // Checks if piece is blank if centerCheck is false (king is not in check) 
                            if (!centerCheck || board.get_piece(i, j).is_blank()) {
                                return false;
                            }
                        }
                    }
                }
            }
        } 
    }
    // Exit returning true if false was never returned (indicates all locations around king are in_check)
    return true;
}


// A captures B
// From piece references
void Move::replace(Board& board, Piece& a, Piece& b) {
    BTools::debug("void Move::replace(Board& board, Piece& a, Piece& b)");

    // "Moves" a to b using copy_from
    b.copy_from(a);
    // Clears a by making it blank
    a.make_blank(); // (location is not changed in make_blank so location is already correctly set)
    
}

// From coords
void Move::replace(Board& board, Coordinate a, Coordinate b) {
    BTools::debug("void Move::replace(Board& board, Coordinate a, Coordinate b)");

    Piece &from = board.board[a.get_y()][a.get_x()];
    Piece &to = board.board[b.get_y()][b.get_x()];

    Move::replace(board, from, to);
}


// Refreshes whiteMoves and blackMoves + aliveWhite and aliveBlack + all moves for indicated player
void Move::refresh(Board& board) {
    BTools::debug("void Move::refresh(Board& board)");

    // Runs through board refreshing whiteMoves and blackMoves + aliveWhite and aliveBlack
    board.refresh_moves();
    Move::update_player(board, 'w');
    Move::update_player(board, 'b');
}

// Promotes a pawn
void Move::promote(Board& board, Coordinate c, int n) {
    BTools::debug("void Move::promote(Board& board, Coordinate c, int n)");
    Piece& pawn = board.get_piece(c);

    pawn.set_type(n);

}

// Promotes a pawn from char
void Move::promote(Board& board, Coordinate c, char n) {
    BTools::debug("void Move::promote(Board& board, Coordinate c, char n)");
    n = BTools::to_lower(n);

    // Grab the int of the piece
    int nPiece;
    switch (n) {
        case 'n':
            nPiece = 2;
            break;
        case 'b':
            nPiece = 3;
            break;
        case 'r':
            nPiece = 4;
            break;
        case 'q':
            nPiece = 5;
            break;
        default:
            return;
            break;
    }

    // Run promote
    Move::promote(board, c, nPiece);

}

// Takes user input
void Move::promote_prompt(Board& board, Coordinate c) {
    BTools::debug("void Move::promote_prompt(Board& board, Coordinate c)");
    Piece& pawn = board.get_piece(c);

    // Exit if not a pawn
    if (pawn.get_type() != 1) {
        return;
    }

    // Find maxY coord

    int maxY = 0;
    if (pawn.get_color() == 'b') {
        maxY = SIZE - 1;
    }
    else if (pawn.get_color() == 'w') {
        maxY = 0;
    }
    else {
        return;

    }


    // Check if piece is not at the end of the board
    if (pawn.get_location().get_y() != maxY) {

        return;
    }

    // Prompt for promote
    std::string raw_input;
    char input;
    do {
        std::cout << "Pawn promotion...\nb = bishop, n = knight, r = rook, q = queen\nEnter choice:" << std::endl;
        std::getline(std::cin, raw_input);
        input = raw_input.at(0);

    } while (!(input == 'b' || input == 'n' || input == 'r' || input == 'q'));

    // Promote piece
    Move::promote(board, c, input);

}
// Checks if it can castle and if the move is a castle, then castles
bool Move::castle(Board& board, Coordinate from, Coordinate to) {
    BTools::debug("void Move::castle(Board& board, Coordinate from, Coordinate to)");
    // Pass it to castle with pieces
    return Move::castle(board, board.get_piece(from), to);


}
// From piece
bool Move::castle(Board& board, Piece& king, Coordinate to) {
    BTools::debug("void Move::castle(Board& board, Piece& moving, Piece& to)");
    char color;
    bool kingSide;
    bool queenSide;

    // Check if it's not a king
    if (king.get_type() != 6) {
        return false;
    }

    // Check if the king has moved
    if (king.hasMoved) {
        return false;
    }

    // Grab it's color
    color = king.get_color();
    char opColor;
    if (color == 'w') {
        opColor = 'b';
    }
    else if (color == 'b') {
        opColor = 'w';
    }
    else {
        return false;
    }

    // Check if it's kingside or queenside
    int y;
    char x;

    if (color == 'b') {
        y = 8;
    }
    else if (color == 'w') {
        y = 1;
    }
    else {
        return false;
    }

    kingSide = to.equals(Coordinate('g', y));
    queenSide = to.equals(Coordinate('c', y));
    
    // Exit if it's not a castle
    if (!(kingSide || queenSide)) {
        return false;
    }

    // Set the x char
    if (kingSide) {
        x = 'h';
    }
    else {
        x = 'a';
    }

    // Save the rook as an alias
    Piece& rook = board.get_piece(Coordinate(x, y));

    // Check if it's a rook
    if (rook.get_type() != 4) {
        return false;
    }

    // Check if the rook has moved
    if (rook.hasMoved) {
        return false;
    }

    // Exit if there are pieces in the way
    if (kingSide) {
        if (!(board.get_piece(Coordinate('f', y)).is_blank() && board.get_piece(Coordinate('g', y)).is_blank())) {
            return false;
        }
    }
    else {
        if (!(board.get_piece(Coordinate('b', y)).is_blank() && board.get_piece(Coordinate('c', y)).is_blank() && board.get_piece(Coordinate('d', y)).is_blank())) {
            return false;
        }
    }


    // Exit if moving out of check
    if (kingSide) {
        if (board.in_moves(Coordinate('e', y), opColor) || board.in_moves(Coordinate('f', y), opColor) || board.in_moves(Coordinate('g', y), opColor)) {
            return false;
        }
    }
    else {
        if (board.in_moves(Coordinate('e', y), opColor) || board.in_moves(Coordinate('d', y), opColor) || board.in_moves(Coordinate('c', y), opColor)) {
            return false;
        }
    }

    // Grab king and rook coords
    Coordinate kingDest;
    Coordinate rookDest;
    
    if (kingSide) {
        kingDest.copy_from(Coordinate('g', y));
        rookDest.copy_from(Coordinate('f', y));
    }
    else {
        kingDest.copy_from(Coordinate('c', y));
        rookDest.copy_from(Coordinate('d', y));

    }

    turns.emplace_back(board, king.get_location(), to);
    king.hasMoved = true;
    rook.hasMoved = true;

    Move::replace(board, king, board.get_piece(kingDest));
    Move::replace(board, rook, board.get_piece(rookDest));

    return true;



    
}

// Deals with en passant
// Checks if the moving piece is a pawn and if it moves two steps
bool Move::passant_vic(Board& board, Coordinate a, Coordinate b) {
    Piece& moving = board.get_piece(a);
    Piece& dest = board.get_piece(b);

    // Leave if it's not a pawn
    if (moving.get_type() != 1) {
        return false;
    }

    // Make sure it's moving forwards two places
    if (abs(b.get_y() - a.get_y()) != 2) {
        return false;
    }

    // Set needed vals
    enPassant = true;
    passantVic = &dest;
    passantVicLoc.copy_from(b);

    return true;
    
}
// Checks if the moving piece is trying to en passant capture
bool Move::passant_cap(Board& board, Coordinate a, Coordinate b) {
    if (!enPassant) {
        return false;
    }

    Piece& moving = board.get_piece(a);
    Piece& dest = board.get_piece(b);

    // Make sure colors are mismatched
    if (moving.get_color() == passantVic->get_color()) {
        return false;
    }

    // Leave if it's not a pawn
    if (moving.get_type() != 1) {
        return false;
    }

    // Make sure there's a value for passant_vic
    if (!passantVic) {
        return false;
    }

    // Assign Coords for passant location based on piece
    Coordinate passantA(passantVicLoc.get_y(), passantVicLoc.get_x() - 1);
    Coordinate passantB(passantVicLoc.get_y(), passantVicLoc.get_x() + 1);

    // Check if the moving is not in a good location
    bool allowed = false;
    if (Move::on_board(passantA)) {
        allowed = a.equals(passantA);
    }
    else if (Move::on_board(passantB)) {
        allowed = a.equals(passantB);
    }
    else {
        return false;
    }

    Move::refresh(board);
    // Make sure it's moving to a good location
    if (moving.get_color() == 'b') {
        if (!(b.equals(Coordinate(passantVicLoc.get_y() + 1, passantVicLoc.get_x())))) {
            return false;
        }
    }
    else if (moving.get_color() == 'w') {
        if (!(b.equals(Coordinate(passantVicLoc.get_y() - 1, passantVicLoc.get_x())))) {
            return false;
        }
    }
    else {
        return false;
    }
    
    // Exit if not allowed
    if (!allowed) {
        return false;
    }

    // Exit if the capturing is trying to capture two pieces
    if (!board.get_piece(b).is_blank()) {
        return false;
    }

    // Now move the pieces!!
    // Move the capturing
    Move::replace(board, a, b);

    // Drop the captured piece
    passantVic->make_blank();

    return true;


}

// Main Move function that will consider all needed methods
// Moves from a to b
// Returns int indicating overall game state
// invalid (against basic rules) = -2, invalid (moving to check) = -1,
// valid (nuetral) = 0, valid (putting enemy in check) = 1,
// valid (stalemate) = 2, valid (checkmate) = 3
// NEED SEPARTE CODE FOR EVERY OUTCOME
// MUST IMPLEMENT FUNCTIONALITY FOR CHECK WARNING ON THE ENEMY PLAYER
// WHERE THEY MUST MOVE THEMSELVES OUT OF CHECK IF POSSIBLE
// CURRENTLY THEY CAN BE IN CHECK THEN MOVE THEMSELVES TO CHECKMATE
// EVEN IF ALTERNATIVE SAFE MOVE IS POSSIBLE --> BREAKS RULES OF CHESS
// ALSO EN PASSANT


int Move::move(Board& board, Coordinate a, Coordinate b) {
    BTools::debug("int Move::move(Board& board, Coordinate a, Coordinate b)");

    // Piece blank; // Makes blank piece for future return needs
    bool capture = false; // True if the move is a capture
    bool canMove = false; // True if it can move there
    bool skip = false; // If theres another rule skipping checks

    if (!Move::on_board(a) || !Move::on_board(b)) {
        printf("INVALID: Location is off board\n"); // For Debug Purposes
        // Exits returning -2 indicating invalid (against basic rules)
        return -2;
    }
    // Exits if there's no piece to move
    if (!board.has_piece(a)) {
        printf("INVALID: Moving piece is blank\n"); // For Debug Purposes
        // Exits returning -2 indicating invalid (against basic rules)
        return -2;
    }

    // Grabs pieces at given locations
    Piece& moving = board.get_piece(a);
    Piece& cap = board.get_piece(b);
    
    // Updates the moving piece's moves
    Move::update_moves(board, moving);

    // Check for castling
    skip = Move::castle(board, moving, b);

    // Check for en passant capture
    skip = Move::passant_cap(board, a, b);

    // Checks if move is legal and within moveset
    if (!skip) {
        vector<Coordinate>& moves = moving.get_moves();
        for (int i = 0; i < moves.size(); i++) {
            // moves[i].print_pair();
            if (moves[i].equals(b)) {
                canMove = true;
                break;
            }
        }
    }

    // Check for en passant victim
    bool passantSet = Move::passant_vic(board, a, b);

    // Sets capture to true if piece cap is not blank
    if (!cap.is_blank()) {
        capture = true;
    }

    // Add to the moves vector
    if (!skip) {
        turns.emplace_back(board, a, b);
        moving.hasMoved = true;
    }

    // Exits if it cannot move
    if (!skip && !canMove) {
        printf("INVALID: Piece cannot move there\n"); // For Debug Purposes
        // Exits returning -2 indicating invalid (against basic rules)
        return -2;
    }
    
    if (capture) {
        // Clears moving array
        cap.get_moves().clear();
    }


    // Stores replicate of captured piece (cap) if undo is necessary
    Piece reverse;
    if (!skip) {
        reverse.copy_from(cap);
        reverse.set_location(cap.get_location());

    }

    // Actually moves the piece
    if (!skip) {
        Move::replace(board, moving, cap);
    }
    


    // board.print_board();


    // Check if needs promotion
    Move::promote_prompt(board, b);

    // Check if needs en passant reset
    if (!passantSet) {
        enPassant = false;
        passantVic = NULL;
     
    }


    passantSet = false;

    // Stores color and color names for future use
    char selfChar;
    char enemyChar;
    string selfName;
    string enemyName;
    if (cap.get_color() == 'w') {
        selfChar = 'w';
        enemyChar = 'b';
        selfName = "White";
        enemyName = "Black";
    } 
    else {
        selfChar = 'b';
        enemyChar = 'w';
        selfName = "Black";
        enemyName = "White";
    }
    //printf("selfChar: %c\nenemyChar: %c\nselfName: %s\nenemyName: %s\n", selfChar, enemyChar, selfName.c_str(), enemyName.c_str());

    // Refreshes whiteMoves and blackMoves + aliveWhite and aliveBlack + all moves for both players 
    Move::refresh(board);
    
    if (skip) {
        return 0;
    }
    // Holds game status in regards to king with self color 
    // neutral = -1, stalemate = 0, check = 1, checkmate = 2
    int statusSelf = Move::game_status(board, selfChar);

    //printf("Self Status: %d\n", statusSelf);

    // Evaluates game status in regards to self color
    switch (statusSelf) {
        // Self in Check
        case 1:
            // Reverses move
            Move::replace(board, cap, moving);
            board.get_piece(b.get_y(), b.get_x()).copy_from(reverse);
            board.get_piece(b.get_y(), b.get_x()).set_location(reverse.get_location());
            // Exits returning -1 indicating invalid (moving to check)
            return -1;
        // Stalemate
        case 0:
            printf("First Stale");
            board.staleMate();
            // Exits returning 2 indicating valid (stalemate)
            return 2;
        // Self in Checkmate
        case 2:
            board.checkMate(enemyChar);
            // Exits returning 3 indicating valid (checkmate)
            return 3;
        // Neutral State (-1)
        default:
            break;
    }
    
    // Holds game status in regards to king with enemy color 
    // neutral = -1, stalemate = 0, check = 1, checkmate = 2
    int statusEnemy = Move::game_status(board, enemyChar);

    //printf("Enemy Status: %d\n", statusEnemy);

    // Evaluates game status in regards to enemy color
    switch (statusEnemy) {
        // Enemy in Check (THIS ONE IS SPECIAL BC IT CAN IMPACT NEXT MOVE)
        case 1:
            // Exits returning 1 indicating valid (putting enemy in check)
            return 1;
        // Stalemate
        case 0:
            printf("Second Stale");
            board.staleMate();
            // Exits returning 2 indicating valid (stalemate)
            return 2;
        // Enemy in Checkmate
        case 2:
            board.checkMate(selfChar);
            // Exits returning 3 indicating valid (checkmate)
            return 3;
        // Neutral State (-1)
        default:
            break;
    }
    // Return Indicating Neutral Overall Game State
    return 0;
}