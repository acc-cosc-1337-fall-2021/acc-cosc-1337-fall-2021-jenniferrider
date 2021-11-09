#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 1", "Validate TicTacToe get_winner function")
{
	// class declaration
	TicTacToe game;
	TicTacToeManager manager;

	// variables
	int i;
	int ix;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	string auto_player[] = {"X","O","X"};
	int auto_positions[][9] = 	{ 	{1,2,3,4,5,7,6,9,8},
									{2,1,5,4,8,3,6,7,9},
									{4,1,5,2,6,7,3,8,9}
								};

	// do until three games played
	do
	{
		// start game and display board
		game.start_game(auto_player[i]);
		cout << game;

		// initialize turn counter
		ix = 0;

		// do until win or tie
		do
		{
			// get position, mark board, display board
			position = auto_positions[i][ix];
			game.mark_board(position);
			game_done = game.game_over();

			if(game_done == true)
			{
				// validate that if winner found, it's C (tie) for first game, O for second game, X for third game
				game_winner = game.get_winner();

				if(i == 0)
				{
					REQUIRE(game_winner == "C");

					// turn count should be no higher than 8 for testing purposes
					REQUIRE(ix == 8);
				}
				else if(i == 1)
				{
					REQUIRE(game_winner == "O");

					// turn count should be no higher than four for testing purposes
					REQUIRE(ix == 4);
				}
				else
				{
					REQUIRE(game_winner == "X");

					// turn count should be no higher than four for testing purposes
					REQUIRE(ix == 4);
				}
			}

			// iterate ix as a counter to verify the number of turns and iterate positions on board
			ix++;

		} while (game_done == false);

		// iterate i as a counter for number of games; there should be a total of 3
		i++;

	} while(i < 3);

	// validates three games were played
	REQUIRE(i == 3);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 2", "Validate TicTacToeManager class")
{
	// class declaration
	TicTacToe game;
	TicTacToeManager manager;

	// variables
	int i;
	int ix;
	int w, o, t;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	string auto_player[] = {"X","O","X"};
	int auto_positions[][9] = 	{ 	{1,2,3,4,5,7,6,9,8},
									{2,1,5,4,8,3,6,7,9},
									{4,1,5,2,6,7,3,8,9}
								};

	// do until three games played
	do
	{
		// start game and display board
		game.start_game(auto_player[i]);
		cout << game;

		// initialize turn counter
		ix = 0;

		// do until win or tie
		do
		{
			// get position, mark board, display board
			position = auto_positions[i][ix];
			game.mark_board(position);
			game_done = game.game_over();

			if(game_done == true)
			{
				// validate that if winner found, it's C (tie) for first game, O for second game, X for third game
				game_winner = game.get_winner();

				if(i == 0)
				{
					REQUIRE(game_winner == "C");

					// turn count should be no higher than 8 for testing purposes
					REQUIRE(ix == 8);
				}
				else if(i == 1)
				{
					REQUIRE(game_winner == "O");

					// turn count should be no higher than four for testing purposes
					REQUIRE(ix == 4);
				}
				else
				{
					REQUIRE(game_winner == "X");

					// turn count should be no higher than four for testing purposes
					REQUIRE(ix == 4);
				}
			}

			// iterate ix as a counter to verify the number of turns and iterate positions on board
			ix++;

		} while (game_done == false);

		// add to TicTacToeManager class - update winner count
		manager.save_game(game);

		// iterate i as a counter for number of games; there should be a total of 3
		i++;

	} while(i < 3);

	// validates three games were played
	REQUIRE(i == 3);

	// validates winners
	manager.get_winner_total(w,o,t);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}