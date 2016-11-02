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


#include"sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes){

	int i, j, k;

	int sum[9];
	int place[9];

	//loop through all rows

	for(i =0; i < 9; i++){
		
		//initialize sum and place to zero
		for(j = 0; j < 9; j++){

			place[j] = 0;
			sum[j] = 0;

		}
		//loop through each square in the row
		for(j = 0; j < 9; j++){

			if(sudoku[i][j]->number != 0){

				continue;

			}
		
			//loop through all possibles
			for(k = 0; k < 9; k++){

				//check if number {k} is possible
				if(sudoku[i][j]->possible[k] == 0){

					sum[k]++;
					place[k] = j;

				}

			}
		}

		for(k = 0; k < 9; k++){

			if(sum[k] == 1){

				sudoku[i][place[k]]->number = k + 1;
				sudoku[i][place[k]]->solvable = 0;
				UNSOLVED--;

				updateSudoku(sudoku, i, place[k]);
				updateBoxes(sudoku, i, place[k]);

				return 1;
			}

		}
	}

	return 0;
}
