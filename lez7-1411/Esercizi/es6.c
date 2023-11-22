/* Scrivere un programma in cui si dichiarano due matrici a e b inizializzate a piacere.
 * Dichiarare una terza matrice C che contenga la somma elemento per elemento delle altre matrici
 */
#include <printf.h>

#define ROWS 3
#define COLS 3

int es6(){

	int
		a[ROWS][COLS] = {{1,2,3},
						 {4,5,6},
						 {7,8,9}},
		b[ROWS][COLS] = {{10,11,12},
						 {13,14,15},
						 {16,17,18}},
		d[ROWS][COLS];

	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			d[r][c] = a[r][c] + b[r][c];
		}
	}

	// Stampa matrice
	printf("Col:\t");

	for (int c = 0; c < COLS; ++c) {
		printf("%d\t", c);
	}

	for(int r = 0; r < ROWS; r++){
		printf("\nRiga %d:\t", r);
		for (int c = 0; c < COLS; c++) {
			printf("%d\t", d[r][c]);
		}
		printf("\n");
	}

	return 0;
}