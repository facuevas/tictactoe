#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

class TicTacToe
{
    public:
        void display_board(std::vector<char> board);
        void player_move(std::vector<char>& board);
        void computer_move(std::vector<char>& board);
        bool contains_winner(std::vector<char> board);
        bool contains_draw(std::vector<char> board);
        void run();
        TicTacToe();
        ~TicTacToe();
};