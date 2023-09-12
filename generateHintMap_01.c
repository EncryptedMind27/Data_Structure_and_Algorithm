#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==== CHANGE THE SIZE OF GRID HERE ==== 
#define ROWS 10
#define COLS 10

int** generateHintMap(int **mines){

	// DIRECTIONS

	int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};		
    
    // CREATES 2D ARRAY FOR THE HNIT MAP
	int **hintMap = (int**) malloc(sizeof(int*)*ROWS);
	for(int x = 0; x < ROWS; x++ )
		hintMap[x] = (int*) malloc(sizeof(int)*COLS);

    // CHECKS THE MINE ARRAY AND ASSIGN THE HINT MAP
	for(int row = 0; row < ROWS; row++){
		for(int col = 0; col < COLS; col++){

            // CHECKS IF TILE HAS A BOMB/UNSAFE
			if(mines[row][col]==1){
				hintMap[row][col] =	 -1;
			} else {

                // CHECKS FOR NEIGHBORING TILE IF UNSAFE
				int ctrMines = 0;
				for(int i = 0; i < 8 ; i++){
					int newRow = row + dr[i];
					int newCol = col + dc[i];
				
					if(newRow >= 0 && newRow < ROWS &&
					   newCol >= 0 && newCol < COLS &&
					   mines[newRow][newCol] == 1){
							ctrMines++;
					}
				}
				hintMap[row][col] = ctrMines;
			}
		}

	}
	return hintMap;
}

int main()
{
	srand(time(NULL));

 	int **mines = (int**) malloc(sizeof(int*)*ROWS);
 	for(int x = 0; x < ROWS;x++){
 		mines[x] = (int*) malloc(sizeof(int)*COLS);
 		for(int i = 0; i < COLS;i++){
 			mines[x][i] = (rand()%2);
 		}
 	}

 	for(int x = 0; x < ROWS;x++){
 		for(int i = 0; i < COLS;i++){
 			printf("%2d ",mines[x][i]);
 		}
 		printf("\n");
 	}

 	mines = generateHintMap(mines);
 	printf("\n");

 	for(int x = 0; x < ROWS;x++){
 		for(int i = 0; i < COLS;i++){
 			printf("%2d ",mines[x][i]);
 		}
 		printf("\n");
 	}
 	
 	for(int x = 0;x < ROWS;x++){
 		free(mines[x]);
 	}
 	free(mines);
 	mines = NULL;

    return 0;	
}
