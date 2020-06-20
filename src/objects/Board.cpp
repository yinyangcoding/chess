#include "../../include/objects/Board.hpp"

using namespace std;

// ============= Constructors ==============
// Defines Empty New Board
Board::Board() {
    // Fill board with blank pieces
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            Piece blank;
            board[i][j] = blank;
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
                printf(" ");
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
