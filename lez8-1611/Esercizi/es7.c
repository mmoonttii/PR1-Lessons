/* Scrivere un programma che cerchi la "maggiore" e la "minore" tra una serie di parole inserite dall'utente
 */

#include <stdio.h>
#include <string.h>

#define NUM_STR 4
#define DIM 20

int main(){

	char str[NUM_STR][DIM];
	int maggiore = 0;

	for (int i = 0; i < NUM_STR; ++i) {
		printf("\nStr %d", i);
		scanf("%s", str[i]);
		getchar();
	}

	for (int i = 0; i < NUM_STR; ++i) {
		if (strcmp(str[i], str[maggiore]) > 0){
			maggiore = i;
		}
	}

	printf("Str. maggiore: %d", maggiore);
	printf("%s", str[maggiore]);
	return 0;
}