#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 1", "Test Player Set to X")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
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
		game_done = game.game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 8 or after the last position is filled
			REQUIRE(i == 8);

			// validate no winner
			game_winner = game.get_winner();
			REQUIRE(first_player == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 9);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 2", "Test Player Set to O")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "O";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 8 or after the last position is filled
			REQUIRE(i == 8);

			// validate no winner
			game_winner = game.get_winner();
			REQUIRE(first_player == "O");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 9);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 3", "Tie Game - No Winner")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
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
		game_done = game.game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 8 or after the last position is filled
			REQUIRE(i == 8);

			// validate no winner
			game_winner = game.get_winner();
			REQUIRE(game_winner == "C");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 9);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 4", "Winner - Test Column Win 1,4,7")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,2,4,5,7,3,6,8,9};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 5", "Winner - Test Column Win 2,5,8")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {2,1,5,4,8,3,6,7,9};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 6", "Winner - Test Column Win 3,6,9")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {3,1,6,4,9,2,5,7,8};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 7", "Winner - Test Row Win 1 - 3")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,4,2,5,3,7,6,8,9};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 8", "Winner - Test Row Win 4 - 6")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {4,1,5,2,6,7,3,8,9};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 9", "Winner - Test Row Win 7 - 9")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {7,1,8,2,9,6,3,4,5};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}



TEST_CASE("Verify Tic-Tac-Toe Test Case 10", "Winner - Test Diagonal Win 1,5,9")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {1,3,5,4,9,2,6,7,8};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}
TEST_CASE("Verify Tic-Tac-Toe Test Case 11", "Winner - Test Diagonal Win 7,5,3")
{
	// class declaration
	TicTacToe game;

	// variables
	int i;
	int position;
	bool game_done;
	string first_player;
	string game_winner;

	// initialized variables
	i = 0;
	game_done = false;
	first_player = "X";
	int auto_positions[9] = {7,1,5,4,3,2,6,9,8};

	// start game and display board
	game.start_game(first_player);
	game.display_board();

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game.mark_board(position);
		game_done = game.game_over();

		if(i < 8)
		{
			// validates that all turns before the last one game_over returns false
			if(game_done == true)
			{
				// turn count should be no higher than four for testing
				REQUIRE(i == 4);

				// validate that if winner found, it's X (first player)
					game_winner = game.get_winner();
					REQUIRE(game_winner == "X");
			}
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 5);
}