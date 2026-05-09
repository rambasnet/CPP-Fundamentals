#include <ncurses.h>
#include <array>
#include <string>

namespace TUI
{
    void draw_menu(const std::array<std::string, 4> &items, int selected);
    bool read_two_numbers(double &a, double &b);
    void show_result(const char *label, double result);
}