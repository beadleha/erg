#include <stdio.h>
#include <ncurses.h>
#include "util.h"

#define WIDTH 80
#define HEIGHT 24
#define MAXFOES 3

void gen_map(thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			level_map[i][j].type = EMPTY;
			if(0==i)
				level_map[i][j].type = ROCK;
			if(0==j)
				level_map[i][j].type = ROCK;
			if((WIDTH-1)==i)
				level_map[i][j].type = ROCK;
			if((HEIGHT-1)==j)
				level_map[i][j].type = ROCK;
		}
	}
}

int gen_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]){
	level_map[10][10].type = ENEMY;
	level_map[10][10].whichfoe = &enemies[0];
	enemies[0].x=10;
	enemies[0].y=10;
	enemies[0].awake=0;
	enemies[0].health=1;
	// returns num of enemies made
	return 1;
}

// Remember to change whichfoe AND type
// This only updates the map.
// The enemy still needs to be printed
void move_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]){
}

// Prints everything except player
void print_map(WINDOW *menu_win, thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			if (ROCK == level_map[i][j].type){
				print_thing(menu_win, i, j,'*');
			}
		}
	}
	wrefresh(menu_win);
}

// Helper to print a character at a place.
void print_thing(WINDOW *menu_win, int x, int y, char thing){
	char cstr[2];
	cstr[0] = thing;
	cstr[1] = '\0';
	mvprintw(y, x, cstr);
	wrefresh(menu_win);
	wmove(menu_win, y, x);
}

