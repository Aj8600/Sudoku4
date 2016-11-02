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


#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(){

	int ** puzzle;
	int progress;
	Sudoku * sudoku;

	puzzle = createPuzzle();

	sudoku = setUpPuzzle(puzzle);
	
	printf("The entered puzzle was:\n\n");

	printPuzzle(sudoku->squares);

	while(UNSOLVED > 0){

		progress = checkPuzzle(sudoku->squares, sudoku->boxes);

		if(progress == 0){

			printf("\n\n\nFailed to solve the puzzle!\n\n");
			break;

		}

	}

	printf("\n\n");

	printPuzzle(sudoku->squares);

	return 0;
}
