#include <ncurses.h>
#include <array>
#include <string>
#include "../include/tui.hpp"

// Function definitions for TUI namespace
// Draws the menu with the given items and highlights the selected item
void TUI::draw_menu(const std::array<std::string, 4> &items, int selected)
{
    clear(); // Clear the screen before drawing the menu
    mvprintw(1, 2, "TUI Calculator (ncurses)");
    mvprintw(2, 2, "Use UP/DOWN and ENTER.");
    for (int i = 0; i < static_cast<int>(items.size()); ++i)
    {
        if (i == selected)
        {
            // Highlight the selected item
            attron(A_REVERSE);
        }
        // Print the menu item
        mvprintw(4 + i, 4, "%s", items[i].c_str());
        if (i == selected)
        {
            // Turn off highlighting
            attroff(A_REVERSE);
        }
    }
    // Refresh to show the menu
    refresh();
}

// Reads two numbers from the user and stores them in a and b
// Returns true if both numbers were successfully read, false otherwise
bool TUI::read_two_numbers(double &a, double &b)
{
    clear();
    mvprintw(1, 2, "Enter two numbers:");
    mvprintw(3, 2, "a = ");
    echo();
    curs_set(1);
    // Read the first number a
    if (scanw("%lf", &a) != 1)
    {
        noecho();
        curs_set(0);
        return false;
    }

    // FIXME: Implement reading the second number b
    noecho();
    curs_set(0);
    return true;
}

// Displays the result with a label and waits for user input to continue
void TUI::show_result(const char *label, double result)
{
    // FXIME : Implement showing the result in a nice format with given label
    mvprintw(8, 2, "Press any key to continue...");
    refresh();
    getch();
}
