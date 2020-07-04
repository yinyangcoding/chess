#ifndef MOVE_GUARD
#define MOVE_GUARD

#include <iostream>
#include <vector>
#include <string>

#include "Constants.h"
#include "BlandTools.hpp"
#include "../objects/Coordinate.hpp"
#include "../objects/Piece.hpp"
#include "../objects/Board.hpp"
#include "../objects/Player.hpp"

// Build a struct that contains a translation
struct Displace {
    Coordinate from; // Contains where it moved from
    Coordinate to; // Contains where it moved to

    int id; // ID of the piece that moved

    // Basic constructor
    Displace(Board& b, Coordinate f, Coordinate t) {
        from.copy_from(f);
        to.copy_from(t);
        id = b.get_piece(from).get_id();
    }

};

// Will represent vector from initial coord to final coord
namespace Move {

    // ============= Methods =============
    // pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
    // Player specific update
    void update_player(Board& board, char color);

    // Switch to decide which piece to operate on
    void update_moves(Board& b, Piece& p);

    // Piece specific updates 
    void update_pawn(Board& board, Piece& piece);
    void update_knight(Board& board, Piece& piece);
    void update_bishop(Board& board, Piece& piece);
    void update_rook(Board& board, Piece& piece);
    void update_queen(Board& board, Piece& piece);
    void update_king(Board& board, Piece& piece);

    // Checks if one pos is btwn -1 and SIZE
    bool on_board(int c);
    // Checks if both pos are btwn -1 and SIZE
    bool on_board(int y, int x);
    // Checks if both pos are btwn -1 and SIZE from Coordinate
    bool on_board(Coordinate loc);

    // checks if king of color c is in check, checkmate, or stalemate
    // neutral = -1, stalemate = 0, check = 1, checkmate = 2
    static int game_status(Board& board, char c);
    // returns true if in check
    bool in_check(Board& board, char color, Coordinate king);
    // return true if Coordinates surrounding king are all in check
    bool surrounding_check(Board& board, char color, Coordinate king, bool centerCheck);

    // A captures B
    // From piece references
    void replace(Board& board, Piece& a, Piece& b);
    // From coords
    void replace(Board& board, Coordinate a, Coordinate b);

    // Refreshes whiteMoves and blackMoves + aliveWhite and aliveBlack + all moves for indicated player
    void refresh(Board& board);

    // Promotes a pawn
    void promote(Board& board, Coordinate c, int n);
    // Promotes a pawn from char
    void promote(Board& board, Coordinate c, char n);
    // Takes user input
    void promote_prompt(Board& board, Coordinate c);

    // Main Move function that will consider all needed methods
    // Moves from a to b
    // Returns int indicating result of the move
    // invalid (against basic rules) = -2, invalid (moving to check) = -1,
    // valid (nuetral) = 0, valid (stalemate) = 1, valid (checkmate) = 2
    int move(Board& board, Coordinate a, Coordinate b);
}

#endif