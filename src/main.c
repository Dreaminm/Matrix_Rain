#include "header.h"
#include <ncurses.h>
#include <locale.h>
#include <time.h>
int main()
{
    int row, col;
    srand(time(0));
    initscr();
    nonl();
    curs_set(0);
    if (has_colors()) {
        start_color();
        init_color(COLOR_BLACK, COLOR_GREEN, COLOR_WHITE, 0);
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_YELLOW, COLOR_BLACK);
        
    }
    
    getmaxyx(stdscr, row, col);
    halfdelay(1);
    mx_printstr();

    while (getch() != 'q') {
        for (int b = row - 1; b > 0; b--) {
            for (int a = 0; a < col; a++) {
                int c = mvinch(b - 1, a) / 256;
                if(mvinch(b - 1, a) % 256 == ' ') {
                    mvaddch(b, a, ' ' | COLOR_PAIR(2));
                }
                else if (mvinch(b - 1, a) / 256 == 1) {
                    mvaddch(b, a, (rand() % 93 + 33) | COLOR_PAIR(1));
                }
                else if (mvinch(b, a) / 256 == 1) {
                    mvaddch(b, a, mvinch(b, a) % 256 | COLOR_PAIR(c));
                }
            }
        }
        for (int a = 0; a < col; a++) {
            move(0, a);
            if (mvinch(0, a) / 256 == 1) {
                mvaddch(0, a, (mvinch(0, a) % 256) | ((rand() % 6 + 2) * 256));             // !!!
            }
            else if(mvinch(0, a) % 256 == ' ') {
                if (rand() % 40 == 0) {
                    if (a == 0) {
                        if(mvinch(0, a + 1) % 256 == ' ') {
                            mvaddch(0, a, (rand() % 93 + 33) | COLOR_PAIR(1));
                        }
                    }
                    else if (a == col - 1) {
                        if(mvinch(0, a - 1) % 256 == ' ') {
                            mvaddch(0, a, (rand() % 93 + 33) | COLOR_PAIR(1));
                        }
                    }
                    else if (mvinch(0, a - 1) % 256 == ' ' && mvinch(0, a + 1) % 256 == ' ') {
                        mvaddch(0, a, (rand() % 93 + 33) | COLOR_PAIR(1));
                    }
                }
            }
            else {
                if(rand() % 10 == 0) {
                    mvaddch(0, a, ' ' | COLOR_PAIR(2));
                }
            }
        }
        refresh();
    }   
    endwin();
    return 0;
}


