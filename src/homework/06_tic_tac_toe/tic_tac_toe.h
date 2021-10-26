// include
#include<string>
#include<vector>

//using
using std::string; using std::vector;

// class interface code
class TicTacToe
{
    public:
        bool game_over();
        void end_game();
        void start_game(string first_player);
        void mark_board(int position);
        void display_board()const;
        string get_player()const;
        string get_winner();
        
    private:
        // variables
        string player;
        string winner;
        vector<string> pegs = vector<string>(9," ");

        // functions
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        bool check_board_full();
        void clear_board();
        void set_next_player();
        void set_winner();
};

class GamePlay
{
    public:
        int get_next_move();
        int * calcTime(int x);
        bool validate_position(int position);
        void display_menu()const;
        void display_turn_info()const;
        void display_winner(string game_winner);
        void update_current_game(string current_player, int position, int turn_count);
        void update_game_history(int game_count, int mode, string game_winner);
        void display_game_history(int time_elapsed);
        void clear_game_history();

    private:
        // variables
        int last_position;
        int turn_number;
        int games_played;
        string last_player;
        vector<int> game_moves = vector<int>(9);				    // tracks positions
    	vector<string> player_moves = vector<string>(9," ");		// tracks used slots
        vector<string> game_type_history;                           // track game type for each game played: automated, against computer, two player
        vector<string> game_winner_history;                         // track winner for each game played
        vector< vector<int> > game_position_history;                // tracks position history of all games
        vector< vector<string> > game_player_history;               // tracks player history of all games

        // functions
        bool check_slots(int position);
        bool check_player(int position, string current_player);
};

class StringExtension
{
    public:
        void strToUpper(string &str);
        void strToLower(string &str);
        void strFirstLetter(string &str);
};

// other functions
int calc_time(int x);
