#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    const int enter_key = 10;
    int ymax, xmax;
    vector<string> choices = {
        "1st Choice",
        "2nd Choice",
        "3rd Choice",
        "Choose me!",
        "Not me!"};
    int num_choices = choices.size();
    int choice;
    int highlight = 0;

    // Setup
    initscr();
    noecho();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);

    // Create menu window
    WINDOW *menuwin = newwin(num_choices + 4, xmax - 2, ymax - (num_choices + 4), 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    while (true)
    {
        for (int i = 0; i < choices.size(); i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 2, 3, "%s", choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            if (highlight > 0)
                highlight--;
            break;
        case KEY_DOWN:
            if (highlight < choices.size() - 1)
                highlight++;
            break;
        default:
            break;
        }
        if (choice == enter_key)
            break;
    }

    move(2, 3);
    printw("You chose: %s", choices[highlight].c_str());
    getch();
    endwin();

    return 0;
}