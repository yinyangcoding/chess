#ifndef PAWN_GUARD
#define PAWN_GUARD

#include "../Piece.hpp"
#include "../Board.hpp"

// REMINDER: Need method to turn pawn to another Piece when reached end of Board but keep same ID
class Pawn : public Piece {
	private: 
		// indicates if first move was done
		bool first;
	Pawn(char c);
	void update();
};

#endif