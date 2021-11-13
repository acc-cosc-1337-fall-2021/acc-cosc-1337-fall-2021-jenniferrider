// include
#include "tic_tac_toe.h"
#include <memory>

// using
using std::ostream;using std::vector;using std::unique_ptr;

#ifndef TICTACTOEMANAGER_H
#define TICTACTOEMANAGER_H

class TicTacToeManager 
{
    public:
        // functions
        void save_game(unique_ptr<TicTacToe>&& b);
        void get_winner_total(int& w, int& o, int& t);

        // friend functions
        friend ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
    
    private:
        // variables
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        vector<unique_ptr<TicTacToe>> games_played;

        //functions
        void update_winner_count(string winner);
};

#endif