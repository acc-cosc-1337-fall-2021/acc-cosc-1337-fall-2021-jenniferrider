// include
#include "tic_tac_toe.h"
#include <memory>

//using
using std::unique_ptr;using std::vector;

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData : public TicTacToe
{
    public:
        void save_games(const std::vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();

};


#endif