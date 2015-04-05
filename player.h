#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	int x;
	int y;
	int health;
}player_t;

//modify health
void modhealth(player_t *player,int modifier);

//modify attribute
void modatribute(player_t *player,int *attribute,int modifier);

#endif