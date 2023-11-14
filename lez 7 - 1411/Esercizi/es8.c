#include <printf.h>

/* Scrivere un programma che definisca una matrice N x N di lato massimo 10, chieda all’utente di
 * indicare la dimensione effettiva del lato (≤10) e la riempia di valori "a spirale" con valori crescenti
 * da 0 a (N2 – 1) iniziando dall'angolo superiore sinistro. Infine la visualizzi
 */

int main(){
	int dim;

	do {
		printf("Inserisci dimensione: ");
		scanf("%d", &dim);
	} while (dim > 10);

	int
		matrix[dim][dim],
		value = 0,
		col = 0,
		row = 1,
		counter = 0;

	while (value < (dim * dim -1)) {

		for (int c = 0; c <= dim - counter; ++c, ++value) {
			matrix[counter][c] = value;
		}

		for (int r = counter; r <= dim-counter; ++r, ++value) {
			matrix[r][dim - counter + 1];

		}

		counter++;
	}

	return 0;
}