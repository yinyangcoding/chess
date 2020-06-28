#include <iostream>

#include "../include/resources/Constants.h"
#include "../include/objects/Coordinate.hpp"
#include "../include/objects/Piece.hpp"
#include "../include/resources/Tools.hpp"
#include "../include/objects/Board.hpp"
#include "../include/objects/Player.hpp"
#include "../include/resources/Move.hpp"

using namespace std;

int main() {
	Board b(true);

	for (int i = 0; i < 500000; i++) {
		Move::move(b, Coordinate('b', 1), Coordinate('c', 3));
		Move::move(b, Coordinate('c', 3), Coordinate('b', 1));
	}



	return 0;
}
