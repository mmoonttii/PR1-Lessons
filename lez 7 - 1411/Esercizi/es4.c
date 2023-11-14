/* Generare una matrice identità (1 sulla diagonale principale, 0 il resto con un solo for)
 */

#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int es4(){

	int matrix[ROWS][COLUMNS];


	// Popolazione matrice random
	for(int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLUMNS; c++) {
			if (r == c){
				matrix[r][c] = 1;
			} else {
				matrix[r][c] = 0;
			}
		}
	}
	/* for (int i = 0; i < ROWS; i++){
		matrix[i][i] = 1;
	*/

	// Stampa matrice
	printf("Col:\t");

	for (int c = 0; c < COLUMNS; ++c) {
		printf("%d\t", c);
	}
	for(int r = 0; r < ROWS; r++){
		printf("\nRiga %d:\t", r);
		for (int c = 0; c < COLUMNS; c++) {
			printf("%d\t", matrix[r][c]);
		}
		printf("\n");
	}
	return 0;
}