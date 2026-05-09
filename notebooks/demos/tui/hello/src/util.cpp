#include <string>
#include <ncurses.h>
#include "../include/util.hpp"
namespace Demo
{
    float add(float a, float b)
    {
        return a + b;
    }
    void print_msg(int row, int col, std::string message)
    {
        mvprintw(row, col, "%s", message.c_str()); // Move cursor and print message
        refresh();                                 // Update screen
    }
}