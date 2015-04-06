#ifndef LEVEL_H
#define LEVEL_H

typedef struct{
	enum {
		EMPTY, 
		ROCK,
		ENEMY,
	} type;
	enemy_t *whichfoe;
}thing_t;

//generates the level
void gen_map(thing_t level_map[WIDTH][HEIGHT]);

#endif

