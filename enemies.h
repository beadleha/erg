#ifndef ENEMIES_H
#define ENEMIES_H

#define MAXFOES 3

typedef struct enemy_s{
	int x;
	int y;
	int awake;
	int health;
	int damage;
}enemy_t;

#include <ncurses.h>
#include "level.h"

int gen_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]);

void move_enemies(WINDOW *erg_win, thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES], int numfoes);

void enemy_health(enemy_t *enemies,int damage);


#endif

