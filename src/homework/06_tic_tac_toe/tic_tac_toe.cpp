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
    //cout << "Mark Board Function\n";
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
    //cout << "Game Over Function\n";
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
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    // options: 0, 3, 6; 1, 4, 7; 2, 5, 8
    if(pegs[0]==last_player && pegs[3] == last_player && pegs[6] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[1]==last_player && pegs[4] == last_player && pegs[7] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[2]==last_player && pegs[5] == last_player && pegs[8] == last_player)
    {
        //true
        you_win = true;
    }

    // return
    return you_win;
}

bool TicTacToe::check_row_win()
{
    //cout << "Check Row Function\n";
    // variables
    bool you_win;
    string last_player;

    // initialized variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //Options: 0, 1, 2; 3, 4, 5; 6, 7, 8
    if(pegs[0]==last_player && pegs[1] == last_player && pegs[2] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[3]==last_player && pegs[4] == last_player && pegs[5] == last_player)
    {
        //true
        you_win = true;
    }
    else if(pegs[6]==last_player && pegs[7] == last_player && pegs[8] == last_player)
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
    string last_player;

    //initialize variables
    you_win = false;
    last_player = (get_player() == "X") ? "O" : "X";

    //0, 4, 8; 2, 4, 6;
    if(pegs[0] == last_player && pegs[4] == last_player && pegs[8] == last_player)
    {
        // true
        you_win = true;
    }
    else if(pegs[2] == last_player && pegs[4] == last_player && pegs[6] == last_player)
    {
        //true
        you_win = true;
    }
    else
    { 
        you_win = false;
    }

    // return
    return you_win;
}

bool TicTacToe::check_board_full()
{
    //cout << "Check Board Function\n";

    // variables
    int i;
    bool not_available;

    // initialize variables
    not_available = true;

    // return false if vector of strings pegs has available slot by checking for a " " (space) in each element. Otherwise return true
    for(i=0;i<9;i++)
    {
        if(pegs[i]== " "){ not_available = false; }
    }

    // return
    return not_available;
}

string TicTacToe::get_winner()
{
    return winner;
}

