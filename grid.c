#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


extern Grid *grid;

int rPos() {
	int cap = 9;

	return rand() % cap;
}

void initGrid() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			grid->cell[i][j].value = 0;
		}
	}
}

void printGrid(){
	printf("\n\n");

	for(int i = 0; i < 9; i++) {
		if(i == 3 )
			printf("----------------------------\n\n");
		if(i == 6 )
			printf("----------------------------\n\n");
		for(int j = 0; j < 9; j++) {
			printf(" %d ", grid->cell[i][j].value);
			if(j == 2 ) {
			printf("%c", 124);
			}
			if(j == 5 ) {
			printf("%c", 124);
			}
		}
		printf("\n         %c         %c        \n", 124, 124);
	}
}

void inputGrid(int x, int y, int num, int set) {
	grid->cell[x][y].value = num;
	grid->cell[x][y].fixed = set;
}

int possible(int x, int y, int num) {
	for(int i = 0; i < 9; i++) {
		if(grid->cell[x][i].value == num)
			return 0;
	}
	for(int i = 0; i < 9; i++) {
		if(grid->cell[i][y].value == num)
			return 0;
	}
	int x0 = (x/3)*3;
	int y0 = (y/3)*3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(grid->cell[x0+i][y0+j].value == num)
				return 0;
		}
	} 
	return 1;
}

int solve() {
	for(int x = 0; x < 9; x++) {
		for(int y = 0; y < 9; y++) {
			if(grid->cell[x][y].value == 0) {
				for(int i = 1; i < 10; i++) {
					if(possible(x, y, i)) {
						inputGrid(x, y, i, 1);
						if(solve())
							return 1;
						inputGrid(x, y, 0, 1);
					}
				}
				return 0;
			}
		}
	}
	printGrid();
	return 1;
}

void removeCells(int count) {
	//remove 31
	bool removed[9][9] = {false};
	int remCount = 0;
	int maxAtt = 1000;
		
	while(remCount < count && maxAtt-- > 0) {
		int xR = rPos();
		int yR = rPos();

		if(!removed[xR][yR] && grid->cell[xR][yR].value != 0) {
			inputGrid(xR, yR, 0, 1);
			removed[xR][yR] = true;
			remCount++;
		}
	}
}




