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

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0 && j == 7) {
				continue;
			}
			if (i == 0 && j == 4) {
				continue;
			}
			b.get_piece(i, j).make_blank();
		}
	}

	b.print_board();

	Move::move(b, Coordinate('e', 8), Coordinate('g', 8));

	b.print_board();

	return 0;
}