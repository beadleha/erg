#include <stdio.h>
#include "drawutil.h"
#include "enemies.h"


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

void isawake(enemy_t enemies[MAXFOES],int numfoes){

}

void detectplayer(enemy_t enemies[MAXFOES],int numfoes){

} 
