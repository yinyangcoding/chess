#ifndef BOARD_GUARD
#define BOARD_GUARD

#include <vector>

#include "../resources/Constants.h"
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
        // New layout board
        Board();
        // New empty board
        Board(bool);

        // ============= Methods ==============
        // Moves Piece a to new Coordinate n on Board
        // Returns the Piece Captured if No Piece then Null
        // --> Return is useful for updating Player vectors: captured, onBoard, lost
        // WILL BE USED AFTER EVERY MOVE
        Piece refresh(Piece a, Coordinate n);


};

#endif