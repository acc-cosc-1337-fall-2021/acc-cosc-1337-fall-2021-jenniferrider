#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>

using std::cout;using std::unique_ptr;using std::make_unique;using std::move;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 1", "3X3 - Validate TicTacToe getwinner function")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 3X3
	game = make_unique<TicTacToe3>();

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
	first_player = "X";
	game_done = false;
	string auto_player[] = {"X","O","X"};
	int auto_positions[][9] = 	{ 	{1,2,3,4,5,7,6,9,8},
									{2,1,5,4,8,3,6,7,9},
									{4,1,5,2,6,7,3,8,9}
								};

	// do until three games played
	do
	{
		cout << "\nHi from beginning of loop!\n";
		cout << game->get_player() << "\n";
		// start game and display board
		//game->start_game(auto_player[i]);
		game->start_game(first_player);
		cout << "Just started game!\n";
		cout << *game;
		cout << "Hi again!";

		// initialize turn counter
		ix = 0;

		// do until win or tie
		do
		{
			// get position, mark board, display board
			position = auto_positions[i][ix];
			game->mark_board(position);
			game_done = game->game_over();

			if(game_done == true)
			{
				// validate that if winner found, it's C (tie) for first game, O for second game, X for third game
				game_winner = game->get_winner();

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

		cout << "Hi 1:\n";
		cout << "Get Player1: " << game->get_player() << "\n";

		// add to TicTacToeManager class - update winner count
		manager.save_game(move(game));

		cout << "Hi 2:\n";
		cout << "Get Player2: " << game->get_player() << "\n";

		manager.get_winner_total(w,o,t);
		cout << w << "\n";
		cout << o << "\n";
		cout << t << "\n";

		cout << "Hi 3!\n";
		cout << "Get Player3: " << game->get_player() << "\n";

		// iterate i as a counter for number of games; there should be a total of 3
		i++;
		cout << "Hi end of loop!";

	} while(i < 3);

	// validates three games were played
	REQUIRE(i == 3);

	// validates winners
	manager.get_winner_total(w,o,t);
	REQUIRE(w == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}

/*TEST_CASE("Verify Tic-Tac-Toe Test Case 2", "4X4 - Test First Player Set to X")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 8 or after the last position is filled
			REQUIRE(i == 15);

      		// validate X is player
			REQUIRE(first_player == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 3", "4X4 - Test First Player Set to O")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 8 or after the last position is filled
			REQUIRE(i == 15);
      
      		// validate X is player
			REQUIRE(first_player == "O");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated nine times
	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 4", "4X4 - Tie Game - No Winner")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,2,3,4,6,5,7,8,9,10,12,11,14,13,16,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 15);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "C");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 16);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 5", "4X4 - Winner - Test Column Win 1,5,9,13")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,2,5,6,9,10,13,14,3,4,7,8,11,12,16,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 6", "Winner - Test Column Win 2,6,10,14")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {2,1,6,5,10,9,14,13,15,3,4,7,8,11,12,16};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 7", "Winner - Test Column Win 3,7,11,15")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {3,1,7,5,11,9,15,13,14,2,4,6,8,10,12,16};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 8", "Winner - Test Column Win 4,8,12,16")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {4,1,8,5,12,9,16,13,14,2,3,6,10,7,11,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 9", "Winner - Test Row Win 1,2,3,4")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,5,2,6,3,7,4,8,9,12,13,10,11,14,15,16};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 10", "Winner - Test Row Win 5,6,7,8")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {5,2,6,3,7,4,8,9,12,13,10,11,14,15,16,1};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 11", "Winner - Test Row Win 9.10,11,12")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {9,5,10,6,11,7,12,1,2,3,4,8,13,14,15,16};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 12", "Winner - Test Row Win 13,14,15,16")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {13,9,14,10,15,11,16,12,1,2,3,4,5,6,7,8};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 13", "Winner - Test Diagonal Win 1,6,11,16")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {1,2,6,3,11,10,16,9,12,13,4,5,7,8,14,15};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}

TEST_CASE("Verify Tic-Tac-Toe Test Case 14", "Winner - Test Diagonal Win 4,7,10,13")
{
	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// 4X4
	game = make_unique<TicTacToe4>();

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
	int auto_positions[16] = {4,2,7,3,10,1,13,9,12,13,2,5,8,14,15,16};

	// start game and display board
	game->start_game(first_player);
	cout << *game;

	do
	{
		// get position, mark board, display board
		position = auto_positions[i];
		game->mark_board(position);
		game_done = game->game_over();

		if(game_done == true)
		{
			// validates this occurs when i = 15 or after the last position is filled
			REQUIRE(i == 6);

			// validate no winner
			game_winner = game->get_winner();
			REQUIRE(game_winner == "X");
		}
		
		// iterate i as a counter to verify the game runs 9 times and fetch position from array
		i++;
	} while (game_done == false);

	// validates game iterated sixteen times
	REQUIRE(i == 7);
}*/

//Total Tests: 16
// Verification: 1
// 3X3: 1 - Verify 
// 4X4: 14
