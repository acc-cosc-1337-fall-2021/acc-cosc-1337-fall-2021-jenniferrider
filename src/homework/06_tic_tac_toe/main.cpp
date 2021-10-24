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
	StringExtension stng;

	// variables
	int mode;
	int game_count;
	int turn_count;
	int position;
	int * auto_positions;
	int auto_game;
	double tm_elapsed;
	string play_again;
	string first_player;
	string current_player;
	string game_winner;

	// initialized variables
	game_count = 0;
	auto_game = 0;
	play_again = "y";
	int game_positions[][9]={   {1,2,3,4,5,7,6,9,8},
								{1,2,4,5,7,3,6,8,9},
								{1,4,2,5,3,7,6,8,9},
								{1,2,5,6,9,3,4,7,8}
							};

	// clear game history
	//play.clear_game_history();

	// program information
	cout << "\nWelcome to Tic-Tac-Toe!  This is a game everyone can play!\n";

	// starting game time
	time_t start = time(NULL);

	do
	{
		// set mode - auto, against computer, or live
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

		// player decision 
		if(mode == 1 || mode == 2)
		{
			do
			{
				// get X or O for first player
				cout << "\nDo you want to be X or O? ";
				cin >> first_player;
				stng.strToUpper(first_player);

			// continue until chooser picks x or o
			} while (first_player != "X" && first_player != "O");
		}
		else if (mode == 0)
		{
			//cout << "Auto: " << auto_game << "\n";
			first_player = "X";
			auto_positions = game_positions[auto_game];
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
			// display round
			cout << "Round " << turn_count + 1 << "\n\n";

			// get current player
			current_player = game.get_player();

			// get position
			if(mode == 1 || mode == 2)
			{
				// mode 1 - play against computer
				if(mode == 1 && current_player != first_player)
				{
					position = play.get_next_move();
				}
				else
				{
					do
					{
						cout<<"Select a position between 1 and 9: ";
						cin>>position;
						if (!std::cin.good())
						{
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							position = 12345;
						}

					// continue until position is valid number
					} while (play.validate_position(position) == false);
				}
			}
			else
			{
				// automated choice from array and output text
				position = auto_positions[turn_count];
			}
			
			// update turn history
			play.update_turn_history(current_player, position, turn_count);

			// display turn info
			play.display_turn_info();

			// mark position and display board
			game.mark_board(position);
			game.display_board();

			// update turn count
			turn_count++;

		} while (game.game_over() == false);

		// check for winner
		game_winner = game.get_winner();
		if(game_winner == "C")
		{
			cout << "It's a tie!\n";
		}
		else
		{
			cout << "The winner is " << game_winner << "!\n\n";
		}

		// update game history
		play.update_game_history(game_count, mode, game_winner);

		// update game count
		game_count++;

		// clear board 
		game.end_game();
		play.clear_game_history();

		if(mode == 0)
		{
			// update autogames
			auto_game++;
			if(auto_game == 4){ auto_game = 0;}
		}

		// user interaction - play again
		cout << "\nDo you want to play again?  Enter 'y' for 'yes' or 'n' for 'no': ";
		cin >> play_again;
		stng.strToLower(play_again);

	} while(play_again == "y");

	// end time and get difference
	time_t end = time(NULL);
	tm_elapsed = end - start;

	// clear console
	//system("clear");

	// display game history
	play.display_game_history(tm_elapsed);

	// end game
	cout<< "\nHope to see you again soon!\n";
	
	// return
	return 0;
}