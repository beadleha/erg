#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "level.h"
#include "room.h"

void gen_map(thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	int left, top;
	int right, bottom;
	int numrooms;
	int allconnected=1;
	room_t * roomlist;
	srand(time());

	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			level_map[i][j].type = ROCK;
		}
	}

	numrooms = 5 + (rand()%5);
	roomlist = malloc(numrooms * sizeof(room_t));
	left=rand()%14;
	top= 1 + rand()%7;
	right= 1 + left+1;
	bottom=top+1;
	for(i=numrooms;i>0;i--){
		right += left + 1 + (rand()%10);
		if (right >= WIDTH-1){
			top = bottom + (rand()%10);
			left = 1 + (rand()%10);
			right = left + 1 + (rand()%10);
		}
		bottom = top + 1 + (rand()%5); 
		if(bottom >= HEIGHT-1) goto CONSIDERED_HARMFUL;
		roomlist[numrooms-1].top = top;
		roomlist[numrooms-1].bottom = bottom;
		roomlist[numrooms-1].left = left;
		roomlist[numrooms-1].right = right;
		fillroom(level_map, left, top, right, bottom);

		left = right + 1 + (rand()%10);
	}

	CONSIDERED_HARMFUL:
	while(allconnected = 0){
		// Randomly connect rooms that are not connected
		int room1,room2,j;
		for(i=1;i<numrooms;i++){
			room1=(rand()%numrooms)-1;
			room2=(rand()%numrooms)-1;
			if(roomlist[room1].connected && roomlist[room2].connected == 0) continue;
			if(roomlist[room1].top<roomlist[room2].top){
				j=roomlist[room1].top;
			}
			for(j;j<roomlist[room2].top;j++){
				level_map[roomlist[room1].top][j].type=EMPTY;
			}
		} 
		// Cycle and check if any are not connected
		allconnected = 1;
		for(i=0;i<numrooms;i++){
			if(roomlist[i].connected == 0) allconnected=0;
		}
	}
}

void fillroom(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2){
	int i,j;
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
			level_map[i][j].type = EMPTY;
		}
	}
}

void connect(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2){
	
}

