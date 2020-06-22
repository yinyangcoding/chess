#include <iostream>

#include "../include/resources/Constants.h"
#include "../include/objects/Coordinate.hpp"
#include "../include/objects/Piece.hpp"
#include "../include/objects/pieces/King.hpp"
#include "../include/objects/pieces/Queen.hpp"
#include "../include/objects/pieces/Bishop.hpp"
#include "../include/objects/pieces/Knight.hpp"
#include "../include/objects/pieces/Rook.hpp"
#include "../include/objects/pieces/Pawn.hpp"
#include "../include/resources/Tools.hpp"
#include "../include/objects/Board.hpp"
#include "../include/objects/Player.hpp"
#include "../include/resources/Move.hpp"

using namespace std;

int main() {
	Board b(true);
	b.print_board();

	Move::swap(b, Coordinate('a', 7), Coordinate('a', 5));
	Move::swap(b, Coordinate('b', 2), Coordinate('b', 4));

	Move::replace(b, Coordinate('b', 4), Coordinate('a', 5));

	

	b.print_board();
	

	return 0;
}
