/*  Scrivere un programma che evochi una procedura che, ricevuti tre valori e l'indirizzo di memoria di due variabili
	(min, max) definite nel main, memorizzi il min e il max all'interno delle realtive variabili.
	Effettuare la stampa nel main
*/

#include <stdio.h>
#define DIM 5

void minMax(int *min, int *max, int dim, int vec[]);


int main(){
	int min, max;
	int vec[] = {1,2,3, 5,4};

	minMax(&min, &max, DIM, vec);

	printf("\nMax %d", max);
	printf("\nMin %d", min);
	return 0;
}

/*
void minMax(int *min, int *max, int a, int b, int c) {
	if (a > c && a > b) {
		*max = a;
		if (c > b) {
			*min = b;
		} else {
			*min = c;
		}
	} else if (b > c && b > a) {
		*max = b;
		if (c > a) {
			*min = a;
		} else {
			*min = c;
		}
	} else if (c > a && c > b) {
		*max = c;
		if (a > b) {
			*min = b;
		} else {
			*min = a;
		}
	}
}*/


void minMax(int *min, int *max, int dim, int vec[]) {
	*min = vec[0];
	*max = vec[0];

	for (int i = 0; i < dim; ++i) {
		if (vec[i] > *max){
			*max = vec[i];
		}
		if (vec[i] < *min){
			*min = vec[i];
		}
	}

}
