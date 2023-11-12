/* Scrivere un programma in cui si dichiara un vettore di 5 elementi. Assegnare
 * casualmente 5 valori da 1 a 90 senza ripetizioni.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5
#define MAX 90
#define MIN 1


int es9(){

	int array[LEN];

	srand(time(NULL));

	for (int i = 0; i < LEN; i++){
		array[i] = MIN + rand() % (MAX + MIN - 1);

		for (int j = 0; j < i; j++){
			if (array[i] == array[j]){
				do {
					array[i] = MIN + rand() % (MAX + MIN - 1);
				} while	(array[i] == array[j]);
			}
		}
	}

	for (int i = 0; i < LEN; ++i) {
		printf("\n%d", array[i]);
	}

	return 0;
}