/* Scrivere un programma che prenda in ingresso due stringhe, s1 ed s2, e stampi se la stringa s2 è
 * completamente contenuta in s1 o meno. Per "completamente contenuta" si intende che i caratteri di s2 devono
 * essere presenti in s1 nella stessa sequenza in cui compaiono in s2. Ad esempio, la stringa "zio" è contenuta in
 * "funzione".
 */

#include <stdio.h>
#include <string.h>



#define DIM 30

int es9(){

	char
	        str1[DIM + 1],
	        str2[DIM + 1];

	int     found = 0,
	        j = 0;

	printf("\nStr 1: ");
	scanf("%[^\n]30s", str1);
	getchar();

	printf("\nStr 2: ");
	scanf("%[^\n]30s", str2);
	getchar();

	for (int i = 0; i<strlen(str1) && !found; ++i) {

		if (str2[j] == str1[i]){
			++j;
		} else {
			j = 0;
		}

		if(j == strlen(str2)) {
			found = 1;
		}
	}

	printf("\nLa stringa %s", str2);
	if( found )           // se il flag è 1, allora ho trovato s2 in s1
		printf(" e' contenuta in %s.\n", str1);
	else                    // altrimenti, non ho trovato s2 in s1
		printf(" non e' contenuta in %s.\n", str1);


    return 0;
}