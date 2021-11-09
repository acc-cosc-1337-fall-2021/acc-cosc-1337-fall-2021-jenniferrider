// include
#include<string>
#include<vector>
#include<iostream>

// using
using std::string; using std::vector;using std::ostream; using std::istream;

#ifndef TICTACTOE_H

// class interface code
class TicTacToe
{
    public:
        // functions
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player()const;
        string get_winner();

        // friend functions
        friend ostream& operator<<(ostream& out, const TicTacToe& game);
        friend istream& operator>>(istream& in, TicTacToe& game);
        
    private:
        // variables
        string player;
        string winner;
        vector<string> pegs = vector<string>(9," ");

        // functions
        bool check_board_full();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_next_player();
        void set_winner();
        void clear_board();    
};

// helper functions
void strToUpper(string &str);
void strToLower(string &str);

#endif