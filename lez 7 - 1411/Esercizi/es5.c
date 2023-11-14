/* Scrivere un programma con una matrice MxN casuale.
 * Dichiarare un array R di N elementi e un array C di M elementi
 * Il programma salva in R[i] la somma degli elementi della riga i-esima della matrice e in C[j],
 * la somma degli elementi della colonna j-esima della matrice
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

#define MAX 100
#define MIN 0

int es5(){

	int
		matrix[ROWS][COLUMNS],
		r[ROWS] = {0,0,0},
		c[COLUMNS] = {0,0,0};

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

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			r[i] += matrix[i][j];
		}
	}

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			c[i] += matrix[j][i];
		}
	}

	for(int i = 0; i < ROWS; i++){
		printf("%d\t", r[i]);
	}

	printf("\n");

	for (int j = 0; j < COLUMNS; ++j) {
		printf("%d\t", c[j]);
	}

	return 0;
}