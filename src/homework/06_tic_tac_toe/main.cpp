#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_manager.h"

// using
using std::cin;using std::cout;using std::unique_ptr;using std::make_unique;
//class TicTacToe;

int main(){

	// class declaration
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;

	// variables
	int version_choice;
	int w, o, t;
	int position;
	string play_again;
	string first_player;
	string game_winner;

	// initialized variables
	play_again = "y";

	// program information
	cout << "\nThis is a game that is known as Tic-Tac-Toe.\n";

	// continue while user enters 'y' to keep playing game.
	do
	{
		// get 3 or 4 game
		game_menu();
		cin >> version_choice;

		(version_choice == 1)?game=(make_unique<TicTacToe3>()):game=(make_unique<TicTacToe4>());

		/*if(version_choice == 1)
		{
			game = make_unique<TicTacToe3>();
		}
		else
		{
			game = make_unique<TicTacToe4>();
		}*/

		// continue until user enters 'X' or 'O'; for first_player
		do
		{
			// get X or O for first player
			cout << "\nDo you want to be 'X' or 'O'? ";
			cin >> first_player;
			strToUpper(first_player);
			
		} while (first_player != "X" && first_player != "O");

		// start game and display board
		game->start_game(first_player);
		cout << *game;
		
		// game runs until board is full
		do
		{
			// user interaction; get position
			cin >> *game;

			// display marked board
			cout << *game;

		// check to see if all positions are filled or if winner has been found; if true, end game
		} while (game->game_over() == false);

		// output
		cout << "Game Over\n\n";

		// get winner
		game_winner = game->get_winner();

		// output winner
		if(game_winner == "C")
		{
			cout << "It's a tie!\n";
		}
		else
		{
			cout << "The winner is " << game_winner << "!  Congratulations!\n\n";
		}

		// add to TicTacToeManager class - update winner count
		manager.save_game(move(game)); // use with function def argument &&

		// get winner history
		manager.get_winner_total(w,o,t);

		// show winner history
		cout << "Running Totals:\n";
		cout << "X: " << w << "\n";
		cout << "O: " << o << "\n";
		cout << "Tie: " << t << "\n";

		// user interaction - play again
		cout << "\nDo you want to play again?  Enter 'y' for 'yes' or 'n' for 'no': ";
		cin >> play_again;
		strToLower(play_again);

	} while (play_again == "y");
	
	// get winner history
	manager.get_winner_total(w,o,t);

	// display winner history
	cout << "\nFinal Totals:\n";
	cout << "X: " << w << "\n";
	cout << "O: " << o << "\n";
	cout << "Tie: " << t << "\n";

	// game history
	cout << manager;

	// output - end of game
	cout << "\nGoodbye.\n";
	
	// return
	return 0;
}