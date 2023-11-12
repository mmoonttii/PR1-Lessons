/* Scrivere un programma in cui si dichiara e inizializza un array A, quindi stamparlo.
 * Senza utilizzare altri array d'appoggio, invertire l'ordine degli elementi di A e ristampare
 * il vettore così modificato.
 */


#include <stdio.h>


#define LEN 6

int es8(){
	int array[LEN], aux;

	for (int i = 0; i < LEN; i++){
		printf("[%d]: ", i);
		scanf("%d", &array[i]);
	}
	for (int i = 0; i < LEN; i++){
		printf("\n[%d]: %d", i, array[i]);
	}

	for (int i = 0; i < LEN/2; ++i) {
		aux = array[i];
		array[i] = array[LEN - i - 1];
		array[LEN - i - 1] = aux;
	}

	for (int i = 0; i < LEN; i++){
		printf("\n[%d]: %d", i, array[i]);
	}
	return 0;
}