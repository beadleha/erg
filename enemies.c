#include <stdio.h>
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

// This only updates the map, the enemy still needs to be printed
void move_enemies(WINDOW *erg_win, thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES], int numfoes){
	int i;
	for(i=0;i<numfoes;i++){
		if(level_map[enemies[i].x+1][enemies[i].y].type == EMPTY){

			// Rid old location of enemy data
			level_map[enemies[i].x][enemies[i].y].type = EMPTY;
			level_map[enemies[i].x][enemies[i].y].whichfoe = NULL;

			// Visually clear old location
			print_thing(erg_win, enemies[i].x, enemies[i].y, ' ');
			enemies[i].x++;

			// Add enemy data to new location
			level_map[enemies[i].x][enemies[i].y].type = ENEMY;
			level_map[enemies[i].x][enemies[i].y].whichfoe = &enemies[i];
		}
	}
}


void enemy_health(enemy_t *enemy,int damage){
	enemy->health-=damage;
}
