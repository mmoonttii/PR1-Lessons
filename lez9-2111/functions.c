#include <stdio.h>

#define DIM 5
#define DIM2 3
#define DIM3 10

// Divide et impera: Sub-routines

// Dichiarazione e definizione
/* type nome_subroutine (parametri){
 * ...;
 * }
 */

// Dichiarazione
int somma (int, int);
void benvenuto(); // Quando una funzione non passa dei valori al main() si chiamano procedure e hanno void come tipo
int input();
void printArray(int array[], int dim);
void initArr(int array[], int dim);

void printMtrx(int r, int c, int matrix[][c]);

int functions() {// Entry point

	int nums[DIM + 1] = {3,4, 5,6, 7}, ris,
	    arr[DIM2 + 1] = {1, 2, 3},
	    arr3[DIM3] = {},
	matrix[3][DIM3] = {{3,4, 5,6, 7}, {1, 2, 3}, {}};

	benvenuto();

	nums[0] = input();
	nums[1] = input();

	ris = somma(nums[0], nums[1]);

//	printArray(nums, DIM);
//	putchar('\n');
//	printArray(arr, DIM2);
	printArray(arr3, DIM3);

	putchar('\n');

	initArr(arr3, DIM3);

	printArray(arr3, DIM3);

	printMtrx(3, DIM3, matrix);
	printMtrx(3, DIM3, matrix);
	printMtrx(3, DIM3, matrix);
	printf("\nIl risultato è %d", ris);
	return 0;
}

// Definizione
int somma(int a, int b){
	int ris;
	ris = a + b;
	return ris;
}

void benvenuto(){
	printf("Benvenuto!\n\n");
}

int input(){
	int num;

	printf("Inserisci num: ");
	scanf("%d", &num);

	return num;
}

void printArray(int array[], int dim){
	for (int i = 0; i < dim; ++i) {
		printf("%d\t", array[i]);
	}
}

void initArr(int array[], int dim){

	for (int i = 0; i < dim; ++i) {
		array[i] = i;
	}
}

void printMtrx(int r, int c, int matrix[][c]){
	static int count = 0; // Le variabili static "sopravvivono" all'esecuzione delle subroutine e vengono eliminate solo col termine del programma

	putchar('\n');

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		putchar('\n');
	}

	count++;

	printf("printMtrx è staa chiamata %d", count);

}