#ifndef DRAWUTIL_H
#define DRAWUTIL_H

#define WIDTH 80
#define HEIGHT 24


#include <ncurses.h>
#include "enemies.h"
#include "player.h"
#include "level.h"

void print_map(WINDOW *erg_win, thing_t level_map[WIDTH][HEIGHT]);
void print_thing(WINDOW *erg_win, int x, int y, char thing);
void print_beings(WINDOW *erg_win, player_t me, enemy_t * enemies, int numfoes);

int init_colors();

#endif

