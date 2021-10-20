// include
#include "tic_tac_toe.h"
#include <iostream>

// using
using std::cout;

void TicTacToe::start_game(string first_player)
{
    //First player function argument must be X or O
    //In function set player(private variable) to first_player function argument
    player = first_player;

    //Call the clear_the_board function
    clear_board();
}

void TicTacToe::display_board() const
{
    //iterate vector of strings pegs to display a tic tac toe board in 3x3
    // variables
    int i;
    string g_name;
    string g_col;
    string g_row;
    string g_left;
    string g_sp;

    // initialize variables
    g_name = string(19,' ') + "Tic-Tac-Toe\n";
    g_col = "|";
    g_row = string(16,' ') + string(17,'_') + "\n\n";
    g_left = string(15,' ');
    g_sp = string(2,' ');

    // pre-set up
    cout<<"\n";
    cout<<g_name;

    // add divider, start first row
    cout << g_row;
    cout << g_left;

    // populate board
    for(i=0;i<9;i++)
    {
        // row of three
        cout << g_col << g_sp << pegs[i] << g_sp;
        if( (i+1) % 3 == 0)
        {
            // end row, add divider
            cout << g_col << "\n";
            cout << g_row;

            // start new row
            if(i != 8){cout<<g_left;}

        }
    }
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

void TicTacToe::clear_board()
{
    // variables
    int i;

    // set all 9 elements to a " " (space)
    for(i=0;i<9;i++)
    {
        pegs[i] = " ";
    }
}

bool TicTacToe::game_over()
{
    // return check board full function return 
    return check_board_full();
}

bool TicTacToe::check_board_full()
{
    // variables
    int i;
    bool not_available;

    // initialize variables
    not_available = true;

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<9;i++)
    {
        if(pegs[i]== " "){ not_available = false;}
    }

    // return
    return not_available;
}

void TicTacToe::end_game()
{
    //clear game data if game is over
    if(game_over() == true)
    {
        // call clear_board to clear the board
        clear_board();

        // game over
		cout << "\nGame over!\n\n";
    }
}

void GamePlay::update_game_history(string current_player, int position, int turn_count)
{
    // update game history
    position_history[turn_count]=position;
    player_history[position-1]=current_player;
    turn_number=turn_count;
}

void GamePlay::update_games_played(int game_count)
{
    // update games played
    games_played = game_count;
}

void GamePlay::clear_game_history()
{
    // variables
    int i;
    string slot;

    // initialize variables
    slot = " ";
    
    // clear position and player history
    position_history.clear();
    for(i=0;i<9;i++)
    {
        player_history[i] = " ";
    }
}

bool GamePlay::slot_available(int position)
{
    return check_slots(position);
}

bool GamePlay::check_slots(int position)
{
    // variables
    bool available;
    string open_slot;

    // initialized variables
    available = false;
    open_slot = " ";

    cout << player_history[position-1] << "\n";

    if(player_history[position-1] == open_slot)
    {
        available = true;
    }

    // return
    return available;
}

int GamePlay::get_next_move(int position)
{
    // declare class
    TicTacToe game;

    // variables
    int i;
    int move;
    int first_slot;

    // new array
    int * mychoice;
    int choices[][4] = { 
                    {2,4,5},
                    {1,3,5},
                    {2,5,6},
                    {1,5,7},
                    {2,4,6,8},
                    {3,5,9},
                    {4,5,8},
                    {5,7,9},
                    {5,6,8}
                    };

    // assign to variable
    mychoice = choices[position-1];

    // find first unused slot
    for(i=0;i<9;i++)
    {
        first_slot=i+1;
        if(check_slots(first_slot)==true){break;}
    }
    
    // run validation
    for(i=0;i<5;i++)
    {
        move = mychoice[i];
        if(move == 0){move = first_slot;}
        // validate
        if(check_slots(move)==true){break;}
    }

    // return
    return move;
}

void GamePlay::display_game_history(int time_elapsed)
{
    // variables
    int i;
    int ix;
    int iy;
    int game_position;
    double tm_time;
    string game_player;
    string name_space;
    string left_space;
    string player_space;
    string game_space;
    string tm_type;

    // initialized variables
    left_space = string(10,' ');
    name_space = string(16,' ');
    player_space = string(19,' ');
    game_space = string(3,' ');

    // get time math
    tm_time = (time_elapsed >= 60) ? time_elapsed/60 : time_elapsed;
    tm_type = (time_elapsed >= 60) ? " minutes" : " seconds";

    // display header
	cout << "\n\n";
    cout << name_space << "Game History\n\n";
	cout << "Total Games Played: " << games_played << "\n";
    cout << "Total Play Time: " << tm_time << tm_type << "\n\n";
    cout << "Last Game Results: \n\n";
    cout << player_space << "Player" << game_space << "Position" << "\n";

    // iterate through loop for game data
	for(i=0; i<9; i++)
	{
        // game data
        game_position = position_history[i];
        game_player = player_history[game_position-1];

        // output to screen
		cout << left_space << "Turn " << i + 1 << ": " << game_space << game_player << left_space << game_position << "\n";
	}
}

void GamePlay::display_menu()const
{
    // menu
    cout << "\nPick Your Poison\n\n";
    cout << "0 - Automated Game\n";
    cout << "1 - Live Against Computer\n";
    cout << "2 - Live Two Player\n";
    cout << "3 - Quit\n\n";
    cout << "Your choice: ";
}

int * calcTime(int x)
{
    int i;
    int quot_time;
    int rem_time;
    string time;

    // initialize
    i = 0; 
    int auto_positions[] = {60,60,24,7,30,365};
    static int times[7];

    while(quot_time > 1)
    {

        quot_time = x/auto_positions[i];
        rem_time = rem_time % auto_positions[i];
        
        // add to time array
        times[i]=rem_time;

        // increment
    }

    // return
    return times;
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
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}