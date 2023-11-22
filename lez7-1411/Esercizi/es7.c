/* Scrivere un programma in cui si dichiarano due matrici A e B. Dopo aver inizializzato A a piacere,
 * fare in modo che la matrice B sia la matrice trasposta di A. Stampare A e B.
 * NB: la matrice trasposta è una matrice che ha, per righe, le colonne della matrice di partenza e,
 * per colonne, le righe della matrice di partenza
 */

#include <printf.h>

#define ROWS 3
#define COLS 3

int es7() {

	int
		a[ROWS][COLS] = {{1, 2, 3},
						 {4, 5, 6},
						 {7, 8, 9}},
		b[ROWS][COLS];

	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			b[c][r] = a[r][c];
		}
	}

	printf("A Col:\t");

	for (int c = 0; c < COLS; ++c) {
		printf("%d\t", c);
	}

	for(int r = 0; r < ROWS; r++){
		printf("\nRiga %d:\t", r);
		for (int c = 0; c < COLS; c++) {
			printf("%d\t", a[r][c]);
		}
		printf("\n");
	}

	printf("\nB Col:\t");

	for (int c = 0; c < COLS; ++c) {
		printf("%d\t", c);
	}

	for(int r = 0; r < ROWS; r++){
		printf("\nRiga %d:\t", r);
		for (int c = 0; c < COLS; c++) {
			printf("%d\t", b[r][c]);
		}
		printf("\n");
	}
	return 0;
}