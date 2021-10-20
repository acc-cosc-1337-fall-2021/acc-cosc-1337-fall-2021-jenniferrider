// include
#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cout;

void TicTacToe::start_game(string first_player)
{
    //First player function argument must be X or O
    //In function set player(private variable) to first_player function argument
    player = first_player;

    //Call the clear_the_board function
    clear_board();
}

void TicTacToe::display_board() const
{
    //iterate vector of strings pegs to display a tic tac toe board in 3x3
    // variables
    int i;
    string game_name;
    string game_col;
    string game_row;
    string board_left;

    // initialize variables
    game_name = "Tic-Tac-Toe";
    game_col = "|";
    game_row = string(16,' ') + string(17,'_');
    board_left = string(15,' ');

    // pre-set up
    cout<<"\n";
    cout<<string(19,' ')<<game_name<<"\n";

    // add divider, start first row
    cout << game_row << "\n\n";
    cout << board_left;

    // populate board
    for(i=0;i<9;i++)
    {
        // row of three
        cout << game_col << string(2,' ') << pegs[i] << string(2,' ');
        if(i == 2 || i == 5 || i == 8)
        {
            // end row, add divider
            cout << game_col << "\n";
            cout << game_row << "\n\n";

            // start new row
            if(i != 8){cout<<board_left;}
        }
    }
}

void TicTacToe::mark_board(int position)
{
    // variables
    int w;
    string current_player;

    // get current player
    current_player=get_player();

    // mark vector w position -1 equal to player (private variable)
    w = position - 1;

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

    // get current player
    current_player = get_player();

    // set player. if private variable player X player is O else player is X
    player = (current_player == "X") ? "O" : "X";
}

void TicTacToe::clear_board()
{
    // variables
    int i;
    string slot;

    // initialize variables
    slot = " ";

    // set all 9 elements to a " " (space)
    for(i=0;i<9;i++)
    {
        pegs[i] = slot;
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

    // initialize variables
    not_available = true;
    slot = " ";

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<9;i++)
    {
        if(pegs[i]== slot){ not_available = false;}
    }

    // return
    return not_available;
}

void display_menu()
{
    // enumerated values
    enum Choices { Automated = 0, Live = 1, Quit = 2};

    // menu
    cout << "\nPick Your Poison\n\n";
    cout << "0 - Automated Game\n";
    cout << "1 - Live Against Computer\n";
    cout << "2 - Live Two Player\n";
    cout << "3 - Quit\n\n";
    cout << "Your choice: ";
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