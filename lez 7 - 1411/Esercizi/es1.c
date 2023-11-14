#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

#define MAX 100
#define MIN 0

int es1(){

	int matrix[ROWS][COLUMNS];

	srand(time(NULL));

	// Popolazione matrice random
	for(int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLUMNS; c++) {
			matrix[r][c] = MIN + rand() % (MAX - MIN + 1);
		}
	}

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