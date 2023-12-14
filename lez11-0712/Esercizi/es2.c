// Scrivere una funzione che controlli se due vettori sono ugualo e restituisca true se si o false

#include <stdio.h>
#include <stdbool.h>

#define DIM 5

bool checkArr(int *a, int *b, int dim);

int es2(){

	int a[DIM] = {1, 2, 3, 4, 5},
		b[DIM] = {1, 2, 3, 4, 5};

	int *ptrA = &a[0],
		*ptrB = b;

	bool same = checkArr(ptrA, ptrB, DIM);

	if (same) {
		printf("a == b");
	} else {
		printf("a != b");
	}

    return 0;
}

bool checkArr(int *a, int *b, int dim){

	bool same = true;

	for (int i = 0; i < dim && same; ++i) {
		if (*a == *b){
			same = true;
		} else {
			same = false;
		}
		a++, b++;
	}

	return same;
}