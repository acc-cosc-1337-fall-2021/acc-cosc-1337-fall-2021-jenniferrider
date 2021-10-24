#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify TicTacToe")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int ix;
	int position;
	int * test_positions;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	first_player = "X";
	int auto_positions[][9]={   {1,2,3,4,5,7,6,9,8},
								{1,2,4,5,7,3,6,8,9},
								{1,4,2,5,3,7,6,8,9},
								{1,2,5,6,9,3,4,7,8}
							};

	// runs four times to check each type of win: no win, row, column, diagonal
	for(i=0;i<4;i++)
	{
		// get position list
		test_positions = auto_positions[i];

		// set counter
		ix = 0;

		// set bool
		game_done = false;

		// start game and display board
		game.start_game(first_player);
		game.display_board();

		do
		{
			// get position, mark board, display board
			position = test_positions[ix];
			game.mark_board(position);
			game.display_board();
			game_done = game.game_over();

			if(ix < 8)
			{
				// Three assertions per run 1 - 3
				// Total in all runs: 9
				if(game_done == true)
				{
					// this occurs during all but first game
					REQUIRE(i != 0);

					// this occurs on the fifth turn
					REQUIRE(ix == 4);

					// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
				}
			}
			else
			{
				// Four assertions for first run only
				// Total in all runs: 4


				// validates this occurs on first run only
				REQUIRE(i == 0);

				// validates the game ran for nine turns when game was over
				REQUIRE(ix == 8);

				// validates that after the last turn, game_over returns true
				REQUIRE(game_done == true);


				// validate no winner
				game_winner = game.get_winner();
				REQUIRE(game_winner == "C");
			}
			
			// iterate i as a counter to verify the game runs 9 times and fetch position from array
			ix++;
		} while (game_done == false);
	}

	REQUIRE(i == 4);
	// Total assertions for this test: 14
	// Total assertsion for all tests: 15
}