void TicTacToe::set_winner()
{
    // set winner
    winner = (get_player() == "X") ? "O" : "X";
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

void GamePlay::update_game_history(int game_count, int mode,string game_winner)
{
    // variables
    string game_type;

    //initialize variables
    vector<int> position_history(9);

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

    // change winner history
    game_winner=(game_winner == "C")?"Tie":game_winner;

    // update game history vectors
    game_type_history.push_back(game_type);
    game_winner_history.push_back(game_winner);
    game_history_player.push_back(player_history);
    game_history_position.push_back(move_history);
  
    // games played
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
        move_history[i] = 0;
        player_history[i] = " ";
    }
    cout << "Player history cleared\n";
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
    int iy;
    int move;
    int turn;
    int first_slot;
    string current_player;

    // initialized variables
    current_player = last_player;
    cout << "Curent player: " << current_player << "\n";

    // new array
    int * mychoice;
    int choices[][8] = { 
                    {5,2,4},
                    {5,1,3,8},
                    {5,2,6,7},
                    {5,1,7,6},
                    {1,9,2,8,3,7,4,6},
                    {5,3,9,4},
                    {5,4,8,3},
                    {5,7,9,2},
                    {5,8,6}
                    };
    // assign correct array to variable
    mychoice = choices[last_position-1];

    // get first slot
    for(ix=0;ix<9;ix++)
    {
        if(check_slots(ix+1)==true)
        {
            first_slot = ix+1;
        }
    }

    // run validation
    for(i=0;i<8;i++)
    {
        move = mychoice[i];
        if(move == 0)
        {
            // find first unused slot
            move = first_slot;
            break;
        }
        else
        {
            // validate
            if(check_slots(move)==true)
            {
                break;
            }
            else
            {
                if(check_player(current_player,move)==true)
                {
                    if(turn_number == 3 || turn_number == 5 || turn_number == 7)
                    {
                        // go to the next in list
                        i=i+2;
                    }
                }
            }
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

bool GamePlay::check_player(string current_player, int position)
{
    // variables
    bool is_player;

    // initialized variables
    is_player = false;

    if(player_history[position-1] == current_player)
    {
        is_player = true;
    }

    // return
    return is_player;
}

void GamePlay::display_game_history(int time_elapsed)
{
    // constants
    int const turn_ind = 7;

    // variables
    int i;
    int ix;
    int game_ind;
    int table_ind;
    int title_ind;
    int pla_ind;
    int pos_ind;
    int game_space;
    int table_space;
    int screen_space;
    int top_ln;
    int table_top_ln;
    int game_position;
    double tm_time;

    // string names
    string header_title;
    string header_row_pla;
    string header_row_pos;

    // string space
    string table_indent_sp;
    string hplayer_sp;
    string hpos_sp;
    string header_indent_sp;
    string line_indent_sp;
    string title_indent_sp;
    string table_sp;
    string table_header_sp;
    string game_sp;
    string screen_sp;
    string pla_sp1;
    string pla_sp2;
    string pos_sp1;
    string pos_sp2;
    string tm_type;
    string game_player;

    // underlining
    string top_line_sp;
    string table_line_sp;

    // game size: game_space
    // table size: table_space

    // header text
    header_title = "Game History";
    header_row_pla = "Player";
    header_row_pos = "Position";

    // size of left indent for table, left indent of player and postion on header row
    // these are changeable
    game_ind = 2;
    table_ind = 10;
    pla_ind = 3;
    pos_ind = 4;

    // lengths in game
    table_space = turn_ind + pla_ind + pos_ind + header_row_pla.size() + header_row_pos.size();
    screen_space = game_ind + table_ind + table_space;
    game_space = screen_space - game_ind;

    // game history title indent
    title_ind = (table_space - header_title.size()) / 2;

    // top line underlining space
    top_ln = table_space + (table_ind * 2);
    table_top_ln = table_space + 4;

    // base indents
    header_indent_sp = string(game_ind,' ');
    table_indent_sp = header_indent_sp + string(table_ind,' ');
    line_indent_sp = string(table_ind,' ');

    // specific indents
    title_indent_sp = table_indent_sp + string(title_ind,' ');
    table_header_sp = table_indent_sp + string(turn_ind,' ');
    hplayer_sp = string(pla_ind,' ');
    hpos_sp = string(pos_ind,' ');

    // constants: spaces on either side of player name (X or O) to keep centered with Player header
    pla_sp1 = hplayer_sp + string((header_row_pla.size()) / 2 - 1,' ');
    pla_sp2 = string((header_row_pla.size()) / 2,' ');

    // constants: spaces on left side of position number to keep centered with Position header
    pos_sp1 = hpos_sp + string((header_row_pos.size()) / 2 - 1,' ');
    pos_sp2 = string((header_row_pos.size()) / 2,' ');

    // decorative underlining
    top_line_sp = header_indent_sp + string(top_ln,'_');
    table_line_sp = line_indent_sp + string(table_top_ln,'_');

    // underlines for sizing and testing
    table_sp = string(table_space,'_');
    screen_sp = string(screen_space, '_');
    game_sp = string(game_space,'_');

    // get time math
    tm_time = (time_elapsed >= 60) ? time_elapsed/60 : time_elapsed;
    tm_type = (time_elapsed >= 60) ? " minutes" : " seconds";

    // display header
	cout << "\n\n";
    cout << top_line_sp << "\n\n";
    cout << title_indent_sp << header_title << "\n\n";
	cout << header_indent_sp << "Games Played: " << games_played << "\n";
    cout << header_indent_sp << "Play Time: " << tm_time << tm_type << "\n\n";
    cout << header_indent_sp << "Game Results\n\n";

    // iterate through loop for each round
    for(i=0;i<games_played;i++)
    {
        // game play table header
        cout << table_line_sp << "\n\n";
        cout << table_indent_sp << "Game " << i + 1 << "\n";
        cout << table_indent_sp << "Type: " << game_type_history[i] << "\n";
        cout << table_indent_sp << "Winner: " << game_winner_history[i] << "\n\n";
        //cout << game_space_test << "\n";

        // table row header
        cout << table_header_sp;
        cout << hplayer_sp << header_row_pla;
        cout << hpos_sp << header_row_pos << "\n";

        // iterate through loop for game data for table
        for(ix=0; ix<game_history_player[i].size(); ix++)
        {
            // get game position
            game_position = game_history_position[i][ix];
            if(game_position > 0)
            {
                // get player name
                game_player = game_history_player[i][game_position-1];

                // output to screen
                cout << table_indent_sp << "Turn " << ix + 1 << ":";
                cout << pla_sp1 << game_player << pla_sp2;
                cout << pos_sp1 << game_position << pos_sp2 << "\n";
            }
            else
            {
                // break if position is zero which indicates no moves left
                break;
            }
        }
    }
    cout << "\n";
    cout << top_line_sp << "\n\n";
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