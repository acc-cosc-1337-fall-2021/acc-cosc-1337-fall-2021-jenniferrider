// include
#include "tic_tac_toe.h"

#ifndef TICTACTOE4_H
#define TICTACTOE4_H

// class
class TicTacToe4 : public TicTacToe
{
    public:
    // constructor
    TicTacToe4():TicTacToe(4){};

    private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
};

#endif