#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int r, int c, int initialValue);

int main(){
	int **matriceDin = NULL;
	int r, c;

	printf("Inserisci righe: ");
	scanf("%d", &r);
	printf("Inserisci colonne: ");
	scanf("%d", &c);

	matriceDin = createMatrix(r, c, 5);

	if (matriceDin != NULL) {
		// Deallocazione di ogni riga
		for (int i = 0; i < r; ++i) {
			if (matriceDin[i] != NULL){
				free(matriceDin[i]);
				matriceDin[i] = NULL;
			}
		}
		// Deallocazione dell'intera matrice
		free(matriceDin);
		matriceDin = NULL;
	}

	// Lavorando in questo modo non abbaimo bisogno di avere c*r celle vicine, ne bastano r vicine e r volte c vicine
	// Facendo così possiamo anche creare righe di lunghezza diversa
	return 0;
}

int **createMatrix(int r, int c, int initialValue){

	int **matrix = NULL;

	matrix = (int **) calloc(r, sizeof(int *)); // Allochiamo dinamicamente un array di puntatori, grande r

	if (matrix == NULL) {
		exit(1);
	}

	for (int i = 0; i < r; ++i) {
		matrix[i] = (int *) calloc(c, sizeof(int)); // Ogni elemento dell'array matrix prende il puntatore a un array
		if (matrix[i] == NULL){
			exit(2);
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = initialValue;
		}
	}

	return matrix;
}
