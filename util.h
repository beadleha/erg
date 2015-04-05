#ifndef UTIL_H
#define UTIL_H

#define WIDTH 80
#define HEIGHT 24
#define MAXFOES 3

typedef struct{
	int x;
	int y;
	int health;
}player_t;

typedef struct{
	int x;
	int y;
	int awake;
	int health;
}enemy_t;

typedef struct{
	enum {
		EMPTY, 
		ROCK,
		ENEMY,
	} type;
	enemy_t * whichfoe;
}thing_t;

void gen_map(thing_t level_map[WIDTH][HEIGHT]);
int gen_enemies(thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES]);

void move_enemies(WINDOW *menu_win, thing_t level_map[WIDTH][HEIGHT], enemy_t enemies[MAXFOES], int numfoes);

void print_map(WINDOW *menu_win, thing_t level_map[WIDTH][HEIGHT]);
void print_thing(WINDOW *menu_win, int x, int y, char thing);
void print_beings(WINDOW *menu_win, player_t me, enemy_t * enemies, int numfoes);

int init_colors();

#endif

