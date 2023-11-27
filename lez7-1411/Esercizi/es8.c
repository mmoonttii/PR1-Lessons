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
		mtx[dim][dim],
		c = 0, r = 0, // col, rows
		k = 0;

	while (c < dim * dim){

		// Avanza verso dx
		while (r < dim - c){ // Le celle della riga
			mtx[r][c] = k;
			k++;
		}
		c--;
		r++;

		// Avanza verso il basso
		while (r <= dim){
			mtx[r][c] = k;
			r++;
			k++;
		}
		r--;
		c--;

		// Avanza verso sx
		while (c >= dim - r - 1){
			mtx[r][c] = k;
			c--;
			k++;
		}
		c++;
		r--;

		// Avanza verso alto
		while (r > c){
			mtx[r][c] = k;
			r--;
			k++;
		}
		r++, c++;
	}

	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			printf("%d\t", mtx[i][j]);
		}
		putchar('\n');
	}
	return 0;
}