#include <ncurses.h>
#define COLOR_ORANGE 8
using namespace std;

int main()
{
    int rows, cols;

    initscr();

    noecho();
    refresh();
    // text color = white, background = black
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    WINDOW *win1 = newwin(5, 76, 1, 2);
    WINDOW *win2 = newwin(15, 46, 6, 18);

    wattron(win1, A_STANDOUT);
    wmove(win1, 2, 22);
    wprintw(win1, "ncurses");
    wattroff(win1, A_STANDOUT);
    wprintw(win1, " Environment Interrogator");
    // Apply color pair to window
    wbkgd(win1, COLOR_PAIR(1));
    box(win1, 0, 0);
    wrefresh(win1);

    const char *colors = has_colors() ? "YES" : "NO";
    wmove(win2, 2, 5);
    wprintw(win2, "%s", "Supports color: ");
    if (colors == "YES")
    {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        wattron(win2, COLOR_PAIR(1));
    };
    wprintw(win2, "%s", colors);
    if (colors == "YES")
    {
        wattroff(win2, COLOR_PAIR(1));
    };

    const char *change_color = can_change_color() ? "YES" : "NO";
    wmove(win2, 4, 5);
    wprintw(win2, "Supports change color: ");
    if (change_color == "YES")
    {
        init_color(COLOR_ORANGE, 1000, 500, 0);
        init_pair(2, COLOR_ORANGE, COLOR_BLACK);
        // Set background color for the window
        wbkgd(win2, COLOR_PAIR(1));
        // Set text color for the window
        wattron(win2, COLOR_PAIR(2));
    };
    wprintw(win2, "%s", change_color);
    if (change_color == "YES")
    {
        wattroff(win2, COLOR_PAIR(2));
    };

    wmove(win2, 6, 5);
    getmaxyx(stdscr, rows, cols);
    wprintw(win2, "%s %d by %d", "Current window size: ", rows, cols);
    wmove(win2, 8, 5);
    getmaxyx(win2, rows, cols);
    wprintw(win2, "Current window size: %d by %d", rows, cols);
    wmove(win2, 10, 5);
    getmaxyx(win1, rows, cols);
    wprintw(win2, "Top window size: %d by %d", rows, cols);
    wmove(win2, 12, 5);
    getbegyx(win2, rows, cols);
    wprintw(win2, "Current window top left pos: %d, %d", rows, cols);

    box(win2, 0, 0);
    wrefresh(win2);

    move(22, 25);
    printw("Enter a character quit: ");
    getch();
    // Clean up
    delwin(win1);
    delwin(win2);
    endwin();

    return 0;
}