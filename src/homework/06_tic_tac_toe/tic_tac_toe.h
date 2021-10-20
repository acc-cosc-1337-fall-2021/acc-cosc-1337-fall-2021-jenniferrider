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
        int get_next_move(int position);
        bool slot_available(int position);
        void update_game_history(string current_player, int position, int turn_count);
        void update_games_played(int game_count);
        void display_game_history(int time_elapsed);
        void clear_game_history();
        void display_menu()const;

    private:
        int games_played;
        int turn_number;
        bool check_slots(int position);
    	vector<string> player_history = vector<string>(9," ");		// tracks used slots
	    vector<int> position_history = vector<int>(9);				// keeps turn history of single game
};

// other functions
int calc_time(int x);

// helper functions
void strToUpper(string &str);
void strToLower(string &str);


