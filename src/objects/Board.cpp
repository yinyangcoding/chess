#include "../../include/objects/Board.hpp"

using namespace std;

// ============= Constructors ==============
// if true create basic board : if false create blank board
// Players constructed automatically
Board::Board(bool basic) {
    BTools::debug("Board::Board(bool)");
    white = Player('w');
    black = Player('b');
    Board::build_board(basic);
    white.set_king(Board::get_piece(Coordinate('e', 1)));
    black.set_king(Board::get_piece(Coordinate('e', 8)));

}

// ============= Getters ==============
// Returns piece at location (i,j)
Piece& Board::get_piece(int i, int j) {
    return board[i][j];
}
// From coord
Piece& Board::get_piece(Coordinate c) {
    return Board::get_piece(c.get_y(), c.get_x());
}

// Returns reference to Player
Player& Board::get_player(char c) {
    if (c == 'w') {
        return white;
    }
    else if (c == 'b') {
        return black;
    }
    else {
        static Player blank;
        return blank;
    }
}

// Returns reference to whiteMoves
vector<Coordinate>** Board::get_whiteMoves() {
    return whiteMoves;
}
// Returns reference to blackMoves
vector<Coordinate>** Board::get_blackMoves() {
    return blackMoves;
}
// Returns reference to whiteMoves or blackMoves depending on color indicated
vector<Coordinate>** Board::get_moves(char c) {
    if (c == 'w') {
        return whiteMoves;
    }
    else if (c == 'b') {
        return blackMoves;
    }
    static vector<Coordinate>** blank;
    return blank;
}
// Returns reference to whiteMoves or blackMoves depending on Piece given
vector<Coordinate>** Board::get_moves(Piece &a) {
    // Switches color to reflect realistic use of this method
    char c = a.get_color();
    if (c == 'w') {
        c = 'b';
    } else if (c == 'b') {
        c = 'w';
    }
    return get_moves(c);
}


// Returns aliveWhite
Coordinate* Board::get_aliveWhite() {
    return aliveWhite;
}
// Returns aliveBlack
Coordinate* Board::get_aliveBlack() {
    return aliveBlack;
}
// Returns aliveWhite or aliveBlack depending on color indicated
Coordinate* Board::get_alive(char c) {
    if (c == 'w') {
        return aliveWhite;
    }
    else if (c == 'b') {
        return aliveBlack;
    }
    static Coordinate blank;
    return &blank;
}
// Returns aliveWhite or aliveBlack depending on Piece given
Coordinate* Board::get_alive(Piece& a) {
    return get_alive(a.get_color());
}


// Returns a reference to king by color provided
Piece* Board::get_king(char c) {
    Piece blank;
    if (c == 'w') {
        return white.get_king();
    }
    else if (c == 'b') {
        return black.get_king();
    }
    else {
        return nullptr;
    }
    
}


// ============= Setters ==============
// Sets a space to a piece
void Board::set_piece(Piece p, Coordinate c) {
    board[c.get_y()][c.get_x()].copy_from(p);
}
    

// ============= Methods ==============
void Board::build_board(bool basic) {
    BTools::debug("void Board::build_board(bool)");
    // if not a basic Board (Blank Board) fill board with blank pieces
    if (!basic) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j].make_blank();
            }
        }
    }
    else { 
        // if it is a basic Board make board a basic board
        // Adds all white pieces first
        // line of white pawns
        for (int i = 0; i < SIZE; i++) {
            board[SIZE - 2][i] = Piece(1, 'w');
            board[SIZE - 2][i].set_location(Coordinate(SIZE - 2, i));
        }
        // pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
        // white rooks
        board[SIZE - 1][0] = Piece(4, 'w');
        board[SIZE - 1][0].set_location(Coordinate(SIZE - 1, 0));
        board[SIZE - 1][SIZE - 1] = Piece(4, 'w');
        board[SIZE - 1][SIZE - 1].set_location(Coordinate(SIZE - 1, SIZE - 1));
        // white knights
        board[SIZE - 1][1] = Piece(2, 'w');
        board[SIZE - 1][1].set_location(Coordinate(SIZE - 1, 1));
        board[SIZE - 1][SIZE - 2] = Piece(2, 'w');
        board[SIZE - 1][SIZE - 2].set_location(Coordinate(SIZE - 1, SIZE - 2));
        // white bishops
        board[SIZE - 1][2] = Piece(3, 'w');
        board[SIZE - 1][2].set_location(Coordinate(SIZE - 1, 2));
        board[SIZE - 1][SIZE - 3] = Piece(3, 'w');
        board[SIZE - 1][SIZE - 3].set_location(Coordinate(SIZE - 1, SIZE - 3));
        // white king and queen
        board[SIZE - 1][3] = Piece(5, 'w');; // white queen
        board[SIZE - 1][3].set_location(Coordinate(SIZE - 1, 3));
        board[SIZE - 1][SIZE - 4] = Piece(6, 'w');; // white king
        board[SIZE - 1][SIZE - 4].set_location(Coordinate(SIZE - 1, SIZE - 4));

        // Adds all black pieces after
        // line of black pawns
        for (int i = 0; i < SIZE; i++) {
            board[1][i] = Piece(1, 'b');
            board[1][i].set_location(Coordinate(1, i));
        }
        // black rooks
        board[0][0] = Piece(4, 'b');
        board[0][0].set_location(Coordinate(0, 0));
        board[0][SIZE - 1] = Piece(4, 'b');
        board[0][SIZE - 1].set_location(Coordinate(0, SIZE - 1));
        // black knights
        board[0][1] = Piece(2, 'b');
        board[0][1].set_location(Coordinate(0, 1));
        board[0][SIZE - 2] = Piece(2, 'b');
        board[0][SIZE - 2].set_location(Coordinate(0, SIZE - 2));
        // black bishops
        board[0][2] = Piece(3, 'b');
        board[0][2].set_location(Coordinate(0, 2));
        board[0][SIZE - 3] = Piece(3, 'b');
        board[0][SIZE - 3].set_location(Coordinate(0, SIZE - 3));
        // black king and queen
        board[0][3] = Piece(5, 'b');; // black queen
        board[0][3].set_location(Coordinate(0, 3));
        board[0][SIZE - 4] = Piece(6, 'b');; // black king
        board[0][SIZE - 4].set_location(Coordinate(0, SIZE - 4));

        // makes all the remaining space blank pieces
        for (int i = 2; i < (SIZE - 2); i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j].make_blank();
                board[i][j].set_location(Coordinate(i, j));
            }
        }
    }
}


