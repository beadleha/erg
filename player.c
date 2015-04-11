#include <stdio.h>
#include <stdlib.h>
#include "player.h"


void player_health(player_t *player,int damage){
	player->health-=damage;
}
