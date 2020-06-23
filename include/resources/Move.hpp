#ifndef MOVE_GUARD
#define MOVE_GUARD

#include <iostream>
#include <vector>

#include "Constants.h"
#include "BlandTools.hpp"
#include "../objects/Coordinate.hpp"
#include "../objects/Piece.hpp"
#include "../objects/Board.hpp"

// Will represent vector from initial coord to final coord
class Move {
    public:
        // ============= Methods =============
        // pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
        // Player specific update
        static void update_player(Board& board, char color);

        // Switch to decide which piece to operate on
        static void update_moves(Board& b, Piece& p);

        // Piece specific updates 
        static void update_pawn(Board& board, Piece& piece);
        static void update_knight(Board& board, Piece& piece);
        static void update_bishop(Board& board, Piece& piece);
        static void update_rook(Board& board, Piece& piece);
        static void update_queen(Board& board, Piece& piece);
        static void update_king(Board& board, Piece& piece);

        // checks if one pos is btwn -1 and SIZE
        static bool on_board(int c);
        // checks if both pos are btwn -1 and SIZE
        static bool on_board(int y, int x);

        
        // Swaps two pieces
        // From piece references
        static void swap(Piece& a, Piece& b);
        // From coords
        static void swap(Board& board, Coordinate a, Coordinate b);

        // checks if king is in check, checkmate, or stalemate
        // none = -1, stalemate = 0, check = 1, checkmate = 2
        static int check_position(Board& board, Coordinate king);
        // returns true if in check
        static bool in_check(Board& board, Coordinate king);
        // return true if Coordinates surrounding king are all in check
        static bool surrounding_check(Board& board, Coordinate king);

        // A captures B
        // From piece references
        static void replace(Piece& a, Piece& b);
        // From coords
        static void replace(Board& board, Coordinate a, Coordinate b);

        // Main Move function that will consider all needed methods
        // Returns a piece if captured. Returns blank if not
        static Piece move(Board& board, Coordinate a, Coordinate b);


};

#endif