// include
#include "tic_tac_toe_4.h"

/*TicTacToe4::TicTacToe4()
{
    // initialize with 3
    TicTacToe(4);
}*/

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/

bool TicTacToe4::check_column_win()
{
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    // options: 0, 4, 8, 12; 1, 5, 9, 13; 2, 6, 10, 14; 3, 7, 11, 15
    if(pegs[0]==last_player && pegs[4] == last_player && pegs[8] == last_player && pegs[12] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[1]==last_player && pegs[5] == last_player && pegs[9] == last_player && pegs[13] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[2]==last_player && pegs[6] == last_player && pegs[10] == last_player && pegs[14] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[3]==last_player && pegs[7] == last_player && pegs[11] == last_player && pegs[15] == last_player)
    {
        //true
        you_win = true;
    }
    // return
    return you_win;
}



bool TicTacToe4::check_row_win()
{
    //cout << "Check Row Function\n";
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //Options: 0, 1, 2, 3; 4, 5, 6, 7; 8, 9, 10, 11; 12, 13, 14, 15
    if(pegs[0]==last_player && pegs[1] == last_player && pegs[2] == last_player && pegs[3] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[4]==last_player && pegs[5] == last_player && pegs[6] == last_player && pegs[7] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[8]==last_player && pegs[9] == last_player && pegs[10] == last_player && pegs[11] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[12]==last_player && pegs[13] == last_player && pegs[14] == last_player && pegs[15] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe4::check_diagonal_win()
{
    // variables
    bool you_win;
    string last_player;

    //initialize variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //0, 5, 10, 15; 3, 6, 9, 12;
    if(pegs[0] == last_player && pegs[5] == last_player && pegs[10] == last_player && pegs[15] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[3] == last_player && pegs[6] == last_player && pegs[9] == last_player && pegs[12] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}







