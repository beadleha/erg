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

void fillroom(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2);
void connect(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2);

#endif

