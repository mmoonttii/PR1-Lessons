/* Scrivere un programma che prenda in ingresso una stringa e stampi in output se la stringa è palindroma. Una
 * stringa è palindroma se può essere letta nello stesso modo da sinistra verso destra e da destra verso sinistra.
 * Esempi: "anna", "kayak", "elle", "otto" sono palindrome.
 */

#include <stdio.h>
#include <string.h>

#define DIM 30

int main(){

	char str[DIM +1];
	int len, count = 0;

	printf("Inserire stringa: ");
	scanf("%[^\n]30s", str);

	len = strlen(str);

	for (int i = 0; i < (len/2); ++i) {
		if (str[i] == str[len-i]){

		}
	}


	return 0;
}