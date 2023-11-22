/* Scrivere un programma in cui si dichiara un vettore A e si inizializza in maniera casuale.
 * Trovare l’elemento, tra quelli presenti, più vicino a un numero inserito dall'utente.
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>

#define LEN 5
#define MAX 50
#define MIN 1

int es5(){

	int array[LEN], userIn, diff = INT_MAX, nearest;

	srand(time(NULL));

	// Generazione casuale array
	for (int i = 0; i < LEN; i++){
		array[i] = MIN + rand() % (MAX + MIN - 1);
	}

	// Acquisizione input
	printf("Inserire numero: ");
	scanf("%d", &userIn);

	for (int i = 0; i < LEN; i++){
		// Se la distanza tra l'attuale valore analizzato e l'input è minore della precedente distanza
		// Salvo la distanza e l'attuale valore
		if (abs(userIn - array[i]) < diff){
			diff = abs(userIn - array[i]);
			nearest = array[i];
		}
	}

	printf("Il più vicino è %d", nearest);
	return 0;
}