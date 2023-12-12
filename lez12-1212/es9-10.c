/*  Scrivere una funziona creaMatriceDinamica che riceva due interi R, C, in ingresso rappresentanti il numero di righe
 *  e il numero di colonne, e restituisca una matrice RxC allocata dinamicamente.
 *  Scrivere un programma che crei dinamicamente una matrice usando la funzione dell'esercizio 9, la
 *  popoli casualmente e la stampi in output
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 20

int **creaMatriceDinamica(int r, int c);
void popolaMatrice(int r, int c, int **matrice);
void stampaMatrice(int r, int c, int **matrice);

int main(){

	srand(time(NULL));

	int **matriceDinameica = NULL;
	int r, c;
	printf("Inserisci righe: ");
	scanf("%d", &r);
	printf("Inserisci colonne: ");
	scanf("%d", &c);

	matriceDinameica = creaMatriceDinamica(r, c);
	popolaMatrice(r, c, matriceDinameica);
	stampaMatrice(r, c, matriceDinameica);

	for (int i = 0; i < r; ++i) {
		if (matriceDinameica[i] != NULL){
			free(matriceDinameica[i]);
			matriceDinameica[i] = NULL;
		}
	}

	if (matriceDinameica != NULL){
		free(matriceDinameica);
		matriceDinameica = NULL;
	}
    return 0;
}


int **creaMatriceDinamica(int r, int c) {

	int **matrice = NULL;

	matrice = (int **) calloc(r, sizeof(int *));
	if (matrice == NULL) {
		exit(-1);
	}

	for (int i = 0; i < r; ++i) {
		matrice[i] = (int *) calloc(c, sizeof(int));
		if (matrice[i] == NULL){
			exit(-2);
		}
	}

	return matrice;
}

void popolaMatrice(int r, int c, int **matrice) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrice[i][j] = MIN + rand() % (MAX - MIN + 1);
		}
	}
}

void stampaMatrice(int r, int c, int **matrice) {
	printf("\n==Stampa matrice %dx%d==\n",r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%d\t",matrice[i][j]);
		}
		printf("\n");
	}
}
