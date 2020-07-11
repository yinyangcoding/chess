#include <iostream>
#include <string>
#include <ctype.h>

#include "../include/resources/Constants.h"
#include "../include/objects/Coordinate.hpp"
#include "../include/objects/Piece.hpp"
#include "../include/resources/Tools.hpp"
#include "../include/resources/BlandTools.hpp"
#include "../include/objects/Board.hpp"
#include "../include/objects/Player.hpp"
#include "../include/resources/Move.hpp"


using namespace std;

int main() {
	Board b(true);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((i == 1 && j == 1) || (i == 6 && j == 0)) {
				continue;
			}
			b.board[i][j].make_blank();
		}
	}
	Move::move(b, Coordinate('a', 2), Coordinate('a', 4));
	Move::move(b, Coordinate('a', 4), Coordinate('a', 5));

	Move::move(b, Coordinate('b', 7), Coordinate('b', 5));

	b.print_board();

	Move::move(b, Coordinate('a', 5), Coordinate('b', 6));

	b.print_board();

	return 0;
}