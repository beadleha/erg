#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	int x;
	int y;
	int health;
	int damage;
}player_t;

void player_health(player_t *player,int damage);

#endif

