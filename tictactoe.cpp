#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

void display_board(std::vector<char> board);
void player_move(std::vector<char>& board);
void computer_move(std::vector<char>& board);
bool contains_winner(std::vector<char> board);
bool contains_draw(std::vector<char> board);

int main()
{
    //init random number seed
    srand (time(0));
    //bool to check if game is over
    bool isGameOver = false;
    // init gameboard
    std::vector<char> board(9);
    std::fill_n(board.begin(), 9, '-');

    //display initial board
    display_board(board);

    while (!isGameOver)
    {
        //have player select
        player_move(board);
        
        //have computer select
        computer_move(board);

        //check for win conditons or draw conditons
        
        if (contains_winner(board))
        {
            std::cout << "SOMEONE WON THE GAME";
            isGameOver = true;
        }
        else if (contains_draw(board))
        {
            std::cout << "DRAW GAME";
            isGameOver = true;
        }
        
    }
    std::cout << "\nTEST END";

    return 0;
}

//display board function
void display_board(std::vector<char> board)
{
    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << "      | 0 | 1 | 2 |\n";
    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << "      | 3 | 4 | 5 |\n";
    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << "      | 6 | 7 | 8 |\n\n";
}

//player move function
void player_move(std::vector<char>& board)
{
    bool isMoveValid = false;
    int choice;
    std::cin >> choice;
    //Player will be Xs, computer will be Os
    while (!isMoveValid)
    {
        if (board[choice] == '-' && choice < 9) 
        {
            board[choice] = 'X';
            display_board(board);
            isMoveValid = true;
        } 
        else 
        {
            std::cout << "invalid move. try again\n";
            display_board(board);
            std::cin >> choice;
        }
    }
}

void computer_move(std::vector<char>& board)
{

    bool isMoveValid = false;
    int move = rand() % 9;
    while (!isMoveValid)
    {
        if (board[move] == '-')
        {
            board[move] = 'O';
            display_board(board);
            isMoveValid = true;
        }
        else
        {
            move = rand() % 9;
        }
    }
}

//can probably do this better.
/*
    TODO: contains_winner() function is broken. it will always find a winner because '-' counts.
    Need to explicitly define Xs and Os in a really nice way.
*/
bool contains_winner(std::vector<char> board)
{
    /*
    This is how board looks like:
    | 0 | 1 | 2 |
    | 3 | 4 | 5 |
    | 6 | 7 | 8 |
    */

   //checks top side
   if (board[0] == board[1] && board[0] == board[2] && board[1] == board[2] && board[0] != '-')
    {
        return true;
    }
    //checks left side
    if (board[0] == board[3] && board[0] == board[6] && board[3] == board[6] && board[0] != '-')
    {
        return true;
    }
    //checks right side
    if (board[2] == board[5] && board[2] == board[8] && board[5] == board[8] && board[2] != '-')
    {
        return true;
    }
    //checks bottom side
    if (board[6] == board[7] && board[6] == board[8] && board[7] == board[8] && board[6] != '-')
    {
        return true;
    }
    //checks middle row
    if (board[3] == board[4] && board[3] == board[5] && board[4] == board[5] && board[3] != '-')
    {
        return true;
    }
    //checks middle column
    if (board[1] == board[4] && board[1] == board[7] && board[4] == board[7] && board[1] != '-')
    {
        return true;
    }
    //checks diagonal from top right to bottom left
    if (board[2] == board[4] && board[2] == board[6] && board[4] == board[6] && board[2] != '-')
    {
        return true;
    }
    //checks diagonal from top left to bottom right
    if (board[0] == board[4] && board[0] == board[8] && board[4] == board[8] && board[0] != '-')
    {
        return true;
    }
    //returns false of no win condition
    return false;
}

bool contains_draw(std::vector<char> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == '-')
        {
            return false;
        }
    }
    return true;
}
