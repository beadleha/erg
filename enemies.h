#ifndef ENEMIES_H
#define ENEMIES_H

#define MAXFOES 5

typedef struct enemy_s{
	int x;
	int y;
	int awake;
	int health;
	int damage;
}enemy_t;

#include <ncurses.h>
#include "level.h"
#include "player.h"

int gen_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]);

void move_enemies(WINDOW *erg_win,player_t player, thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES], int numfoes);

void enemy_health(enemy_t *enemies,int damage);


#endif

