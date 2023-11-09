// Monti 09/11/2023
/* Scrivere un programma in cui si dichiarino due array, A e B. Inizializzare il primo array a
 * piacere e il secondo in modo che contenga gli stessi elementi di A in ordine inverso.
 * Stampare entrambi gli array come verifica della correttezza.
 */

#include <stdio.h>
#define LEN 6

int es3(){
	// Init arrays
	int a[LEN] = {5, 8, 11, 14, 17, 20};
	int b[LEN];

	// Leggiamo ogni elemento di a
	for (int i = 0; i < LEN; i++){
		b[i] = a[LEN - i - 1]; // Selezioniamo gli elementi di a a ritroso
	}

	// Stampiamo i due arrays per correttezza
	printf("a \t b");
	for (int i = 0; i < LEN; i++){
		printf("\n%d \t %d", a[i], b[i]);
	}

	return 0;
}
