// include
#include<string>
#include<vector>
#include<iostream>

// using
using std::vector;using std::string;using std::ostream; using std::istream;

// class declarations
class TicTacToe;

#ifndef TICTACTOEMANAGER_H

class TicTacToeManager
{
    public:
        // functions
        void save_game(TicTacToe b);
        void get_winner_total(int& w, int& o, int& t);

        // friend functions
        friend ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
    
    private:
        // variables
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        vector<TicTacToe> games_played;

        //functions
        void update_winner_count(string winner);
};

#endif