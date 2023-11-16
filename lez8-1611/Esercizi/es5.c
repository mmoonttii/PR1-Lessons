#include <stdio.h>

#define DIM 20

int es5(){

	char str[DIM + 1];

	printf("\nStr: ");
	scanf("%s", str);
    getchar();

	for (int i = 0; i < DIM; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}
	}

	printf("Str: %s", str);

	return 0;
}