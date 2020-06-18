#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include <vector>

#include "../resources/Tools.hpp"
#include "Piece.hpp"

using namespace std;

class Player {
    private:
        char color;

        int points;      

    public:
        // Can Be Accessed by Other Classes
        vector<Piece> captured; // Pieces they have captured
        vector<Piece> onBoard; // Pieces they have on board
        vector<Piece> lost; // Pieces they have lost

        // contains ids
        vector<int> icaptured;
        vector<int> ionBoard;
        vector<int> ilost;

        // ================ Constructors ================
        // Sets given color: b or w
        Player(char c);

        // ================ Methods ================
        // Removes piece from onBoard and puts it in taken. Returns if successful
        bool lose(Piece a);

};

#endif