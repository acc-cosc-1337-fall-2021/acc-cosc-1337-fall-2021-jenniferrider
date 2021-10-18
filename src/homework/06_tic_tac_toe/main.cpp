// includes
#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cin; using std::cout; using std::vector;

// main
int main() 
{
	// class declaration
	TicTacToe game;

	// variables
	int mode;
	int game_count;
	int turn_count;
	int position;
	bool pass_slot;
	string play_again;
	string first_player;
	string second_player;
	string current_player;
	string open_slot;
	string position_text;

	// initialized variables
	game_count = 0;
	play_again = "y";
	open_slot = " ";
	position_text = "Last Move: ";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};
	vector<string> all_slots = vector<string>(9," ");
	vector<int> game_history = vector<int>(9);

	// program information
	cout << "\nWelcome to Tic-Tac-Toe!  This is a game everyone can play!\n";

	// starting game
	do
	{
		// clear any local existing history and data
		clear_local_data(all_slots, game_history);

		// set mode - auto or live play
		cout << "\nDo you want to watch the automated game or play live?  Enter 0 for automated and 1 for live: ";
		cin >> mode;

		// if playing live, choose X or O
		if(mode == 1)
		{
			do
			{
				// get X or O for first player
				cout << "\nDo you want to be X or O? ";
				cin >> first_player;
				strToUpper(first_player);

			} while (first_player != "X" && first_player != "O");

			// second player
			second_player = (first_player == "X") ? "O" : "X";
		}
		else
		{
			first_player = "X";
		}

		// display board for game start
		game.start_game(first_player);
		game.display_board();

		// user input - wait for user to be ready
		system("pause");

		// set counter for rounds
		turn_count = 0;

		// game runs until board is full
		do
		{
			// display round number
			cout << "\nRound " << turn_count + 1 << "\n";

			// play mode
			if(mode == 1)
			{
				// set pass slot
				pass_slot = false;

				do
				{
					// round selection
					if(turn_count == 0 || turn_count % 2 == 0)
					{
						// get current player and choice
						current_player = first_player;
						cout<<"\nSelect a position between 1 and 9: ";
						cin>>position;
					}
					else
					{
						// get current player and position
						current_player = second_player;
						position = (rand() % 9) + 1;
					}

					// validate slot is free
					if(all_slots[position-1] == open_slot)
					{
						pass_slot = true;
					}
					else
					{
						// user output if first player 
						if(current_player == first_player){ cout << "\nThat position is filled. Try again.\n";}
					}

				} while (pass_slot == false);
				
				// update all_slots and game history
				all_slots[position-1] = current_player;
				game_history[turn_count] = position;
			}
			else
			{
				// automated choice and output text
				position = auto_positions[turn_count];
			}

			// display position
			cout << position_text << position << "\n\n";

			// mark position, display board, check to see if all slots are filled
			game.mark_board(position);
			game.display_board();

			// turn counter
			turn_count++;

		} while (game.game_over() == false);

		// game count
		game_count++;

		// clear board data
		game.clear_game_data();

		// user interaction - play again
		cout << "\nDo you want to play again? ";
		cin >> play_again;

		// convert to lowercase
		strToLower(play_again);

	} while(play_again == "y");

	// clear console
	system("clear");

	// display game history
	if(mode == 1)
	{
		get_game_history(game_history, game_count);
	}

	// clear local data
	clear_local_data(all_slots, game_history);

	// end game
	cout<< "\nThank you for playing!\n";
	
	// return
	return 0;
}