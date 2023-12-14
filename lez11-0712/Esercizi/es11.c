/*  Scrivere una funzione che verifichi se c'è una sovrapposizione tra due intervalli (min1,max1) e
	(min2,max2). Se sì, la funzione restituirà vero e il punto medio della loro sovrapposizione si troverà in
	un argomento di output, altrimenti renderà falso
 */

#include <stdio.h>
#include <stdbool.h>

#define DIM 4

bool intersezione(int min1, int max1, int min2, int max2, float *output, int a[]);

int main(){

	int min1, min2, max1, max2, a[DIM];
	bool flag;
	float output;

	printf("==Intervallo 1==\n"
		   "Minimo: ");
	scanf("%d", &min1);
	printf("Massimo: ");
	scanf("%d",&max1);

	printf("==Intervallo 2==\n"
		   "Minimo: ");
	scanf("%d", &min2);
	printf("Massimo: ");
	scanf("%d",&max2);

	flag = intersezione(min1, max1, min2, max2, &output, a);

	if (flag) {
		printf("\n\n%d\t%d\t%d\t%d", a[0], a[1], a[2], a[3]);
		printf("\nPunto medio intersezione [%d, %d] : %.3f", a[1], a[2], output);
	} else {
		printf("\n\n%d\t%d\t%d\t%d", a[0], a[1], a[2], a[3]);
		printf("\nNon abbiamo intersezione");
	}
	return 0;
}

bool intersezione(int min1, int max1, int min2, int max2, float *output, int a[DIM]) {
	bool result;

	if (min1 < min2){
		a[0] = min1;

		if (min2 < max1) {
			a[1] = min2;

			result = true;

			if (max1 > max2) {
				a[2] = max2;
				a[3] = max1;
			} else {
				a[2] = max1;
				a[3] = max2;
			}

		} else {
			a[1] = max1;
			a[2] = min2;
			a[3] = max2;
			result = false;
		}
	} else {
		a[0] = min2;

		if (min1 < max2) {
			a[1] = min1;

			result = true;

			if (max1 > max2){
				a[2] = max2;
				a[3] = max1;
			} else {
				a[2] = max1;
				a[3] = max2;
			}
		} else {
			a[1] = max2;
			a[2] = min1;
			a[3] = min2;
			result = false;
		}
	}

	if (result) {

		*output = (float)(a[1] + a[2])/2;

	}

	return result;
}
