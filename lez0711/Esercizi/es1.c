/* Scrivere un programma che generi una serie di N numeri casuali all'interno di un array
 * Dopodiche stampare in output tutti gli elementi in ordine inverso
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LEN 15
#define MAX 10

int main(){
	int i;
	int array[LEN];

	srand(time(NULL));

	for (i = 0; i < LEN; i++){
		array[i] = rand() % MAX;
		printf("%d\n", array[i]);
	}

	for (i = LEN - 1; i >= 0; i--){
		printf("[%d]: %d\n", i, array[i]);
	}
	return 0;
}