/* Scrivere un programma che date due stringhe in input stampi la più lunga,
 * se di lunghezza uguale stampi la più lunga
 */

#include <stdio.h>
#include <string.h>

#define NUM_STR 2
#define DIM 30

int es1() {

	char strings[NUM_STR][DIM + 1];
	int longest = 0;

	// Acquisizione stringhe
	for (int i = 0; i < NUM_STR; ++i) {
		printf("\nStr %d: ", i);
		scanf("%[^\n]s", strings[i]);
		getchar();

		// Cerco la stringa più lunga
		if (strlen(strings[longest]) < strlen(strings[i])) {
			longest = i;
		}
	}

		printf("%s", strings[longest]);


	return 0;
}
