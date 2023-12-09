//4. Scrivere una subroutine che stampi un array ricevuto come parametro.
//5. Scrivere una subroutine che stampi una matrice, utilizzando la subroutine scritta per l'esercizio 4

#include <stdio.h>
#define DIM 5
void printMtrx(int *mtx, int dim);

int main(){
	int mtx [DIM][DIM] = {1,2,3,4,5,67,8,2,5,76,};
    return 0;
}

void printMtrx(int *mtx, int dim){

	for (int i = 0; i < dim; ++i) {
		printf("\n%d",*mtx);
		mtx++;
	}
}