// include
#include "tic_tac_toe.h"
#include "math.h"

// using
using std::cout;using std::sqrt;

// class declaration
void TicTacToe::start_game(string first_player)
{
    //In function set player(private variable) to first_player function argument
    player = first_player;

    //Call the clear_the_board function
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    // variables
    int w;

    // mark vector w position -1 equal to player (private variable)
    w = position - 1;

    // mark board
    pegs[w] = get_player();

    //Call set_next_player private function
    set_next_player();
}

string TicTacToe::get_player()const
{
    // return the player (private variable) value
    return player;
}

void TicTacToe::set_next_player()
{
    // set player. if private variable player X player is O else player is X
    player = (get_player() == "X") ? "O" : "X";
}

string TicTacToe::get_winner()
{
    // return winner
    return winner;
}

void TicTacToe::set_winner()
{
    // set winner
    winner = (get_player() == "X") ? "O" : "X";
}

void TicTacToe::clear_board()
{
    // variables
    int i;

    // set all 9 elements to a " " (space)
    for(i=0;i<pegs.size();i++)
    {
        pegs[i] = " ";
    }
}

bool TicTacToe::game_over()
{
    // variables
    bool game_result;

    // initialize variables
    game_result = false;

    // check for row win
    if(check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
    {
        set_winner();
        game_result = true;
    }
    else if(check_board_full() == true)
    {
        winner = "C";
        game_result = true;
    }

    // return
    return game_result;
}

bool TicTacToe::check_column_win()
{
    // return
    return false;
}

bool TicTacToe::check_row_win()
{
    // return
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    // return
    return false;
}

bool TicTacToe::check_board_full()
{
    // variables
    int i;
    bool not_available;

    // initialize variables
    not_available = true;

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<pegs.size();i++)
    {
        if(pegs[i] == " "){ not_available = false; break; }
    }

    // return
    return not_available;
}

// TicTacToe class friends
ostream& operator<<(ostream& out, const TicTacToe& game)
{
    // iterate vector of strings pegs to display a tic tac toe board in 3x3 or 4X4
    // constants
    int const base_col = 3;

    // variables
    int i;
    int ind_sz;
    int space_sz;
    int peg_num;
    int col_num;
    int add_col;
    int base_sz;
    int add_sz;
    int game_board_size;
    string game_title;
    string g_left;
    string g_name;
    string g_row;
    string g_col;
    string g_sp;

    // INITIALIZE VARIABLES
    game_title = "Tic-Tac_Toe";                                         // board display title

    // CHANGEABLE
    ind_sz = 20;                                                        // left indent space
    space_sz = 3;                                                       // space on each side of X and O on the board

    // DO NOT CHANGE
    // get size of peg vector
    peg_num = game.pegs.size();
    col_num = sqrt(peg_num);
    add_col = col_num - base_col;                                       // number of columns to add to base size

    /* GETTING BOARD SIZE:
    BASE SIZE FORMULA: (space_sz * (base_number_of_columns * 2)) + (base_number_of_columns * 2) + 1;
    BOARD EXPANSION FORMULA: (space_sz * (additional_number_of_columns * 2)) + (additional_number_of_columns * 2);
    */
    base_sz = (space_sz * (base_col* 2)) +  (base_col * 2)  +  1;       // base size of 3X3 board; 
    add_sz = (space_sz * (add_col * 2)) +  (add_col * 2);               // each additional expansion
    game_board_size = base_sz + add_sz;                                 // game board size

    // board variables
    g_sp = string(space_sz,' ');
    g_left = string(ind_sz,' ');
    g_name = string((game_board_size - game_title.size())/2,' ');
    g_row = string(game_board_size,'_');
    g_col = "|";

    // BOARD SET-UP
    // game title
    out << "\n" << g_left << g_name << game_title << "\n";

    // add horizontal divider for top of board
    out << g_left << g_row << "\n\n";
    
    // set up first row
    out << g_left;

    // populate board
    for(i=0;i<game.pegs.size();i++)
    {
        // create row
        out << g_col << g_sp << game.pegs[i] << g_sp;
        if( (i+1) % col_num == 0)
        {
            // end row
            out << g_col << "\n";

            // add horizontal divider
            out << g_left << g_row << "\n\n";

            // start new row (if not last row)
            if(i != peg_num-1)
            { 
                out << g_left; 
            }
        }
    }

    // return
    return out;
}

istream& operator>>(istream& in, TicTacToe& game)
{
    // variables
    int position;

    // user interaction
    cout << "\nSelect a position between 1 and " << game.pegs.size() << " : ";
    in >> position;

    // mark position on board
    game.mark_board(position);

    // return
    return in;
}

// Helper functions
void game_menu()
{
    cout << "\nThere are two versions of Tic-Tac-Toe:\n";
	cout << "1) 3 X 3\n";
	cout << "2) 4 X 4\n\n";
	cout << "Which would you like to play? Enter 1 or 2: ";
}
void strToUpper(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = toupper(str[i]);
    }
}

void strToLower(string &str)
{
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}