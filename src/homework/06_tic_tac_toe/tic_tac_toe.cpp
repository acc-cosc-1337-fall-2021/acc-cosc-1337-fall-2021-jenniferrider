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
    string g_left;
    string g_name;
    string g_row;
    string g_col;
    string g_sp;

    // base measurements of board space
    // total area: 45 spaces
    //// left indent: 20 spaces (g_left)
    //// board width: 25 spaces (g_row)
    ////// name indent: 7 spaces (g_name)
    ////// square width: 7 spaces (g_sp)
    ////// square height: 2 lines 

    // initialize variables
    g_left = string(20,' ');
    g_name = string(7,' ');
    g_row = string(25,'_') + "\n\n";
    g_col = "|";
    g_sp = string(3,' ');

    // pre-set up
    cout<<"\n";
    cout << g_left << g_name << "Tic-Tac-Toe" << "\n";

    // add divider
    cout << g_left << g_row;

    // set up first row
    cout << g_left;

    // populate board
    for(i=0;i<9;i++)
    {
        // row of three
        cout << g_col << g_sp << pegs[i] << g_sp;
        if( (i+1) % 3 == 0)
        {
            // end row
            cout << g_col << "\n";

            // add divider
            cout << g_left << g_row;

            // start new row (if not last)
            if(i != 8)
            { 
                cout << g_left; 
            }
        }
    }
}

void TicTacToe::mark_board(int position)
{
    // variables
    int w;

    // mark vector w position -1 equal to player (private variable)
    w = position - 1;

    // mark board
    pegs[w] = get_player();

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
    // set player. if private variable player X player is O else player is X
    player = (get_player() == "X") ? "O" : "X";
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

    // initialize variables
    not_available = true;

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<9;i++)
    {
        if(pegs[i] == " "){ not_available = false; break; }
    }

    // return
    return not_available;
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
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}