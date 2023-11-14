/* Scrivere un programma che stampi una matrice di float casuali dal primo all'ultimo elemento
 * e dall'ultimo al primo
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

#define MAX 10
#define MIN 1
#define MULT 100

int es3(){

	float matrix[ROWS][COLUMNS];

	srand(time(NULL));

	// Popolazione matrice random
	for(int r = 0; r < ROWS; ++r){
		for (int c = 0; c < COLUMNS; ++c) {
			matrix[r][c] = (float)(MIN*MULT + rand() % (MAX*MULT - MIN*MULT + 1))/MULT;
		}
	}

	// Stampa matrice
	printf("Col:\t");

	for (int c = 0; c < COLUMNS; ++c) {
		printf("%d\t\t", c);
	}
	for(int r = 0; r < ROWS; r++){
		printf("\nRiga %d:\t", r);
		for (int c = 0; c < COLUMNS; c++) {
			printf("%.2f\t", matrix[r][c]);
		}
		printf("\n");
	}

	printf("\nCol:\t");

	for (int c = COLUMNS - 1; c >= 0; c--) {
		printf("%d\t\t", c);
	}
	for(int r = ROWS - 1; r >= 0; r--){
		printf("\nRiga %d:\t", r);
		for (int c = COLUMNS - 1; c >= 0; c--) {
			printf("%.2f\t", matrix[r][c]);
		}
		printf("\n");
	}
	return 0;
}