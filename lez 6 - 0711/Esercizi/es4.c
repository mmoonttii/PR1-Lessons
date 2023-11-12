/* Scrivere un programma in cui si dichiari e inizializzi a piacimento un array A, quindi
 * normalizzarlo. Stampare l'array prima e dopo la normalizzazione.
 * Hint: normalizzare un intervallo vuol dire portare tutti gli elementi dell’intervallo ad avere
 * valori compresi tra 0 e 1, secondo la formula x_norm = (x − min)/(max − min)
 */

#include <stdio.h>
#include <limits.h>

#define LEN 6

int es4(){
	// Init variabili
	int array[LEN],
		max = 0, min = INT_MAX; // Potrei inizializzare max e min a MIN - 1 e MAX + 1 se conosco il range
								// oppure posso inizializzare al primo elemento dell'array
	float norm[LEN];

	for (int i = 0; i < LEN; i++){
		printf("[%d]: ", i);
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < LEN; i++){
		// Scansiono l'array per trovare il valore massimo e minimo
		if (array[i] > max){
			max = array[i];
		}
		if (array[i] < min){
			min = array[i];
		}
	}

	// Normalizzo l'array
	for (int i = 0; i < LEN; i++){
		norm[i] = (float)(array[i] - min) / (max - min);
	}

	// Stampo gli array
	printf("array \t norm");
	for (int i = 0; i < LEN; i++){
		printf("\n%d \t %.4f", array[i], norm[i]);
	}

	return 0;
}