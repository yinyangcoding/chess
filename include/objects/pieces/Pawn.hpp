#ifndef PAWN_GUARD
#define PAWN_GUARD

#include "../../resources/BlandTools.hpp"
#include "../Piece.hpp"
#include "../Board.hpp"

// REMINDER: Need method to turn pawn to another Piece when reached end of Board but keep same ID
class Pawn : public Piece {
	public:
		Pawn(char c);

		// ============== Methods ================
		void update();
};

#endif