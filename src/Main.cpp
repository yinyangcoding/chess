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

	// Move::swap(b.board[6][3], b.board[4][3]);
	// Move::swap(b.board[1][0], b.board[3][0]);

	Move::swap(b, Coordinate('a', 7), Coordinate('a', 5));
	printf("====================\n");
	Coordinate('g', 1).print_pair();
	Coordinate('f', 3).print_pair();
	printf("====================\n");
	Move::swap(b, Coordinate('g', 1), Coordinate('f', 3));

	

	b.print_board();
	

	return 0;
}
