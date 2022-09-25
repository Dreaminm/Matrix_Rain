#include "header.h"
#include <ncurses.h>
#include <locale.h>
#include <time.h>

void mx_printstr() {
	srand(time(0));
	
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
    
    char wake_up[14] = "Wake up, Neo..";
    char matrix[20] = "The matrix has you..";
    char follow[23] = "Follow the white rabbit";
    char knock[17] = "Knock, knock, Neo";
 
    for (int i = 0; i < 14; i++)
    {
    	if (getch() == 'q')
    	{
    		endwin();
    		exit(0);
    	}
    	mvaddch(0, i, wake_up[i] | COLOR_PAIR((rand() % 7) + 1));
    	refresh();
    	if (wake_up[i] == ' ')
    	{
    		
    	}
    	else usleep(30000);
    }
    usleep(1000000);
    clear();

    for (int i = 0; i < 20; i++)
    {
    	if (getch() == 'q')
    	{
    		endwin();
    		exit(0);
    	}
   	mvaddch(0, i, matrix[i] | COLOR_PAIR((rand() % 7) + 1));
   	refresh();
   	if (matrix[i] == ' ')
   	{
   		
   	}
   	else usleep(30000);
    }
    usleep(1000000);
    clear();

    for (int i = 0; i < 23; i++)
    {
    	if (getch() == 'q')
    	{
    		endwin();
    		exit(0);
    	}
    	mvaddch(0, i, follow[i] | COLOR_PAIR((rand() % 7) + 1));
    	refresh();
    	if (follow[i] == ' ')
    	{
    		
    	}
    	else usleep(30000);
    }
    usleep(1000000);
    clear();

    for (int i = 0; i < 17; i++)
    {
    	if (getch() == 'q')
    	{
    		endwin();
    		exit(0);
    	}
    	mvaddch(0, i, knock[i] | COLOR_PAIR((rand() % 7) + 1));
    	refresh();
    	if (knock[i] == ' ')
    	{
    		
    	}
    	else usleep(30000);
    }
    usleep(1000000);
    clear();
}
