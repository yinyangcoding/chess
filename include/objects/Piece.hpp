#ifndef PIECE_GUARD
#define PIECE_GUARD

#include <string>
#include <vector>

#include "Coordinate.hpp"
#include "../resources/BlandTools.hpp"

// This cannot take board, because Piece must be defined before board
// #include "Board.hpp"

using namespace std;

// Parent class of each piece
class Piece {
	private:
        static int idCountW; // Increments id for white
        static int idCountB; // Decrements id for black
        int id; // Unique id for each piece
        int point; // point value
        int type; // pawn: 1, knight: 2, bishop: 3, Rook: 4, Queen: 5, King: 6
        char color; // 'w' for white 'b' for black
        vector<Coordinate> moves; // Contains possible moves
        Coordinate location; // Contains current location

    public:
        bool hasMoved; // true if it's moved, false otherwise
        // ============= Constructors ==============
        // Creates piece with given type
        Piece(int t);

        // Creates piece with given type and given color
        Piece(int t, char c);

        // Creates blank piece
        Piece();

        // ============== Getters ================
        // Returns id
        int get_id() const;

        // Returns point val
        int get_point() const;

        // Returns type num
        int get_type() const;

        // Returns color char
        char get_color() const;

        // Returns location Coordinate
        Coordinate get_location() const;

        // Returns possible moves
        vector<Coordinate>& get_moves();

        // ============= Setters ==============
        void set_location(Coordinate a);
        void set_id(int i);
        void set_point(int i);
        void set_type(int i);
        void set_color(char c);

        // ============= Methods ==============
        // Returns if a equals this by id
        bool equals(Piece a);

        // Sets point val with switch from type
        void assign_point();

        // Copies a traits to this
        void copy_from(Piece a);

        // Updates possible moves vector specific to each piece
        void update();

        // Returns if the piece is a blank placeholder
        bool is_blank();

        // Makes the piece a blank placeholder
        void make_blank();

        // swaps pieces NOT PREFERED USE
        void swap(Piece &a);
};

#endif