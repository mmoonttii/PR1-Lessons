/* Il programma acquisisce una strinha e conta utilizzando i numeri di caratteri spazio inseriti dall'utente in due modi:
 * - strlen() e un for
 * - con un ciclo che si ferma a '\0' e un while
 * Quale sol è preferbile, perch?
 */

#include <stdio.h>
#include <string.h>

#define DIM 20

int es6(){
	char str[DIM + 1];
	int spaces = 0,
	    i = 0;


	printf("\nStr: ");
	scanf("%[^\n]s", str);
	getchar();

	/*
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 32){
			spaces++;
		}
	}
	*/

	while (str[i] != '\0'){
		if (str[i] == 32){
			spaces++;
		}
		++i;
	}

	printf("Spazi: %d", spaces);
	return 0;
}