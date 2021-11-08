#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cin; using std::cout;

int main(){

	// class declaration
	TicTacToe game;
	TicTacToeManager manager;

	// temp variables
	int i;
	string play_again_var[]={"y","y","n"};
	
	// temp initialized variables
	i = 0;

	// variables
	int w, o, t;
	int position;
	string play_again;
	string first_player;
	string game_winner;

	// initialized variables
	//play_again = "y";

	// program information
	cout << "\nThis program is a game that is known as Tic-Tac-Toe\n";

	// continue while user enters 'y' to keep playing game.
	do
	{
		// continue until user enters 'X' or 'O'; for first_player
		do
		{
			// get X or O for first player
			cout << "\nDo you want to be 'X' or 'O'? ";
			cin >> first_player;
			strToUpper(first_player);
			
		} while (first_player != "X" && first_player != "O");

		// start game and display board
		game.start_game(first_player);
		cout << game;
		
		// game runs until board is full
		do
		{
			// user interaction; get position
			cin >> game;

			// display marked board
			cout << game;

		// check to see if all positions are filled or if winner has been found; if true, end game
		} while (game.game_over() == false);

		// output
		cout << "Game Over\n\n";

		// get winner
		game_winner = game.get_winner();

		// output winner
		if(game_winner == "C")
		{
			cout << "It's a tie!\n";
		}
		else
		{
			cout << "The winner is " << game_winner << "!  Congratulations!\n\n";
		}

		// reset board using start_game function
		game.start_game(first_player);
		
		// add to TicTacToeManager class - update winner count
		manager.save_game(game);

		// show winners
		manager.get_winner_total(w,o,t);
		cout << "X: " << w << "\n";
		cout << "O: " << o << "\n";
		cout << "Tie: " << t << "\n";

		// user interaction - play again
		cout << "\nDo you want to play again?  Enter 'y' for 'yes' or 'n' for 'no': ";
		//cin >> play_again;
		//strToLower(play_again);
		play_again = play_again_var[i];
		i++;

	} while (play_again == "y");

	// output - show history
	cout << "\nShowing history.\n";
	
	// show winners
	manager.get_winner_total(w,o,t);
	cout << "X: " << w << "\n";
	cout << "O: " << o << "\n";
	cout << "Tie: " << t << "\n";

	// output - end of game
	cout << "\nProgram exiting.\n";
	
	// return
	return 0;
}