/*
TUI with NCurses demo.
*/
#include <locale.h>
// #include <ncurses.h>
// We will use ncursesw for wide character support (Unicode)
#include <ncursesw/ncurses.h>
#include "include/util.hpp"

int main()
{
    setlocale(LC_ALL, "");                // This enables UTF-8
    initscr();                            // Start ncurses mode
    move(5, 10);                          // Move cursor to row 5, column 10
    printw("Hello World 🌍 テスト 测试"); // Print to memory; supporting Unicode characters
    refresh();                            // Show it on the real screen
    getch();                              // Wait for user input
    float ans = Demo::add(3.5f, 4.2f);
    move(7, 10);                                                 // Move cursor to row 7, column 10
    printw("3.5 + 4.2 = %.2f", ans);                             // Print the result of addition
    refresh();                                                   // Show it on the real screen
    Demo::print_msg(8, 10, "Welcome to TUI demo with NCurses!"); // Print a message using the utility function
    getch();                                                     // Wait for user input
    Demo::print_msg(9, 10, "Press enter to exit...");            // Print another message
    getch();                                                     // Wait for user input
    endwin();                                                    // End ncurses mode
    return 0;
}