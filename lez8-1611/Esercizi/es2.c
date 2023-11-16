/* Scrivere un programma che acquisite due stringhe stampi la maggiore alfabeticamente
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STR 2
#define DIM 30

int es2() {

	char strings[NUM_STR][DIM + 1];
	int
	        maggiore = 0,
	        count = 0;

	bool found = false;
	// Acquisizione stringhe
	for (int i = 0; i < NUM_STR; ++i) {
		printf("\nStr %d: ", i);
		scanf("%[^\n]s", strings[i]);
		getchar();

		for (int j = 0; j < DIM; ++j) {
			if (strings[i][j] >= 'A' && strings[i][j] <= 'Z'){
				strings[i][j] += 32;
			}
		}
	}

	if (strcmp(strings[0], strings[1]) > 0){
		printf("La prima è maggiore");
	}

	return 0;
}
