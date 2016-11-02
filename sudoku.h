/*
Sudoku Code Solver
Copyright (C) 2016 Ajinkya Landge 

LICENCE:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Sudoku{

	struct Square *** squares;
	struct Box ** boxes;

} Sudoku;

typedef struct Box{
	
	struct Square ** squares;
	int numbers;
	int possible[9];
	int solvable;
	struct Box * next;

} Box;

typedef struct Square{
	
	int number;

	/* [1] [1] [1] [1] [1] [1] [1] [1] [1]
	   [9] [8] [7] [6] [5] [4] [3] [2] [1] */

	int possible[9];
	int solvable;
	Box * box;
	int row;
	int column;

} Square;


int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Sudoku * setUpPuzzle(int ** puzzle);

Sudoku * createSudoku(Square *** squares, Box ** boxes);

int solveSquare(Square * square);
int checkPuzzle(Square *** sudoku, Box ** boxes);
int updateSudoku(Square *** sudoku, int row, int column);

/* Box functions */
Box ** createBoxes();
int updateBoxes(Square *** sudoku,int row, int column);

int boxSingles(Square *** sudoku,Box ** boxes);

int checkRows(Square *** sudoku, Box ** boxes);

#endif
