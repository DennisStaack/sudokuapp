#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


extern Grid *grid;

int rPos() {
	int cap = 9;

	return rand() % cap;
}

//shuffle numbers in an array
void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

//init the grid with 0
void initGridZero() {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			grid->cell[i][j].value = 0;
		}
	}
}

void initGridRando() {
	int shouse[] = {1,2,3,4,5,6,7,8,9};

	//load all the houses with random numbers
	for(int box = 0; box < 9; box++) {
		int rowCount = 0, colCount = 0, count = 0;
		shuffle(shouse, 9);

		switch(box) {
			case 0: rowCount = 0; colCount = 0; break;
			case 1: rowCount = 0; colCount = 3; break;
			case 2: rowCount = 0; colCount = 6; break;
			case 3: rowCount = 3; colCount = 0; break;
			case 4: rowCount = 3; colCount = 3; break;
			case 5: rowCount = 3; colCount = 6; break;
			case 6: rowCount = 6; colCount = 0; break;
			case 7: rowCount = 6; colCount = 3; break;
			case 8: rowCount = 6; colCount = 6; break;

		}
		
		for(int row = rowCount; row < rowCount+3; row++) {
			for(int col = colCount; col < colCount+3; col++) {
				grid->cell[row][col].value = shouse[count];
				count++;
			}
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

//checks if a given input would be possible according to sudoku rules
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

//solves the sudoku through backtracking
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

//remove a count number off random cells
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


//checks if all houses, rows and columns have numbers 1-9 in them
bool perfect() {

	//house check
	for(int box = 0; box < 9; box++) {
		bool reg[9] = {false}; 
		reg[0] = true;
		int rowCount = 0, colCount = 0;

		switch(box) {
			case 0: rowCount = 0; colCount = 0; break;
			case 1: rowCount = 0; colCount = 3; break;
			case 2: rowCount = 0; colCount = 6; break;
			case 3: rowCount = 3; colCount = 0; break;
			case 4: rowCount = 3; colCount = 3; break;
			case 5: rowCount = 3; colCount = 6; break;
			case 6: rowCount = 6; colCount = 0; break;
			case 7: rowCount = 6; colCount = 3; break;
			case 8: rowCount = 6; colCount = 6; break;

		}
		
		for(int row = rowCount; row < rowCount+3; row++) {
			for(int col = colCount; col < colCount+3; col++) {
				int cellCheck = grid->cell[row][col].value;
				reg[cellCheck] = true;
			}
		}

		for(int b = 0; b < 9; b++) {
			if(!reg[b]) {
				printf("box %d failed on bool %d!\n", box, b);
				return false;
			}

		}

	}

	//row check
	for(int row = 0; row < 9; row++) {
		bool reg[9] = {false}; 
		reg[0] = true;
		for(int col = 0; col < 9; col++) {
			int cellCheck = grid->cell[row][col].value;
			reg[cellCheck] = true;
		}

		for(int b = 0; b < 9; b++) {
			if(!reg[b]) {
				printf("row %d failed on bool: %d!\n", row, b);
				return false;
			}
		}
	}

	//column check
	for(int col = 0; col < 9; col++) {
		bool reg[9] = {false}; 
		reg[0] = true;
		for(int row = 0; row < 9; row++) {
			int cellCheck = grid->cell[row][col].value;
			reg[cellCheck] = true;
		}

		for(int b = 0; b < 9; b++) {
			if(!reg[b]) {
				printf("col %d failed on bool: %d!\n", col, b);
				return false;
			}
		}
	}
	
	return true;
}

//try bas, pas, abs
void trySolveMethods() {
	bool rowSorted[9] = {false};
	bool colSorted[9] = {false};
	int cap = 20;
	//shrink square
	for(int i = 0; i < 9; i++) {
		//0 for rows, 1 for columns
		for(int a = 0; a < 2; a++) {
			bool reg[10] = {false}; //register if a number appeard
			for(int j = 0; j < 9; j++) {
				if(a == 0) { 
					int cell = grid->cell[j][i].value;
					if(!reg[cell]) {//found duplicate
						reg[cell] = true;
					} else { //do bas
						
					}
				} else {
					int cell = grid->cell[i][j].value;
					reg[cell] = true;
				}


			}
		}
	}
}

void generate() {
	initGridRando();
	trySolveMethods();


}


