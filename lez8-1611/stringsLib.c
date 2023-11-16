#include <stdio.h>
#include <string.h>

#define DIM 20
int stringsLib(){

	char str1[DIM + 1];
	char str2[DIM + 1];
	char nomeCognome[DIM + 1] = "";

	// strcpy(str1, str2) copia str2 in str1
	// strlen(str1) calcola lunghezza stringa, non array
	// strcmp(str1, str2) comparazione tra due stringhe -- Se le stringhe sono uguali restituisce 0
	// strcat(str1, str2) unisce le due stringhe in str1

/*  STRCMP(), STRLEN()
	printf("Nome 1: ");
	scanf("%[^\n]s", str1);
	printf("\nNome 1 lungo: %d", strlen(str1));

	getchar();

	printf("\nNome 2 :");
	scanf("%[^\n]s", str2);
	printf("\nNome 2 lungo: %d", strlen(str2));

	if (strcmp(str1, str2) == 0){ // o !strcmp(str1, str2)
		printf("\nOmonimi");
	} else {
		printf("\nNomi diversi");
	}
*/

/*  STRCAT()
	printf("\nNome: ");
	scanf(" %[^\n]s", str1);

	getchar();

	printf("\nCognome :");
	scanf("%[^\n]s", str2);

	strcat(nomeCognome, str1);
	strcat(nomeCognome, " ");
	strcat(nomeCognome, str2);

	printf("%s", nomeCognome);
 */

/*  STRCPY()
	printf("Nome: ");
	scanf("%[^\n]s", str1);

	stpcpy(str2, str1);

	printf("str2: %s", str2);
*/

	return 0;
}