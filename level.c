#include <stdio.h>
#include "print.h"
#include "level.h"

void gen_map(thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	int left, top;
	int right, bottom;
	int numrooms = 3 + (rand() % 2);
	srand(time());

	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			level_map[i][j].type = ROCK;
			if(0==i)
				level_map[i][j].type = ROCK;
			if(0==j)
				level_map[i][j].type = ROCK;
			if((WIDTH-1)==i)
				level_map[i][j].type = ROCK;
			if((HEIGHT-1)==j)
				level_map[i][j].type = ROCK;
		}
	}

	numrooms=2;
	left=1;
	top=1;
	right=1;
	bottom=1;
	for(i=numrooms;i>0;i--){
		right += left + 1 + (rand()%10);
		bottom = 2+(rand()%5); 
		printf("Filling to %d,%d\n",right,bottom);
		fillroom(level_map, left, top, right, bottom);

		left += right + 1 + (rand()%10);
	}
}

void fillroom(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2){
	int i,j;
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
			printf("Filling %d,%d\n",i,j);
			level_map[i][j].type = EMPTY;
		}
	}
}

void connect(thing_t level_map[WIDTH][HEIGHT], int x1, int y1, int x2, int y2){
}

