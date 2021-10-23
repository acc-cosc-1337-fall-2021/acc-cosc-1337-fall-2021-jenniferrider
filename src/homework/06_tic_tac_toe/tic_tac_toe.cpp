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
    g_name = string(7,' ') + "Tic-Tac-Toe\n";
    g_col = "|";
    g_row = string(25,'_') + "\n\n";
    g_left = string(20,' ');
    g_sp = string(3,' ');

    // pre-set up
    cout << "\n";
    cout << g_left << g_name;

    // add divider, start first row
    cout << g_left << g_row;
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
            cout << g_left << g_row;

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
    // check if board is full
    check_board_full();

    // check for column win


    // check for row win


    // check for diagnoal win


    return check_board_full();
}

bool TicTacToe::check_column_win()
{
    // variables
    int i;
    bool you_win;
    string player_move;

    // initialized variables
    you_win = false;
    string players[2]={"X","O"};

    for(i=0;i<2;i++)
    {
        player_move = players[i];
    }
    // 0, 3, 6; 1, 4, 7; 2, 5, 8
    if(pegs[0]=="X" && pegs[3] == "X" && pegs[6] == "X")
    {
        // true
        you_win = true;
    }
    else if(pegs[1]=="X" && pegs[4] == "X" && pegs[7] == "X")
    {
        //true
        you_win = true;
    }
    else if(pegs[2]=="X" && pegs[5] == "X" && pegs[8] == "X")
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe::check_row_win()
{
    // variables
    bool you_win;

    // initialized variables
    you_win = false;

    //0, 1, 2; 3, 4, 5; 6, 7, 8
    if(pegs[0]=="X" && pegs[1] == "X" && pegs[2] == "X")
    {
        // true
        you_win = true;
    }
    else if(pegs[3]=="X" && pegs[4] == "X" && pegs[5] == "X")
    {
        //true
        you_win = true;
    }
    else if(pegs[6]=="X" && pegs[7] == "X" && pegs[8] == "X")
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe::check_diagonal_win()
{
    // variables
    bool you_win;

    // initialized variables
    you_win = false;

    //0, 4, 8; 2, 4, 6;
    if(pegs[0]=="X" && pegs[4] == "X" && pegs[8] == "X")
    {
        // true
        you_win = true;
    }
    else if(pegs[2]=="X" && pegs[4] == "X" && pegs[6] == "X")
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
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

void GamePlay::update_turn_history(string current_player, int position, int turn_count)
{
    // update game history
    player_history[position-1]=current_player;
    move_history[turn_count]=position;
    turn_number = turn_count + 1;
    last_position = position;
    last_player = current_player;
}

void GamePlay::display_turn_info()const
{
	// display turn data
    cout << "\nLast Turn\n";
	cout << "Turn: " << turn_number << "\n";
	cout << "Player: " << last_player<< "\n";
	cout << "Last Move: " << last_position << "\n\n";
}

void GamePlay::update_game_history(int game_count, int mode)
{
    // variables
    string game_type;

    // get game type
    if(mode == 0)
    {
        game_type = "Automated";
    }
    else if(mode == 1)
    {
        game_type = "Player Against Computer";
    }
    else
    {
        game_type = "Two Player";
    }

    // update game history vectors
    game_type_history.push_back(game_type);
    game_history_player.push_back(player_history);
    game_history_position.push_back(move_history);
    games_played = game_count+1;
}

void GamePlay::clear_game_history()
{
    // variables
    int i;
    string slot;

    // initialize variables
    slot = " ";
    
    // clear position and player history
    for(i=0;i<9;i++)
    {
        player_history[i] = " ";
    }
}

bool GamePlay::validate_position(int position)
{
    // variables
    bool valid_position;

    // initialize variables
    valid_position = false;

	// validate slot is valid
    if(position == 12345)
    {
        cout<<"\nThat was not a number. Try again\n";
    }
	else if(position < 1 || position > 9)
	{
		cout<<"\nThat is not a valid position. Try again.\n";
	}
	else
	{
		if(check_slots(position) == false)
		{
			cout << "\nThat position is filled. Try again.\n";
		}
        else
        {
            valid_position = true;
        }
    }

    // return
    return valid_position;
}

int GamePlay::get_next_move()
{
    // declare class
    TicTacToe game;

    // variables
    int i;
    int ix;
    int position;
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

    // assign correct array to variable
    mychoice = choices[last_position-1];
    
    // run validation
    for(i=0;i<5;i++)
    {
        move = mychoice[i];
        if(move == 0)
        {
            // find first unused slot
            for(ix=0;ix<9;ix++)
            {
                // validate each slot
                if(check_slots(i+1)==true)
                {
                    move = i + 1;
                    break;
                }
            }
            break;
        }
        else
        {
            // validate
            if(check_slots(move)==true){break;}
        }
    }

    // return
    return move;
}

bool GamePlay::check_slots(int position)
{
    // variables
    bool available;

    // initialized variables
    available = false;

    if(player_history[position-1] == " ")
    {
        available = true;
    }

    // return
    return available;
}

void GamePlay::display_game_history(int time_elapsed)
{
    // variables
    int i;
    int ix;
    int ind;
    int hpla;
    int hpos;
    int game_length;
    int name_length;
    int game_position;
    double tm_time;
    string game_player;
    string left_space;
    string na_space;
    string turn_sp;
    string hplayer_sp;
    string hpos_sp;
    string pla_sp1;
    string pla_sp2;
    string pos_sp1;
    string pos_sp2;
    string tm_type;
    string pos_test;

    // structural
    ind = 12;
    left_space = string(ind,' ');
    turn_sp = string(7,' ');

    // headers - distance from turn space
    hpla = 3;
    hpos = 4;
    hplayer_sp = string(hpla,' ');
    hpos_sp = string(hpos,' ');

    // total length of game
    game_length = ind + 7 + hpla + 6 + hpos + 8;

    // indent name
    name_length = ((game_length - ind) - 12) / 2;
    na_space = string(name_length,' ');

    // constants: spaces on either side of player name to keep centered with Player header
    pla_sp1 = hplayer_sp + string(2,' ');
    pla_sp2 = string(3,' ');

    // constants: spaces on left side of position number to keep centered with Position header
    pos_sp1 = hpos_sp + string(3,' ');
    pos_sp2 = string(4,' ');

    // test
    pos_test = string(game_length,'_');

    // get time math
    tm_time = (time_elapsed >= 60) ? time_elapsed/60 : time_elapsed;
    tm_type = (time_elapsed >= 60) ? " minutes" : " seconds";

    // display header
	cout << "\n\n";
    cout << left_space << na_space << "Game History\n\n";
	cout << "Games Played: " << games_played << "\n";
    cout << "Play Time: " << tm_time << tm_type << "\n\n";
    cout << "Game Results:\n";

    // iterate through loop for each round
    for(i=0;i<games_played;i++)
    {
        cout << "\n";
        cout << left_space << "Game: " << i + 1 << "\n";
        cout << left_space << "Type: " << game_type_history[i] << "\n\n";
        //cout << pos_test << "\n";
        cout << left_space << turn_sp << hplayer_sp << "Player" << hpos_sp << "Position" << "\n";

        // iterate through loop for game data
        for(ix=0; ix<9; ix++)
        {
            // game data
            game_position = game_history_position[i][ix];
            game_player = game_history_player[i][game_position-1];

            // output to screen
            cout << left_space << "Turn " << ix + 1 << ":";
            cout << pla_sp1 << game_player << pla_sp2;
            cout << pos_sp1 << game_position << pos_sp2 << "\n";
        }
    }
}

void StringExtension::strToUpper(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = toupper(str[i]);
    }
}

void StringExtension::strToLower(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i] = tolower(str[i]);
    }
}

void StringExtension::strFirstLetter(string &str)
{
    // variables
    int i;

    // change to uppercase
    for(i=0;i<str.length();i++)
    {
        str[i]=(i==0)?str[i]=toupper(str[i]):str[i]=tolower(str[i]);
    }
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