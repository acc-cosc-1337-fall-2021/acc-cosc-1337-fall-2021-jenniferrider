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
    string g_col;
    string g_row;
    string g_sp;

    // initialize variables
    g_col = "|";
    g_row = string(1,' ') + string(17,'_') + "\n\n";
    g_sp = string(2,' ');

    // pre-set up
    cout<<"\n";
    cout<<g_sp+g_sp<<"Tic-Tac-Toe"<<"\n";

    // add divider, start first row
    cout<<g_row;

    // populate board
    for(i=0;i<9;i++)
    {
        // row of three
        cout<<g_col<<g_sp<<pegs[i]<<g_sp;
        if( (i+1) % 3 == 0)
        {
            // end row, add divider
            cout << g_col << "\n";
            cout << g_row;
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
        if(pegs[i]== " "){ not_available = false;}
    }

    // return
    return not_available;
}