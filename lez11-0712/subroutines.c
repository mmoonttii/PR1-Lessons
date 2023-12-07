#include <stdio.h>

void sumDiff(int x, int y, int *sum, int *diff);



int subs(){
	int a = 5, b = 10;

	int sum, diff;

	int *ptrSum = &sum;
	int *ptrDiff = &diff;

	sumDiff(a, b, ptrSum, ptrDiff);
//	Oppure
//	sumDiff(a, b, &sum, &diff);

	printf("\nSomma: %d", sum);
	printf("\nDiff: %d", diff);

	return 0;
}

void sumDiff(int x, int y, int *sum, int *diff) {
	*sum = x + y;
	*diff = x - y;
}