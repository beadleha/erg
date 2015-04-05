#include <stdio.h>
#include <ncurses.h>
#include "drawutil.h"
#include "enemies.h"
#include "level.h"

#define WIDTH 80
#define HEIGHT 24

// Prints everything except player
void print_map(WINDOW *erg_win, thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			if (ROCK == level_map[i][j].type){
				print_thing(erg_win, i, j,'*');
			}
		}
	}
	wrefresh(erg_win);
}

// Helper to print a character at a place.
void print_thing(WINDOW *erg_win, int x, int y, char thing){
	char cstr[2];
	cstr[0] = thing;
	cstr[1] = '\0';
	mvprintw(y, x, cstr);
	wrefresh(erg_win);
	wmove(erg_win, y, x);
}

void print_beings(WINDOW *erg_win, player_t me, enemy_t * enemies, int numfoes){
	int i;
	// Print Enemies
	attron(COLOR_PAIR(2));
	for(i=0;i<numfoes;i++){
		print_thing(erg_win, enemies[i].x, enemies[i].y,'E');
	}

	// Print Player
	attron(COLOR_PAIR(3));
	print_thing(erg_win, me.x, me.y,'@');
	attron(COLOR_PAIR(1));

	refresh();
}

int init_colors(){
	// Initialize Colors
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		return(1);
	}
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	return 0;
}

