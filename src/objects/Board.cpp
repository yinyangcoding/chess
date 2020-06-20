#include "../../include/objects/Board.hpp"

using namespace std;

// ============= Constructors ==============
// if true create basic board : if false create blank board
Board::Board(bool basic) {
    // if not a basic Board (Blank Board) fill board with blank pieces
    if (!basic) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j].make_blank();
            }
        }
    } else { // if it is a basic Board make board a basic board
        // Adds all white pieces first
        // line of white pawns
        for (int i = 0; i < SIZE; i++) {
            board[SIZE - 2][i] = Pawn('w');
        }
        // white rooks
        board[SIZE - 1][0] = Rook('w');
        board[SIZE - 1][SIZE - 1] = Rook('w');
        // white knights
        board[SIZE - 1][1] = Knight('w');
        board[SIZE - 1][SIZE - 2] = Knight('w');
        // white bishops
        board[SIZE - 1][2] = Bishop('w');
        board[SIZE - 1][SIZE - 3] = Bishop('w');
        // white king and queen
        board[SIZE - 1][3] = Queen('w'); // white queen
        board[SIZE - 1][SIZE - 4] = King('w'); // white king

        // Adds all black pieces after
        // line of black pawns
        for (int i = 0; i < SIZE; i++) {
            board[1][i] = Pawn('b');
        }
        // black rooks
        board[0][0] = Rook('b');
        board[0][SIZE - 1] = Rook('b');
        // black knights
        board[0][1] = Knight('b');
        board[0][SIZE - 2] = Knight('b');
        // black bishops
        board[0][2] = Bishop('b');
        board[0][SIZE - 3] = Bishop('b');
        // black king and queen
        board[0][3] = Queen('b'); // black queen
        board[0][SIZE - 4] = King('b'); // black king

        // makes all the remaining space blank pieces
        for (int i = 2; i < (SIZE - 2); i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j].make_blank();
            }
        }
    }
}

// ============= Methods ==============
// Moves Piece a to new Coordinate n on Board
// Returns the Piece captured if No Piece then blank
// --> Return should be used to update Player vectors: captured, onBoard, lost
// WILL BE USED AFTER EVERY MOVE
Piece Board::refresh(Piece moving, Coordinate n){
    // temp set to the value of the Piece at the new Coordinate and NULL if no piece there
    Piece temp;
    
    // WHY DOES THIS NOT WORK
    if (!board[n.get_x()][n.get_y()].is_blank()) {
        temp.copy_from(board[n.get_x()][n.get_y()]);
        // makes location (-1, -1) indicating offBoard
        temp.set_location(Coordinate(-1, -1));
    }

    // old location of the moving Piece is set to blank
    board[moving.get_location().get_x()][moving.get_location().get_y()].make_blank();
    // new Coordinate is set to the moving Piece
    board[n.get_x()][n.get_y()].copy_from(moving);
    // updates location of moving Piece
    board[n.get_x()][n.get_y()].set_location(Coordinate(n.get_x(), n.get_y()));
    // Returns Piece Captured and blank if none
    return temp;
}

// Sets a space to a piece
void Board::set_piece(Piece p, Coordinate c) {
    board[c.get_x()][c.get_y()].copy_from(p);
}


// ============= Debug ==============
// This will print the board
void Board::print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if it's blank and print a space
            if (board[i][j].is_blank()) {
                printf("-");
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
                printf("%c", Tools::to_upper(c));
            }
            else {
                printf("%c", Tools::to_lower(c));
            }
        }
        // Make new line
        printf("\n");
    }
}
