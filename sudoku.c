//#include "include/raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

#define EASY 30

Grid *grid;

int main() {
	srand(time(NULL));

	grid = malloc(sizeof(Grid));

	initGridZero();

	//inputGrid(0, 0, 4, 1);
	//inputGrid(0, 6, 8, 1);
	//inputGrid(0, 8, 5, 1);
	//inputGrid(1, 1, 3, 1);
	//inputGrid(2, 3, 7, 1);
	//inputGrid(3, 1, 2, 1);
	//inputGrid(3, 7, 6, 1);
	//inputGrid(4, 4, 8, 1);
	//inputGrid(4, 6, 4, 1);
	//inputGrid(5, 4, 1, 1);
	//inputGrid(6, 3, 6, 1);
	//inputGrid(6, 5, 3, 1);
	//inputGrid(6, 7, 7, 1);
	//inputGrid(7, 0, 5, 1);
	//inputGrid(7, 3, 2, 1);
	//inputGrid(8, 0, 1, 1);
	//inputGrid(8, 2, 4, 1);

	// Row 0: [5,3,0,0,7,0,0,0,0]
	//inputGrid(0, 0, 5, 1);
	//inputGrid(0, 1, 3, 1);
	//inputGrid(0, 4, 7, 1);

	//// Row 1: [6,0,0,1,9,5,0,0,0]
	//inputGrid(1, 0, 6, 1);
	//inputGrid(1, 3, 1, 1);
	//inputGrid(1, 4, 9, 1);
	//inputGrid(1, 5, 5, 1);

	//// Row 2: [0,9,8,0,0,0,0,6,0]
	//inputGrid(2, 1, 9, 1);
	//inputGrid(2, 2, 8, 1);
	//inputGrid(2, 7, 6, 1);

	//// Row 3: [8,0,0,0,6,0,0,0,3]
	//inputGrid(3, 0, 8, 1);
	//inputGrid(3, 4, 6, 1);
	//inputGrid(3, 8, 3, 1);

	//// Row 4: [4,0,0,8,0,3,0,0,1]
	//inputGrid(4, 0, 4, 1);
	//inputGrid(4, 3, 8, 1);
	//inputGrid(4, 5, 3, 1);
	//inputGrid(4, 8, 1, 1);

	//// Row 5: [7,0,0,0,2,0,0,0,6]
	//inputGrid(5, 0, 7, 1);
	//inputGrid(5, 4, 2, 1);
	//inputGrid(5, 8, 6, 1);

	//// Row 6: [0,6,0,0,0,0,2,8,0]
	//inputGrid(6, 1, 6, 1);
	//inputGrid(6, 6, 2, 1);
	//inputGrid(6, 7, 8, 1);

	//// Row 7: [0,0,0,4,1,9,0,0,5]
	//inputGrid(7, 3, 4, 1);
	//inputGrid(7, 4, 1, 1);
	//inputGrid(7, 5, 9, 1);
	//inputGrid(7, 8, 5, 1);

	//// Row 8: [0,0,0,0,8,0,0,7,9]
	//inputGrid(8, 4, 8, 1);
	//inputGrid(8, 7, 7, 1);
	//inputGrid(8, 8, 9, 1);


	//printGrid();

	//solve();
	//inputGrid(8, 7, 9, 1);

	printGrid();
	
	generate();


	//removeCells(EASY);

	printGrid();

	//Color darkBlue = {44, 44, 127, 255};

	//InitWindow(300, 600, "Sudoku Fickers");

	//SetTargetFPS(144);

	//while(WindowShouldClose() == false) {
		//events
		//updates
		//drawing

		//BeginDrawing();
		//ClearBackground(darkBlue);

		//EndDrawing();


	//}

	
	free(grid);
	//CloseWindow();
	
	
	return 0;
}
