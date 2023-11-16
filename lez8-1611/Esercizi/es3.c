/* Il programm chiede una stringa e calcoli da quanti caratteri è composta, senza strlen()
 */

#include <stdio.h>

#define DIM 20
int es3(){

	char str[DIM + 1];
	int count = 0;

	printf("Input: ");
	scanf("%[^\n]s", str);

	while (str[count] != '\0'){
		count++;
	}

	printf("\n%s", str);
	printf("\n%d", count);
	return 0;
}