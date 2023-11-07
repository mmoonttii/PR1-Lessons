/* Scrivere un programma in cui, dato un inseieme di valori in un array, si calcoli la media dei valori e vengano stampati
 * in output tutti i valori minori della media, tutti i valori maggiori della media e la media stessa
 * Infine stampare quanti sono i valori minori della media e quanti i valori maggiori
 */

#include <stdio.h>

#define LEN 10

int main(){
	int valori[LEN], sum = 0;
	float avg;

	for (int i = 0; i < LEN; i++){
		printf("\n[%d]: ", i);
		scanf("%d", &valori[i]);

		sum += valori[i];
	}

	avg = sum / LEN;

	for (int i = 0; i < LEN; i++){
		if (valori[i] > avg){
			printf("%dMaggiore media")
		}
	}



	return 0;
}