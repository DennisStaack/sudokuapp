#ifndef GRID_H
#define GRID_H

typedef struct {
	int value; //0 empty, 1-9 numbers
	int fixed; //1 given, 0 entered by player
} Cell;

typedef struct {
	Cell cell[9][9];
} Grid;

void initGrid();
void printGrid();
void inputGrid(int x, int y, int num, int set);
int possible(int x, int y, int num);
int solve();
int rPos();
void removeCells(int count);

#endif
