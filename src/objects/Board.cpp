#include "../../include/objects/Board.hpp"

using namespace std;

// ============= Constructors ==============
// if true create basic board : if false create blank board
Board::Board(bool basic) {
    if(DEBUG) {
        printf("Board::Board(bool)\n");
    }
    Board::build_board(basic);

}

// Create board with players
Board::Board(Player &w, Player &b) {
    if(DEBUG) {
        printf("Board::Board(Player, Player)\n");
    }

    white = &w;
    black = &b;

    Board::build_board(true);
}

// ============= Getters ==============
// Returns piece at location (i,j)
Piece *Board::get_piece(int i, int j) {
    return &board[i][j];
}
// From coord
Piece *Board::get_piece(Coordinate c) {
    return Board::get_piece(c.get_y(), c.get_x());
}


// ============= Setters ==============
// Sets a space to a piece
void Board::set_piece(Piece p, Coordinate c) {
    board[c.get_y()][c.get_x()].copy_from(p);
}

// ============= Methods ==============
void Board::build_board(bool basic) {
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
            board[SIZE - 2][i] = Pawn('w');
            board[SIZE - 2][i].set_location(Coordinate(SIZE - 2, i));
        }
        // white rooks
        board[SIZE - 1][0] = Rook('w');
        board[SIZE - 1][0].set_location(Coordinate(SIZE - 1, 0));
        board[SIZE - 1][SIZE - 1] = Rook('w');
        board[SIZE - 1][SIZE - 1].set_location(Coordinate(SIZE - 1, SIZE - 1));
        // white knights
        board[SIZE - 1][1] = Knight('w');
        board[SIZE - 1][1].set_location(Coordinate(SIZE - 1, 1));
        board[SIZE - 1][SIZE - 2] = Knight('w');
        board[SIZE - 1][SIZE - 2].set_location(Coordinate(SIZE - 1, SIZE - 2));
        // white bishops
        board[SIZE - 1][2] = Bishop('w');
        board[SIZE - 1][2].set_location(Coordinate(SIZE - 1, 2));
        board[SIZE - 1][SIZE - 3] = Bishop('w');
        board[SIZE - 1][SIZE - 3].set_location(Coordinate(SIZE - 1, SIZE - 3));
        // white king and queen
        board[SIZE - 1][3] = Queen('w'); // white queen
        board[SIZE - 1][3].set_location(Coordinate(SIZE - 1, 3));
        board[SIZE - 1][SIZE - 4] = King('w'); // white king
        board[SIZE - 1][SIZE - 4].set_location(Coordinate(SIZE - 1, SIZE - 4));

        // Adds all black pieces after
        // line of black pawns
        for (int i = 0; i < SIZE; i++) {
            board[1][i] = Pawn('b');
            board[1][i].set_location(Coordinate(1, i));
        }
        // black rooks
        board[0][0] = Rook('b');
        board[0][0].set_location(Coordinate(0, 0));
        board[0][SIZE - 1] = Rook('b');
        board[0][SIZE - 1].set_location(Coordinate(0, SIZE - 1));
        // black knights
        board[0][1] = Knight('b');
        board[0][1].set_location(Coordinate(0, 1));
        board[0][SIZE - 2] = Knight('b');
        board[0][SIZE - 2].set_location(Coordinate(0, SIZE - 2));
        // black bishops
        board[0][2] = Bishop('b');
        board[0][2].set_location(Coordinate(0, 2));
        board[0][SIZE - 3] = Bishop('b');
        board[0][SIZE - 3].set_location(Coordinate(0, SIZE - 3));
        // black king and queen
        board[0][3] = Queen('b'); // black queen
        board[0][3].set_location(Coordinate(0, 3));
        board[0][SIZE - 4] = King('b'); // black king
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

Piece Board::refresh(Piece moving, Coordinate n){
    // stores piece at n into temp
    Piece temp;
    temp.copy_from(board[n.get_y()][n.get_x()]);
    // makes location of temp (-1, -1) indicating offBoard
    temp.set_location(Coordinate(-1, -1));
    // sets old location of moving piece to blank
    board[moving.get_location().get_y()][moving.get_location().get_x()].make_blank();
    // sets coordinate n to moving Piece
    board[n.get_y()][n.get_x()].copy_from(moving);
    // updates location of moving Piece
    board[n.get_y()][n.get_x()].set_location(Coordinate(n.get_y(), n.get_x()));
    // Returns temp -> (Piece captured and blank Piece if none)
    return temp;
}

// Returns true or false if there is a piece there
bool Board::has_piece(int i, int j) {
    return !board[i][j].is_blank();
}
bool Board::has_piece(Coordinate c) {
    return Board::has_piece(c.get_y(), c.get_x());
}

// ============= Debug ==============
// This will print the board
void Board::print_board() {
    if(DEBUG) {
        printf("Board::print_board()\n");
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if it's blank and print a space
            if (board[i][j].is_blank()) {
                printf("- ");
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
                printf("%c ", BTools::to_upper(c));
            }
            else {
                printf("%c ", BTools::to_lower(c));
            }
        }
        // Make new line
        printf("\n");
    }
}
