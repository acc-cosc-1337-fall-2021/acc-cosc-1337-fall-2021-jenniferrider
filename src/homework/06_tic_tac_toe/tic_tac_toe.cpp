// include
#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cout;

void TicTacToe::display_board() const
{
    //iterate vector of strings pegs to display a tic tac toe board in 3x3
    // variables
    int i;
    string game_name;
    string game_space;
    string board_space;
    string game_liner;

    // initialize variables
    game_name = "Tic-Tac-Toe";
    game_space = string(6,' ');
    board_space = string(5,' ');
    game_liner = string(17,'_');
    
    // pre-set up
    cout<<"\n";
    cout<<string(9,' ')<<game_name<<"\n";

    // add divider, start first row
    cout<<game_space<<game_liner<<"\n\n";
    cout<<board_space;

    // populate board
    for(i=0;i<9;i++)
    {
        // row of three
        cout << "|" << string(2,' ') << pegs[i] << string(2,' ');
        if(i == 2 || i == 5)
        {
            // end row, add divider, start new row
            cout<<"|"<<"\n";
            cout<<game_space<<game_liner<<"\n\n";
            cout<<board_space;
        }
        else if(i == 8)
        {
            // end last row and add divider
            cout<<"|"<<"\n";
            cout<<game_space<<game_liner<<"\n\n";
        }
    }
}

void TicTacToe::start_game(string first_player)
{
    //First player function argument must be X or O
    //In function set player(private variable) to first_player function argument
    TicTacToe::player=first_player;

    //Call the clear_the_board function
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    // variables
    int w;
    string current_player;

    // mark vector w position -1 equal to player (private variable)
    w = position - 1;

    // get current player
    current_player = get_player();

    // mark board
    pegs[w] = current_player;

    //Call set_next_player private function
    set_next_player();
}

string TicTacToe::get_player()const
{
    // return the player (private variable) value
    return player;
}

void TicTacToe::set_next_player()
{
    // variables
    string current_player;

    // initialize variables
    current_player = get_player();

    // set player. if private variable player X player is O else player is X
    player = (current_player == "X") ? "O" : "X";
}

void TicTacToe::clear_board()
{
    // variables
    int i;

    // set all 9 elements to a " " (space)
    for(i=0;i<9;i++)
    {
        pegs[i] = " ";
    }
}

bool TicTacToe::game_over()
{
    // return check board full function return 
    return check_board_full();
}

bool TicTacToe::check_board_full()
{
    // variables
    int i;
    bool not_available;
    string slot;
    string peg_slot;

    // initialize variables
    not_available = true;
    slot = " ";

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<9;i++)
    {
        peg_slot = pegs[i];
        if(peg_slot == slot)
        {
            not_available = false;
        }
    }

    // return
    return not_available;
}

void TicTacToe::clear_game_data()
{
    //clear game data if game is over
    bool i;

    if(game_over() == true)
    {
        // call clear_board to clear the board
        clear_board();

        // game over
		cout << "\nGame over!\n\n";
    }
}
void clear_local_data(vector<string> &all_slots, vector<int> &game_history)
{
    // variables
    int i;

    // clear all_slots data
    for(i=0;i<9;i++)
    {
        all_slots[i] = " ";
    }

    // clear game history
    game_history.clear();
}

void get_game_history(const vector<int> &game_history, int game_count)
{
    // variables
    int i;
    string game_num;
    string player;

    // get text
	game_num=(game_count == 1) ? "game" : "games";

    // display output
	cout << "\n\nGame History\n\n";
	cout << "You played " << game_count << " " << game_num << ".\n\n";
	for(i=0; i<9; i++)
	{
		player = (i == 0 || i % 2 == 0) ? "X" : "O";
		cout << "  Turn " << i + 1 << ": " << player << " " << game_history[i] << "\n";
	}
}

void strToUpper(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = toupper(str[i]);
    }
}

void strToLower(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}