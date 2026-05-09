#include <ncurses.h>
using namespace std;

int main()
{
    char ch;

    initscr();
    // noecho();
    move(9, 25);
    printw("Enter a character or '!' to quit: ");
    refresh();
    ch = getch();

    while (ch != '!')
    {
        clear();
        mvprintw(9, 25, "Enter a character or '!' to quit: ");
        mvprintw(
            12, 18,
            "You entered '%c', which has a numeric value of %d.",
            ch, ch);
        move(9, 59);
        refresh();
        ch = getch();
    }
    endwin();

    return 0;
}