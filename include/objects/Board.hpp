#ifndef BOARD_GUARD
#define BOARD_GUARD

#include <vector>

#include "../resources/Constants.h"
#include "../resources/Tools.hpp"
#include "../resources/BlandTools.hpp"
#include "Piece.hpp"
#include "pieces/Pawn.hpp"
#include "pieces/Knight.hpp"
#include "pieces/Bishop.hpp"
#include "pieces/Rook.hpp"
#include "pieces/Queen.hpp"
#include "pieces/King.hpp"
#include "Player.hpp"



// Declares unchangeable size
// #define SIZE 8

using namespace std;

// NOTE: White on Bottom of Board (Starting y = 6,7) / Black on Top (Starting y = 0,1)
class Board {
    private:
        Player white;
        Player black;

        vector<Coordinate>* blackMoves[16];
        vector<Coordinate>* whiteMoves[16];

    public:
        // Creates a 2d array to represent a board
        // blank piece means no piece there
        Piece board[SIZE][SIZE];

        // ============= Constructors ==============
        // if true create basic board : if false create blank board
        // Players constructed automatically
        Board(bool basic);

        // ============= Getters ==============
        // Returns piece at location (i,j)
        Piece& get_piece(int i, int j);
        // From coord
        Piece& get_piece(Coordinate c);

        // Returns reference to Player
        Player& get_player(char c);

        // Returns reference to whiteMoves
        vector<Coordinate>* get_whiteMoves();
        // Returns reference to blackMoves
        vector<Coordinate>* get_blackMoves();
        // Returns reference to whiteMoves or blackMoves depending on Piece given
        vector<Coordinate>* get_moves(Piece &a);

        // ============= Setters ==============
        // Sets a space to a piece
        void set_piece(Piece p, Coordinate c);

        // ============= Methods ==============
        // Builds starting board
        void build_board(bool basic);

        // sets up Players vectors: captured, onBoard, lost
        void set_Players();

        // Returns true or false if there is a piece there
        bool has_piece(int i, int j);
        bool has_piece(Coordinate c);

        // ============= Debug ==============
        // This will print board piece ids
        void print_id();

        // This will print the board
        void print_board();



};

#endif