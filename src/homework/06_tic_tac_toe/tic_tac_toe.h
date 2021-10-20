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
        void clear_game_data();
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

// other functions
int calc_time(int x);
void display_menu();
void clear_local_data(vector<int> &game_history, vector<string> &all_slots);
void get_game_history(const vector<int> &game_history, const vector<string> &all_slots, int game_count, double tm_elapsed);

// helper functions
void strToUpper(string &str);
void strToLower(string &str);


