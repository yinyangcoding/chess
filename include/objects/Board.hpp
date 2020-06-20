#ifndef BOARD_GUARD
#define BOARD_GUARD

#include <vector>

#include "../resources/Constants.h"
#include "../resources/Tools.hpp"
#include "Piece.hpp"

// Declares unchangeable size
// #define SIZE 8

using namespace std;

// NOTE: White on Bottom of Board (Starting y = 6,7) / Black on Top (Starting y = 0,1)
class Board {
    public:
        // Creates a 2d array to represent a board
        // NULL means no piece there
        // Does this initialize all players to NULL???
        Piece board[SIZE][SIZE];

        // ============= Constructors ==============
        // if true create basic board : if false create blank board
        Board(bool basic);

        // ============= Methods ==============
        // Moves Piece a to new Coordinate n on Board
        // Returns the Piece Captured if No Piece then Null
        // --> Return is useful for updating Player vectors: captured, onBoard, lost
        // WILL BE USED AFTER EVERY MOVE
        Piece refresh(Piece a, Coordinate n);
        
        // Sets a space to a piece
        void set_piece(Piece p, Coordinate c);


        // ============= Debug ==============
        // This will print the board
        void print_board();



};

#endif