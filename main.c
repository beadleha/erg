#include <stdio.h>
#include <ncurses.h>
#include "util.h"

#define WIDTH 80
#define HEIGHT 24
#define MAXFOES 3

int main(){
	thing_t level_map[WIDTH][HEIGHT];
	enemy_t enemies[MAXFOES];
	player_t me;

	WINDOW *menu_win;
	int c,i;
	int numfoes=0;

	me.x = 1;
	me.y = 1;
	me.health = 3;

	curs_set(0);

	initscr();
	clear();
	noecho();
	cbreak();

	menu_win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(menu_win, TRUE);

	gen_map(level_map); // Generate a level
	numfoes = gen_enemies(level_map, enemies); // Generate enemies
	print_map(menu_win, level_map);
	for(i=0;i<numfoes;i++){
		print_thing(menu_win, enemies[i].x, enemies[i].y,'E');
	}
	print_thing(menu_win, me.x, me.y,'@');
	refresh();
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if((level_map[me.x][me.y-1].type == EMPTY)
					&& (me.y>0)){
					print_thing(menu_win, me.x, me.y,' ');
					me.y--;
				}
				break;
			case KEY_DOWN:
				if((level_map[me.x][me.y+1].type == EMPTY)
					&& (me.y<HEIGHT-1)){
					print_thing(menu_win, me.x, me.y,' ');
					me.y++;
				}
				break;
			case KEY_LEFT:
				if((level_map[me.x-1][me.y].type == EMPTY)
					&& (me.x>0)){
					print_thing(menu_win, me.x, me.y,' ');
					me.x--;
				}
				break;
			case KEY_RIGHT:
				if((level_map[me.x+1][me.y].type == EMPTY)
					&& (me.y<WIDTH)){
					print_thing(menu_win, me.x, me.y,' ');
					me.x++;
				}
				break;
			case 'q':
				clrtoeol();
				refresh();
				endwin();
				return(0);
		}
		for(i=0;i<numfoes;i++){
			print_thing(menu_win, enemies[i].x, enemies[i].y,'E');
		}
		print_thing(menu_win, me.x, me.y,'@');
		refresh();
	}	
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

