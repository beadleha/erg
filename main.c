#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"
#include "enemies.h"
#include "level.h"
#include "player.h"



int attack(player_t *player,enemy_t *enemy){
	 if(rand()%2==0){
		 player_health(player,enemy->damage);
	 }else{
		 enemy_health(enemy,player->damage);
	 }
	 if(player->health==0){
		return -1;
	 }else if(enemy->health==0){
		return 1;
	 }else{
		return 0;
	 }

}

void update_attack(thing_t *tile,player_t *player,enemy_t *enemy,int *numfoes){
	if(attack(player,enemy)==-1){
		mvprintw(25, 1, "YOU ARE DEAD");		
	}else if(attack(player,enemy)==1){
		mvprintw(25, 1, "ENEMY IS DEAD");
		tile->type=EMPTY;
		*numfoes--;
	}else{
		 mvprintw(25, 1, "NOBODY DIED Enemy %d Player %d",enemy->health,player->health);
	}
}

int main(){
	thing_t level_map[WIDTH][HEIGHT];
	enemy_t enemies[MAXFOES];
	player_t me;

	WINDOW *erg_win;
	int c;
	int numfoes=0;

	me.x = 1;
	me.y = 1;
	me.health = 3;

	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0); // Hides cursor

	init_colors();

	// ncurses setup stuff
	erg_win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(erg_win, TRUE);

	gen_map(level_map); // Generate a level
	numfoes = gen_enemies(level_map, enemies); // Generate enemies
	print_map(erg_win, level_map);

	mvprintw(24, 1, "Press q to quit"); // This needs a refresh() before it displays
	print_beings(erg_win, me, enemies, numfoes);
	int num;
	while(1){	
		c = wgetch(erg_win);
		srand(time(NULL));
		switch(c)
		{	case KEY_UP:
				if(me.y>0){
					if(level_map[me.x][me.y-1].type == ENEMY){
						update_attack(&level_map[me.x][me.y-1],&me,level_map[me.x][me.y-1].whichfoe,&numfoes);
						//attack(&me,level_map[me.x][me.y-1].whichfoe);
					}
					if(level_map[me.x][me.y-1].type == EMPTY){
						print_thing(erg_win, me.x, me.y,' ');
						me.y--;
					}
				}
				break;
			case KEY_DOWN:
				if(me.y<HEIGHT-1){
					if(level_map[me.x][me.y+1].type == ENEMY){
						 attack(&me,level_map[me.x][me.y+1].whichfoe);
					}
					if((level_map[me.x][me.y+1].type == EMPTY)){
						print_thing(erg_win, me.x, me.y,' ');
						me.y++;
					}
				}
				break;
			case KEY_LEFT:
				if(me.x>0){
					if(level_map[me.x-1][me.y].type == ENEMY){
						 attack(&me,level_map[me.x-1][me.y].whichfoe);
					}
					if((level_map[me.x-1][me.y].type == EMPTY)){
						print_thing(erg_win, me.x, me.y,' ');
						me.x--;
					}
				}
				break;
			case KEY_RIGHT:
				if(me.y<WIDTH){
					if(level_map[me.x+1][me.y].type == ENEMY){
						 attack(&me,level_map[me.x+1][me.y].whichfoe);
					}
					if((level_map[me.x+1][me.y].type == EMPTY) && (me.y<WIDTH)){
						print_thing(erg_win, me.x, me.y,' ');
						me.x++;
					}
				}
				break;
			case 'q':
				clrtoeol();
				refresh();
				endwin();
				return(0);
		}
		// Enemies move
		move_enemies(erg_win, level_map, enemies, numfoes);
		//Print player and enemies
		print_beings(erg_win, me, enemies, numfoes);
	}	
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

