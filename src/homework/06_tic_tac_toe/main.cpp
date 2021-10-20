// includes
#include "tic_tac_toe.h"
#include <iostream>
#include <time.h>
#include <limits>

// using
using std::cin; using std::cout;

// main
int main() 
{
	// class declaration
	TicTacToe game;
	GamePlay play;

	// variables
	int mode;
	int game_count;
	int turn_count;
	int position;
	int last_position;
	double tm_elapsed;
	bool slot_available;
	string play_again;
	string answer;
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

	// clear history
	play.clear_game_history();

	// program information
	cout << "\nWelcome to Tic-Tac-Toe!  This is a game everyone can play!\n";

	// starting game
	time_t start = time(NULL);

	do
	{
		// clear game history
		play.clear_game_history();

		// set mode - auto or live play
		play.display_menu();
		cin >> mode;

		while (!std::cin.good())
		{
    		cin.clear();
    		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		cout<<"\nThat was not a number.\n";
			play.display_menu();
			cin >> mode;
		}

		// quit game
		if(mode == 3)
		{
			cout << "Are you sure you want to quit?  Enter 'y' for 'yes' or 'n' for 'no': ";
			cin >> answer;
			strToLower(answer);

			if(answer != "n")
			{
				// break out of loop and quit
				break;
			}
			else
			{
				// set mode - auto or live play
				play.display_menu();
				cin >> mode;

				while (!std::cin.good())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout<<"\nThat was not a number.\n";
					play.display_menu();
					cin >> mode;
				}
			}
		}

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
			// quit game
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
			current_player = game.get_player();

			// play modes 1 and 2
			if(mode == 1 || mode == 2)
			{

				// get position
				if(mode == 1 && current_player != first_player)
				{
					last_position = position;
					position = play.get_next_move(last_position);
					play.update_game_history(current_player, position, turn_count);
				}
				else
				{
					slot_available = false;
					do
					{
						cout<<"Select a position between 1 and 9: ";
						cin>>position;
						while (!std::cin.good())
						{
    						cin.clear();
    						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    						cout<<"\nThat was not a number. Try again\n";
							game.display_board();
							cout<<"Select a position between 1 and 9: ";
							cin >> position;
						}
			
						// validate slot is free
						if(position < 1 || position > 9)
						{
							cout<<"That is not a valid position. Try again.\n";
							game.display_board();
						}
						else
						{
							slot_available = play.slot_available(position);
							if(slot_available == false)
							{
								cout << "\nThat position is filled. Try again.\n";
								game.display_board();
							}
							else
							{
								play.update_game_history(current_player, position, turn_count);
							}
						}

					} while (slot_available == false);
				}
			}
			// automated game
			else
			{
				// automated choice from array and output text
				position = auto_positions[turn_count];
			}

			// display position
			cout << "\nPlayer " << current_player << "\n";
			cout << "Last Move: " << position << "\n\n";

			// mark position and display board
			game.mark_board(position);
			game.display_board();

			// turn counter
			turn_count++;

		} while (game.game_over() == false);

		// game count
		game_count++;

		// clear board 
		game.end_game();

		// user interaction - play again
		cout << "\nDo you want to play again?  Enter 'y' for 'yes' or 'n' for 'no': ";
		cin >> play_again;
		strToLower(play_again);

	} while(play_again == "y");

	// update games played
	play.update_games_played(game_count);

	// end time
	time_t end = time(NULL);

	// get elapsed time
	tm_elapsed = end - start;

	// clear console
	system("clear");

	// display game history
	if(mode==1 || mode ==2)
	{
		play.display_game_history(tm_elapsed);
	}

	// end game
	cout<< "\nHope to see you again soon!\n";
	
	// return
	return 0;
}