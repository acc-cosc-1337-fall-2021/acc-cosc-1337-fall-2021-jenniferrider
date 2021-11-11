// include
#include "tic_tac_toe_manager.h"
#include <utility>

using std::cout;

void TicTacToeManager::save_game(unique_ptr<TicTacToe>&& b)
{
    // call update winner count pass the winner from TicTacToe to update x, o, or tie totals.
    update_winner_count(b->get_winner());

    // add the TicTacToe to games vector with push_back
    games_played.push_back(move(b));
}

void TicTacToeManager::update_winner_count(string winner)
{
    //if winner X increment x_win, if winner O increment o_win, and else increment ties 
    if(winner == "X")
    {
        x_win = x_win + 1;
    }
    else if(winner == "O")
    {
        o_win = o_win + 1;
    }
    else
    {
        ties = ties + 1;
    }
}

void TicTacToeManager::get_winner_total(int& w, int& o, int& t)
{
    // Use references to get the winners  
    w = x_win;
    o = o_win;
    t = ties;
}

// TicTacToeManager class friends
ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    // variables
    int i;

    // Overload <<-Loop through vector of TicTacToe and call the TicTacToe cout overload.
    for(i=0;i<manager.games_played.size();i++)
    {
        out << "\nGame " << i+1 << "\n";
       // this gives the value
        out << *manager.games_played[i] <<"\n";
    }

    // return
    return out;
}
