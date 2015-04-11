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
	int room1, room2;
	int allconnected=0;
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
	for(i=0;i<numrooms;i++){
		right += left + 1 + (rand()%10);
		if (right >= WIDTH-1){ // Start new row
			top = bottom + (rand()%10);
			left = 1 + (rand()%10);
			right = left + 1 + (rand()%10);
		}
		bottom = top + 1 + (rand()%5); 
		if(bottom >= HEIGHT-1) goto CONSIDERED_HARMFUL;
		roomlist[i].top = top;
		roomlist[i].bottom = bottom;
		roomlist[i].left = left;
		roomlist[i].right = right;
		roomlist[i].connected = 0;

		fillroom(level_map, left, top, right, bottom);

		left = right + 1 + (rand()%10);
	}

	CONSIDERED_HARMFUL:
	allconnected = 0;
	while(allconnected == 0){
		allconnected = 1;

		// Randomly connect rooms
		room1 = rand()%numrooms;
		room2 = rand()%numrooms;
		connect(level_map, roomlist[room1].right, roomlist[room1].bottom, roomlist[room2].right, roomlist[room2].bottom);
		roomlist[room1].connected = 1;
		roomlist[room2].connected = 1;

		// Cycle and check if any are not connected
		for(i=0;i<numrooms;i++){
			if(roomlist[i].connected==0){
				allconnected=0;
			}
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
	int i,j;
	while(x1!=x2 | y1!=y2){
		if(x1<x2){
			x1++;
		}else if(x1>x2){
			x1--;
		}
		level_map[x1][y1].type=EMPTY;
		if(y1<y2){
			y1++;
		}else if(y1>y2){
			y1--;
		}
		level_map[x1][y1].type=EMPTY;
	}
}

