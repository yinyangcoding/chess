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

	// Stores Player Input
	std::string input;
	int fromI, toI;
	char fromC, toC;

	// Implements Turn Functionality
	char turnPlayer;
	std::string playerName;
	std::string enemyName;
	int turnNumber = 1;

	// Indicates Game State
	int state = 0;

	// Displays Board
	b.print_board();

	// Runs Until Game State Indicates End Game (2 = StaleMate / 3 = CheckMate)
	while (state != 2 && state != 3) {
		// Sets Turn & Player Name Determined By Turn Number
		if (turnNumber % 2 == 1) {
			turnPlayer = 'w';
			playerName = "WHITE";
			enemyName = "BLACK";
		}
		else {
			turnPlayer = 'b';
			playerName = "BLACK";
			enemyName = "WHITE";
		}


		// Prompts Player for Input
		printf("TURN %d (%s):\n", turnNumber, playerName.c_str());
		getline(cin, input);
		input = BTools::trim(input);

		if ((input.size() != 5) || 
		(!isalpha(input.at(0)) || !isdigit(input.at(1)) || input.at(2) != ' ' || !isalpha(input.at(3)) || !isdigit(input.at(4)))) {
			BTools::debug("NOT VALID INPUT --> CONTINUE");
			// Displays Board
			b.print_board();
			// Instructs Player To Go Again
			printf("Invalid Input. Go Again (STILL %s)\n", playerName.c_str());
			continue;
		}


		fromC = input.at(0);
		fromI = input.at(1) - '0';
		toC = input.at(3);
		toI = input.at(4) - '0';
		BTools::debug("OUTPUT RECIEVED");
		//printf("\n%c%d\n%c%d\n", fromC, fromI, toC, toI);

		//Move::update_moves(b, b.get_piece(Coordinate(fromC, fromI)));
		//auto movesTest = b.get_piece(Coordinate(fromC, fromI)).get_moves();
		//for (int i = 0; i < movesTest.size(); i++) {
		//	movesTest[i].print_pair();
		//}
		// BTools::debug(string("'S TURN").insert(0, 1, toupper(turnPlayer)));

	
		// Regresses To Beginning Of Loop If Input Does Not Match The Correct Player
		//printf("\n\n\n%c\n", b.get_piece(Coordinate(fromC, fromI)).get_location();
		if (b.get_piece(Coordinate(fromC, fromI)).get_color() != turnPlayer) {
			BTools::debug("NOT CORRECT TURN --> CONTINUE");
			// Displays Board
			b.print_board();
			// Instructs Player To Go Again
			printf("Invalid Input. Go Again (STILL %s)\n", playerName.c_str());
			continue;
		}



		// Moves Pieces & Stores Game State
		state = Move::move(b, Coordinate(fromC, fromI), Coordinate(toC, toI));
		// Regresses To Beginning Of Loop If Move Indicates Error
		if (state == 1) {
			printf("Warning: Your King Is In Check (%s)\n", enemyName.c_str());
		}
		else if (state == -1) {
			BTools::debug("MOVING TO CHECK --> GAME STATE: " + to_string(state) + " --> CONTINUE");
			// Displays Board
			b.print_board();
			// Instructs Player To Go Again
			printf("Invalid. Moving Into Check. Go Again (STILL %s)\n", playerName.c_str());
			continue;
		}

		else if (state == -2) {
			BTools::debug("MOVE ERROR --> GAME STATE: " + to_string(state) + " --> CONTINUE");
			// Displays Board
			b.print_board();
			// Instructs Player To Go Again
			printf("Invalid Input. Go Again (STILL %s)\n", playerName.c_str());
			continue;
		}
		BTools::debug("MOVE OCCURED --> GAME STATE: " + to_string(state));
		// cout << "White: " << Move::game_status(b, 'w') << endl;
		// cout << "Black: " << Move::game_status(b, 'b') << endl;
		//printf("\n");

		// Increments Turn Number At The End Of The Turn
		turnNumber++;

		// // Displays Board If Game Is Not Over
		if (state != 2 && state != 3) {
			b.print_board();
		}

	}
	// Exits Eeturning 0
	return 0;
}