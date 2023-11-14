/* Scrivere un programma in cui dichiarata una matrice NxM, popolata con valori casuali, stampare
 * la matrice e la somma di tutti i valori
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

#define MAX 100
#define MIN 0

int es2(){

	int
		matrix[ROWS][COLUMNS],
		sum = 0;

	float
		avg;


	srand(time(NULL));

	// Popolazione matrice random
	for(int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLUMNS; c++) {
			matrix[r][c] = MIN + rand() % (MAX - MIN + 1);
			sum += matrix[r][c];
		}
	}

	avg = (float)sum / (ROWS * COLUMNS);

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

	printf("Somma: %d", sum);
	printf("Media: %.2f", avg);


	return 0;
}