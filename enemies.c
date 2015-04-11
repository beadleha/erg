#include <stdio.h>
#include <time.h>
#include "print.h"
#include "enemies.h"




int gen_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]){
	int i;
	int count = 1+ (rand() % (MAXFOES-1));

	for(i=0;i<count;i++){

bad:
		enemies[i].x = (rand()%WIDTH);
		enemies[i].y = (rand()%HEIGHT);

		if(level_map[enemies[i].x][enemies[i].y].type !=EMPTY) goto bad;

		level_map[enemies[i].x][enemies[i].y].type = ENEMY;
		level_map[enemies[i].x][enemies[i].y].whichfoe = &enemies[i];
		enemies[i].awake=0;
		enemies[i].health=1;
		enemies[i].damage=1;
	}
	// returns num of enemies made
	return count;
}

void change_tile(WINDOW *erg_win,thing_t *oldtile,thing_t *newtile,enemy_t *enemy){
	oldtile->type=EMPTY;
	oldtile->whichfoe=NULL;
	newtile->type=ENEMY;
	newtile->whichfoe=enemy;
	print_thing(erg_win, enemy->x, enemy->y, ' ');
}


// This only updates the map, the enemy still needs to be printed
void move_enemies(WINDOW *erg_win,player_t player,thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES], int numfoes){
	int i;
	for(i=0;i<numfoes;i++){
		if(player.x>enemies[i].x && level_map[enemies[i].x+1][enemies[i].y].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x+1][enemies[i].y],&enemies[i]);
			enemies[i].x++;
		}else if(player.y > enemies[i].y && level_map[enemies[i].x][enemies[i].y+1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x][enemies[i].y+1],&enemies[i]);
			enemies[i].y++;
		}else if(player.x < enemies[i].x && level_map[enemies[i].x-1][enemies[i].y].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x-1][enemies[i].y],&enemies[i]);
			enemies[i].x--;
		}else if(player.y < enemies[i].y && level_map[enemies[i].x][enemies[i].y-1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x][enemies[i].y-1],&enemies[i]);
			enemies[i].y--;
		}/*else if(player.y < enemies[i].y && player.x < enemies[i].x && level_map[enemies[i].x-1][enemies[i].y-1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x-1][enemies[i].y-1],&enemies[i]);
			enemies[i].y--;
			enemies[i].x--;
		}else if(player.y < enemies[i].y && player.x > enemies[i].x && level_map[enemies[i].x+1][enemies[i].y-1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x+1][enemies[i].y-1],&enemies[i]);
			enemies[i].y--;
			enemies[i].x++;
		}else if(player.y > enemies[i].y && player.x < enemies[i].x && level_map[enemies[i].x-1][enemies[i].y+1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x-1][enemies[i].y+1],&enemies[i]);
			enemies[i].y++;
			enemies[i].x--;
		}else if(player.y > enemies[i].y && player.x > enemies[i].x && level_map[enemies[i].x+1][enemies[i].y+1].type==EMPTY){
			change_tile(erg_win,&level_map[enemies[i].x][enemies[i].y],&level_map[enemies[i].x+1][enemies[i].y+1],&enemies[i]);
			enemies[i].y++;
			enemies[i].x++;
		}*/



	}
}


void enemy_health(enemy_t *enemy,int damage){
	enemy->health-=damage;
}
