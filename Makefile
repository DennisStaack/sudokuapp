CC = gcc
SRC = sudoku.c grid.c
CFLAGS = -Wall -Werror -g -O1 -std=c99 -Wno-missing-braces
LIB = -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(SRC)
	$(CC) $(SRC) -o sudokuApp.exe $(CFLAGS) $(LIB)

clean:
	rm sudokuApp.exe
