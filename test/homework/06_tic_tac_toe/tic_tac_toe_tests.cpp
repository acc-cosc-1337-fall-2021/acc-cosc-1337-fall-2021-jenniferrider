#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	string first_player;

	// initialized variables
	i = 0;
	first_player = "X";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			REQUIRE(game.game_over() == false);
		}
		else
		{
			// validates that after the last turn, game_over returns true
			REQUIRE(game.game_over() == true);

			// validates this occurs when i = 8 or after the last p;osition is filled
			REQUIRE(i == 8);
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game.game_over() == false);

	// validates game iterated nine times
	REQUIRE(i == 9);
}