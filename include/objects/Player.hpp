#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include <vector>

#include "../resources/Tools.hpp"
#include "Piece.hpp"

using namespace std;

class Player {
    private:
        char color;
        // Should use a point calculator at the end instead (running point total is unnecessary)
        int points;      

    public:
        // Can Be Accessed by Other Classes
        // Copies Needed Here Rather Than Addresses for Speed
        vector<Piece> captured; // Pieces they have captured
        vector<Piece> onBoard; // Pieces they have on board
        vector<Piece> lost; // Pieces they have lost

        // ================ Constructors ================
        // Sets given color: b or w
        Player(char c);

        // ============== Getters ================
        // Returns color
        char get_color() const;

        // Returns points
        int get_points() const;

        // Returns captured vector
        vector<Piece>& get_captured();

        // Returns onBoard vector
        vector<Piece>& get_onBoard();

        // Returns lost vector
        vector<Piece>& get_lost();

        // ============== Setters ================
        // Sets color
        void set_color(char c);

        // Sets points
        void set_points(int p);

        // ================ Methods ================
        // Removes piece from onBoard and puts it in taken. Returns if successful
        bool lose(Piece& a);
};

#endif