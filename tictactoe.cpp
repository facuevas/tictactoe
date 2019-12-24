#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

void display_board(std::vector<char>& board);
bool player_move(std::vector<char>& board, int choice);

int main()
{
    bool isGameOver = false;
    bool didPlayerMove = false;
    // init gameboard
    std::vector<char> board(9);
    std::fill_n(board.begin(), 9, '-');

    //display board
    display_board(board);

    //player move
    int choice;
    std::cout << "Select move: ";
    std::cin >> choice;
    while (!didPlayerMove)
    {
        didPlayerMove = player_move(board, choice);
    }

    display_board(board);

    std::cout << "Hello World!";
    return 0;
}

//display board function
void display_board(std::vector<char>& board)
{
    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |\n";
    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |\n";
    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |\n\n";
    std::cout << "Move set:\n";
    std::cout << "| 0 | 1 | 2 |\n";
    std::cout << "| 3 | 4 | 5 |\n";
    std::cout << "| 6 | 7 | 8 |\n";
}

//player move function
bool player_move(std::vector<char>& board, int choice)
{
    //Player will be Xs, computer will be Os
    if (board[choice] == '-') 
    {
        board[choice] = 'X';
        return true;
    } else {
        std::cout << "invalid move";
        return false;
    }
}
