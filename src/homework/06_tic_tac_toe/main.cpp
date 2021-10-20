// includes
#include "tic_tac_toe.h"
#include <iostream>
#include <time.h>

// using
using std::cin; using std::cout;

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
	double tm_elapsed;
	bool slot_available;
	string play_again;
	string first_player;
	string current_player;
	string open_slot;

	// initialized variables
	game_count = 0;
	play_again = "y";
	open_slot = " ";
	int auto_positions[9] = {1,2,3,4,5,7,6,9,8};			// array for automated play
	vector<string> all_slots = vector<string>(9," ");		// tracks used slots
	vector<int> game_history = vector<int>(9);				// keeps turn history of single game

	// program information
	cout << "\nWelcome to Tic-Tac-Toe!  This is a game everyone can play!\n";

	// starting game
	time_t start = time(NULL);

	do
	{
		// clear local existing history and data
		clear_local_data(game_history, all_slots);

		// set mode - auto or live play
		display_menu();
		cin >> mode;

		// if playing live, choose X or O
		if(mode == 1 || mode == 2)
		{
			do
			{
				// get X or O for first player
				cout << "\nDo you want to be X or O? ";
				cin >> first_player;
				strToUpper(first_player);

			} while (first_player != "X" && first_player != "O");
		}
		else if (mode == 0)
		{
			first_player = "X";
		}
		else
		{
			break;
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

			// get current player
			current_player=(turn_count ==0 || turn_count % 2 == 0) ? first_player : (first_player == "X") ? "O" : "X";

			// play modes 1 and 2
			if(mode == 1 || mode == 2)
			{
				// set pass slot
				slot_available = false;

				do
				{
					// get current player
					//current_player=(turn_count ==0 || turn_count % 2 == 0) ? first_player : (first_player == "X") ? "O" : "X";

					// get position
					if(mode == 1 && turn_count % 2 != 0)
					{
						cout << "\nAutomated Player\n";
						position = (rand() % 9) + 1;
					}
					else
					{
						cout<<"\nSelect a position between 1 and 9: ";
						cin>>position;
					}
					
					// modes: live against computer and two player
					/*if(turn_count == 0 || turn_count % 2 == 0)
					{
						// get current player and choice
						current_player = first_player;
						cout<<"\nSelect a position between 1 and 9: ";
						cin>>position;
					}
					else
					{
						// get current player and position
						current_player = (first_player == "X") ? "O" : "X";
						position = (rand() % 9) + 1;
					}*/

					// validate slot is free
					if(all_slots[position-1] == open_slot)
					{
						slot_available = true;
					}
					else
					{
						// user output if first player or in mode 2 player live play
						//if(current_player == first_player || mode == 2){ cout << "\nThat position is filled. Try again.\n";}
						game.display_board();
					}

				} while (slot_available == false);
				
			}
			else
			{
				// automated choice from array and output text
				//current_player=(turn_count == 0 || turn_count % 2 == 0) ? first_player : (first_player == "X") ? "O" : "X";
				position = auto_positions[turn_count];
			}

			// update all_slots and game history
			all_slots[position-1] = current_player;
			game_history[turn_count] = position;

			// display position
			cout << "Player " << current_player << "\n";
			cout << "Last Move: " << position << "\n\n";

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
		strToLower(play_again);

	} while(play_again == "y");

	// clear console
	//system("clear");

	// end time
	time_t end = time(NULL);
	tm_elapsed = end - start;

	// display game history
	//if(mode == 1 || mode == 2){ get_game_history(game_history, all_slots, game_count,tm_elapsed);}
 	get_game_history(game_history, all_slots, game_count,tm_elapsed);

	// clear local data
	clear_local_data(game_history, all_slots);

	// end game
	cout<< "\nHope to see you again soon!\n";
	
	// return
	return 0;
}