#include <stdio.h>
#include "drawutil.h"
#include "level.h"


void gen_map(thing_t level_map[WIDTH][HEIGHT]){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			level_map[i][j].type = EMPTY;
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
}