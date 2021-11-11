// include
#include<iostream>
#include<string>
#include<vector>

// using
using std::ostream; using std::istream;using std::string;using std::vector;

#ifndef TICTACTOE_H
#define TICTACTOE_H

// class interface code
class TicTacToe
{
    public:
        // constructors
        TicTacToe(int size): pegs(size*size," "){};
        TicTacToe(){};

        // functions
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player()const;
        string get_winner();

        // friend functions
        friend ostream& operator<<(ostream& out, const TicTacToe& game);
        friend istream& operator>>(istream& in, TicTacToe& game);

    protected:
        // variables
        vector<string> pegs;

        // functions
        bool virtual check_column_win();
        bool virtual check_row_win();
        bool virtual check_diagonal_win();
        
    private:
        // variables
        string player;
        string winner;

        // functions
        bool check_board_full();

        void set_next_player();
        void set_winner();
        void clear_board();    
};

// helper functions
void game_menu();
void strToUpper(string &str);
void strToLower(string &str);

#endif