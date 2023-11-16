/* In un programma si dichiarino due stringhe di dim N e le si acquisisono
 * Il progrmma copia la seconda nella prima senza strcpy
 * Stampare la stringhe prima e dopo la copia
 */

#include <stdio.h>

#define NUM_STRS 2
#define CHAR_STRS 30

int es4(){
	char strings[NUM_STRS][CHAR_STRS];

	for (int i = 0; i < NUM_STRS; ++i) {
		printf("\nStr %d", i);
		scanf("%s", strings[i]);
		getchar();
	}

	printf("\n0: %s", strings[0]);
	printf("\n1: %s", strings[1]);

	for (int j = 0; j < CHAR_STRS; ++j) {
		strings[0][j] = strings[1][j];
	}

	printf("\n0: %s", strings[0]);
	printf("\n1: %s", strings[1]);

	return 0;
}