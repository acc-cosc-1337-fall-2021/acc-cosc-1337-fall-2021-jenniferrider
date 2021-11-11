// include
#include "tic_tac_toe.h"

#ifndef TICTACTOE3_H
#define TICTACTOE3_H

// class
class TicTacToe3 : public TicTacToe
{
    public:
    // constructor
    TicTacToe3():TicTacToe(3){};

    private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
};

#endif