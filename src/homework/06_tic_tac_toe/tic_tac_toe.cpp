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

string TicTacToe::get_winner()
{
    return winner;
}

void TicTacToe::set_winner()
{
    // set winner
    winner = (get_player() == "X") ? "O" : "X";
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
    // variables
    bool game_result;

    // initialize variables
    game_result = false;

    // check for row win
    if(check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
    {
        set_winner();
        game_result = true;
    }
    else if(check_board_full() == true)
    {
        winner = "C";
        game_result = true;
    }

    // return
    return game_result;
}

bool TicTacToe::check_column_win()
{
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    // options: 0, 3, 6; 1, 4, 7; 2, 5, 8
    if(pegs[0]==last_player && pegs[3] == last_player && pegs[6] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[1]==last_player && pegs[4] == last_player && pegs[7] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[2]==last_player && pegs[5] == last_player && pegs[8] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe::check_row_win()
{
    //cout << "Check Row Function\n";
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //Options: 0, 1, 2; 3, 4, 5; 6, 7, 8
    if(pegs[0]==last_player && pegs[1] == last_player && pegs[2] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[3]==last_player && pegs[4] == last_player && pegs[5] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[6]==last_player && pegs[7] == last_player && pegs[8] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe::check_diagonal_win()
{
    // variables
    bool you_win;
    string last_player;

    //initialize variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //0, 4, 8; 2, 4, 6;
    if(pegs[0] == last_player && pegs[4] == last_player && pegs[8] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[2] == last_player && pegs[4] == last_player && pegs[6] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
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