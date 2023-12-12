/*  Scrivere una funzione che verifichi se c'è una sovrapposizione tra due intervalli (min1,max1) e
	(min2,max2). Se sì, la funzione restituirà vero e il punto medio della loro sovrapposizione si troverà in
	un argomento di output, altrimenti renderà falso
 */

#include <stdio.h>
#include <stdbool.h>

bool intersezione(int min1, int max1, int min2, int max2, float *output);

int main(){

    return 0;
}

bool intersezione(int min1, int max1, int min2, int max2, float *output) {
	bool result;

	result = min2 < max1;

	return result;
}
