// include
#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win()
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

bool TicTacToe3::check_row_win()
{
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    // Options: 0, 1, 2; 3, 4, 5; 6, 7, 8
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

bool TicTacToe3::check_diagonal_win()
{
    // variables
    bool you_win;
    string last_player;

    // initialize variables
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
