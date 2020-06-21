#ifndef MOVE_GUARD
#define MOVE_GUARD

#include <iostream>

#include "../resources/Constants.h"
#include "../objects/Coordinate.hpp"
#include "../objects/Piece.hpp"
#include "../objects/Board.hpp"

// Will represent vector from initial coord to final coord
class Move {
    public:
        // ============= Methods =============
        // pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
        // Piece specific updates 
        static void update_pawn(Board board, Piece piece);
        static void update_knight(Board board, Piece piece);
        static void update_bishop(Board board, Piece piece);
        static void update_rook(Board board, Piece piece);
        static void update_queen(Board board, Piece piece);
        static void update_king(Board board, Piece piece);
        // checks if one pos is btwn -1 and SIZE
        static bool on_board(int c);
        // checks if both pos are btwn -1 and SIZE
        static bool on_board(int x, int y);

        // Switch to decide which piece to operate on
        static void update_moves(Board b, Piece p);

        // Swaps two pieces
        // From piece references
        static void swap(Piece &a, Piece &b);
        // From coords
        static void swap(Board &board, Coordinate a, Coordinate b);



};

#endif