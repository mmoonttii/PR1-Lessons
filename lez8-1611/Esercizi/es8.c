/* Scrivere un filtor B1FF che letta una stringa la modifichi
 * - tutte le lettere diventano maiuscole
 * - A -> 4, B -> 8, E -> 3, I -> 1, O -> 0, S -> 5
 * - il messagio finisce in !!1!1
 * */

#include <stdio.h>
#include <string.h>

#define DIM 30

int es8(){
	char str[DIM + 1];
	char end[] = {"11!1!"};

	printf("\nStr: ");
	scanf("%[^\n]s", str);
	getchar();

	for (int i = 0; i < DIM; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
		}

		switch (str[i]) {
			case 'A':
				str[i] = '4';
				break;
			case 'B':
				str[i] = '8';
				break;
			case 'E':
				str[i] = '3';
				break;
			case 'I':
				str[i] = '1';
				break;
			case 'O':
				str[i] = '0';
				break;
			case 'S':
				str[i] = '5';
				break;
		}
	}

	strcat(str, end);
	printf("\n%s", str);
	return 0;
}