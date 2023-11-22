/* Scrivere un programma in cui, dato un inseieme di valori in un array, si calcoli la media dei valori e vengano stampati
 * in output tutti i valori minori della media, tutti i valori maggiori della media e la media stessa
 * Infine stampare quanti sono i valori minori della media e quanti i valori maggiori
 */

#include <stdio.h>

#define LEN 10

int es2(){
	int nums[LEN], sum = 0, min = 0, mag = 0;
	float avg;

	for (int i = 0; i < LEN; i++){
		printf("\n[%d]: ", i);
		scanf("%d", &nums[i]);

		sum += nums[i];
	}

	avg = sum / LEN;

	printf("Avg: %f", avg);

	for (int i = 0; i < LEN; i++) {
		if (nums[i] > avg) {
			printf("\n%d Maggiore media", nums[i]);
			mag++;
		}
	}

	for (int i = 0; i < LEN; i++) {
		if (nums[i] < avg) {
			printf("\n%d Minore media", nums[i]);
			min++;
		}
	}

	for (int i = 0; i < LEN; i++) {
		if (nums[i] == avg) {
			printf("\n%d Uguale media", nums[i]);
		}
	}

	printf("\nNumeri maggiori della media: %d", mag);
	printf("\nNumeri minori della media %d", min);
	return 0;
}