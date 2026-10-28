#include <iostream>
#include <tuple>
#include <limits>
#include "../includes/tictactoe.hpp"

void tictactoe::init_board(char board[][3])
{
    for (unsigned short i = 0; i < ROWS; ++i)
    {
        for (unsigned short j = 0; j < COLS; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void tictactoe::display_board(char board[][3])
{
    for (short i = 0; i < ROWS; i++)
    {
        for (short j = 0; j < COLS; ++j)
        {
            std::cout << board[i][j];
            if (j < COLS - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < ROWS - 1)
            std::cout << "--+---+--" << std::endl;
    }
}

bool tictactoe::place_mark(char board[][3], size_t row, size_t col, const char mark)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = mark;
        return true;
    }
    return false;
}

bool tictactoe::check_winner(char board[][3], const char mark)
{
    // Check ROWS
    for (unsigned short i = 0; i < ROWS; ++i)
    {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return true;
    }
    // Check columns
    for (unsigned short j = 0; j < COLS; ++j)
    {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
            return true;
    }
    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return true;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return true;

    return false;
}

// Simple computer move: place mark in the first available spot
bool tictactoe::computer_move(char board[][3], const char mark)
{
    for (unsigned short i = 0; i < ROWS; ++i)
    {
        for (unsigned short j = 0; j < COLS; ++j)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = mark;
                return true;
            }
        }
    }
    return false;
}

void tictactoe::switch_player(char &current_player)
{
    current_player = (current_player == 'X') ? 'O' : 'X';
}

void tictactoe::clear_board(char board[][3])
{
    for (unsigned short i = 0; i < ROWS; ++i)
    {
        for (unsigned short j = 0; j < COLS; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

unsigned short tictactoe::get_menu_option()
{
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "1. Two-Player Game" << std::endl;
    std::cout << "2. Single-Player Game (vs Computer)" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Please select an option: [1-3] ";
    unsigned short option;
    std::cin >> option;
    return option;
}

std::tuple<unsigned short, unsigned short> tictactoe::get_player_move(char current_player)
{
    unsigned short row, col;
    std::cout << "Player " << current_player << ", enter your move row: [1-3] and column: [1-3] separated by a space: ";
    while (true)
    {
        std::cin >> row >> col;
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3)
        {
            return std::make_tuple(row - 1, col - 1); // Convert to 0-based index
        }
        else
        {
            if (std::cin.fail())
            {
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            std::cout << "Invalid input. Please enter row and column numbers between 1 and 3 separated by a space: ";
        }
    }
    return std::make_tuple(row, col);
}

bool tictactoe::check_draw(char board[][3])
{
    for (unsigned short i = 0; i < ROWS; ++i)
    {
        for (unsigned short j = 0; j < COLS; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false; // Found an empty space, not a draw
            }
        }
    }
    return true; // No empty spaces, it's a draw
}

void tictactoe::two_player_game_loop(char board[][3])
{
    char current_player = 'X';
    bool game_over = false;
    unsigned short row, col = 0;
    std::tuple<unsigned short, unsigned short> move;

    while (!game_over)
    {
        CLEAR_SCREEN;
        tictactoe::display_board(board);
        move = tictactoe::get_player_move(current_player);
        row = std::get<0>(move);
        col = std::get<1>(move);
        if (place_mark(board, row, col, current_player))
        {
            display_board(board);
            if (check_winner(board, current_player))
            {
                std::cout << "Player " << current_player << " wins!" << std::endl;
                game_over = true;
            }
            else if (tictactoe::check_draw(board))
            {
                std::cout << "It's a draw!" << std::endl;
                game_over = true;
            }
            else
            {
                switch_player(current_player);
            }
        }
        else
        {
            std::cout << "Invalid move. Try again. Enter to continue..." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            std::cin.get();                                                     // Wait for user to press Enter
        }
    }
}

// FIXME: Implement single-player game loop against computer
void tictactoe::single_player_game_loop(char board[][3])
{
}
