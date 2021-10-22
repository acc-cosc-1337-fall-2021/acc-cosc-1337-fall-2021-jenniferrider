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
        
    private:
        // variables
        string player;
        vector<string> pegs = vector<string>(9," ");

        // functions
        bool check_board_full();
        void set_next_player();
        void clear_board();
};

class GamePlay
{
    public:
        int get_next_move();
        bool validate_position(int position);
        void display_menu()const;
        void display_turn_info()const;
        void update_turn_history(string current_player, int position, int turn_count);
        void update_game_history(int game_count, int mode);
        void display_game_history(int time_elapsed);
        void clear_game_history();

    private:
        int games_played;
        int turn_number;
        int last_position;
        string last_player;
        bool check_slots(int position);
        vector<string> game_type_history;                           // track game type for each game played: automated, against computer, two player
        vector<int> move_history = vector<int>(9);				    // keeps turn history of single game
    	vector<string> player_history = vector<string>(9," ");		// tracks used slots
        vector< vector<int> > game_history_position;
        vector< vector<string> > game_history_player;
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
