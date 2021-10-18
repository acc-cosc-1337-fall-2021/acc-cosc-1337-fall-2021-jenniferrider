#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe")
{
	// class
	TicTacToe game;

	// variables
	int turn_count;
	int position;
	string first_player;

	// initialized variables
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};
	first_player = "X";

	// game
	game.start_game(first_player);
	game.display_board();

	do
	{
		for(turn_count=0;turn_count<9;turn_count++)
		{
			position = auto_positions[turn_count];
			game.mark_board(position);
			game.display_board();
		}

		if(turn_count < 9)
		{
			REQUIRE(game.game_over() == false);
		}
		else
		{
			REQUIRE(game.game_over() == true);
		}

	} while (game.game_over() == false);

	REQUIRE(turn_count == 9);
}