// Returns true or false if there is a piece there
bool Board::has_piece(int i, int j) {
    return !board[i][j].is_blank();
}
bool Board::has_piece(Coordinate c) {
    return Board::has_piece(c.get_y(), c.get_x());
}


// Runs through board refreshing whiteMoves and blackMoves + aliveWhite and aliveBlack
void Board::refresh_moves() {
    BTools::debug("void Board::refresh_moves()");
    // Clears aliveWhite and aliveBlack
    //for (int i = 0; i < 16; i++) {
    //    aliveWhite[i] = Coordinate(-1, -1);
    //    aliveBlack[i] = Coordinate(-1, -1);
    //}
    // Runs through board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Checks if a piece is blank
            if (!get_piece(i, j).is_blank()) {
                // Stores id if piece is not blank
                int id = get_piece(i, j).get_id();
                // Sets king variables for both players
                if (get_piece(i, j).get_type() == 6) {
                    if (get_piece(i, j).get_color() == 'w'){
                        get_player('w').set_king(get_piece(i, j));
                    }
                    else {
                        get_player('b').set_king(get_piece(i, j));
                    }
                }
                // Treats piece as a white piece if id > 0
                if (id > 0) {
                    // Sets appropriate element of whiteMoves to address of moves vector of that piece
                    whiteMoves[id - 1] = &get_piece(i, j).get_moves();
                    // Sets appropriate element of aliveWhite to location of that piece
                    aliveWhite[id - 1] = get_piece(i, j).get_location();
                    //printf("WHITE: %d\t", id);
                    //get_piece(i, j).get_location().print_pair();
                }
                 // Treats piece as a black piece if id < 0
                else {
                    // Sets appropriate element of blackMoves to address of moves vector of that piece
                    blackMoves[(id * -1) - 1] = &get_piece(i, j).get_moves();
                    // Sets appropriate element of aliveBlack to location of that piece
                    aliveBlack[(id * -1) - 1] = get_piece(i, j).get_location();
                    //printf("BLACK: %d\t", id);
                    //get_piece(i, j).get_location().print_pair();
                }
            }
        }
    }
    /*printf("ALIVEWHITE:\n");
    for (int i = 0; i < 16; i++) {
        aliveWhite[i].print_pair();
    }
    printf("ALIVEBLACK:\n");
    for (int i = 0; i < 16; i++) {
        aliveBlack[i].print_pair();
    }
    */
}


// End Game Methods
void Board::staleMate() {
    printf("Game Over: Stalemate\n");
}
void Board::checkMate(char c) {
    // Many variables for advance future use
    char winnerChar;
    char loserChar;
    std::string winnerName;
    std::string loserName;
    if (c == 'w') {
        winnerChar = 'w';
        loserChar = 'b';
        winnerName = "White";
        loserName = "Black";
    } 
    else {
        winnerChar = 'b';
        loserChar = 'w';
        winnerName = "Black";
        loserName = "White";
    }
    printf("Game Over: Checkmate\n");
    printf("%s Wins!\n", winnerName.c_str());
}


// ============= Debug ==============
// This will print board piece ids
void Board::print_id() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            std::printf("%d ", board[i][j].get_id());
        }
        std::printf("\n");
    }
}

// This will print the board
void Board::print_board() {
    BTools::debug("void Board::print_board()");

    std::printf("\n    A B C D E F G H\n  +-----------------+\n");

    for (int i = 0; i < SIZE; i++) {
        std::printf("%d | ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            // Check if it's blank and print a space
            if (board[i][j].is_blank()) {
                std::printf("- ");
                continue;
            }

            // Processes pieces char
            // starting letter, cap for black, n for knight
            Piece ij;
            ij.copy_from(board[i][j]);

            bool cap;
            if (ij.get_color() == 'w') {
                cap = false;
            }
            else if (ij.get_color() == 'b'){
                cap = true;
            }
            
            // Find out what piece it is
            char c;
            switch (ij.get_type()) {
                case 1:
                    c = 'p';
                    break;
                case 2:
                    c = 'n';
                    break;
                case 3:
                    c = 'b';
                    break;
                case 4:
                    c = 'r';
                    break;
                case 5:
                    c = 'q';
                    break;
                case 6:
                    c = 'k';
                    break;
                default:
                    break;
            }
            
            // Print out depending on cap
            if(cap) {
                std::printf("%c ", BTools::to_upper(c));
            }
            else {
                std::printf("%c ", BTools::to_lower(c));
            }
        }
        std::printf("| %d", SIZE - i);
        // Make new line
        std::printf("\n");
    }

    std::printf("  +-----------------+\n    A B C D E F G H\n");

}