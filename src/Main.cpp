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
#include "../include/objects/Move.hpp"

using namespace std;

int main() {
	Board b(true);
	b.print_board();

	return 0;
}
