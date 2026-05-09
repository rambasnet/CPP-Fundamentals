/*
TUI Lab - Text User Interface for basic math operations (Add, Subtract, Multiply) using ncurses library.

Updated By: FIXME
Date: FIXME

Algorithm steps:
1. Initialize ncurses and set up the terminal for TUI.
2. Create a menu with options for Add, Subtract, Multiply, and Exit.
3. Use a loop to display the menu and handle user input for navigation and selection.
4. When an operation is selected, prompt the user to enter two numbers.
5. Perform the selected operation using MyMath functions and display the result.
6. Handle invalid input gracefully and allow the user to return to the menu.
7. Exit the TUI when the user selects "Exit" and clean up ncurses resources.
*/

#include <ncurses.h>
#include <string>
#include <array>
#include <iostream>
#include "../include/tui.hpp"

// FIXME: Add power function to menu and MyMath
const std::array<std::string, 4> menu = {
    "Add",
    "Subtract",
    "Multiply",
    "Exit"};

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    int selected = 0;
    bool running = true;

    while (running)
    {
        TUI::draw_menu(menu, selected);
        int ch = getch();

        switch (ch)
        {
        case KEY_UP:
            selected = (selected - 1 + static_cast<int>(menu.size())) % static_cast<int>(menu.size());
            break;
        case KEY_DOWN:
            // FIXME
            break;
        case '\n':
        case KEY_ENTER:
        {
            if (menu[selected] == "Exit")
            {
                running = false;
                break;
            }

            double a = 0.0;
            double b = 0.0;
            if (!TUI::read_two_numbers(a, b))
            {
                clear();
                mvprintw(2, 2, "Invalid input. Press any key...");
                refresh();
                getch();
                break;
            }

            if (menu[selected] == "Add")
            {
                TUI::show_result("a + b", a + b);
            }
            // FIXME: Implement Subtract and Multiply cases

            break;
        }
        default:
            break;
        }
    }

    endwin();
    return 0;
}