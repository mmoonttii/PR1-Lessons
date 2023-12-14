#include <stdio.h>
#include <stdlib.h>

int *createMatrix(int r, int c, int initialValue);

int main(){
	int *matriceDin = NULL;
	int r, c;

	printf("Inserisci righe: ");
	scanf("%d", &r);
	printf("Inserisci colonne: ");
	scanf("%d", &c);

	matriceDin = createMatrix(r, c, 5);

	if (matriceDin != NULL) {
		free(matriceDin);
		matriceDin = NULL;
	}

    return 0;
}

int *createMatrix(int r, int c, int initialValue){

	int *matrix = NULL;

	matrix = (int *)calloc(r*c, sizeof(int));

	if (matrix == NULL){
		exit(-1);
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i * c + j] = initialValue; // Simuliamo i doppi indici delle matrici
			printf("%d\t",matrix[i * c + j]);
		}
		printf("\n");
	}
	return matrix;
}
