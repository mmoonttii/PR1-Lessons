/* Scrivere un programma che inizializzi un vettore, di dimensione N, a piacere, con valori casuali mediante
 * una subroutine initArray(…).
 * Il programma deve poi chiedere un valore all'utente e, mediante apposita subroutine, deve capire se quel
 * valore è contenuto nel vettore oppure no. Stampare tale informazione in output.
 * Nel caso in cui lo sia, mediante apposita subroutine, identificare quante volte è contenuto e poi
 * staparlo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0
#define MAX 50
#define DIM 20

int randRange(int min, int max);
void initArr(int min, int max, int dim, int arr[dim]);
int searchArr(int val, int dim, int arr[dim]);
int countArr(int val, int dim, int arr[dim]);

int main(){
	srand(time(NULL));
	int arr[DIM],
		val,
		found,
		count;

	initArr(MIN, MAX, DIM, arr);

	printf("Inserire valore da cercare: ");
	scanf("%d", &val);

	found = searchArr(val, DIM, arr);

	if (found){
		count = countArr(val, DIM, arr);
		printf("%d è presente nellarray %d volte", val, count);
	}
    return 0;
}

int randRange(int min, int max){
	int random;

	random = min + rand()%(max - min + 1);

	return random;
}

void initArr(int min, int max, int dim, int arr[dim]){

	for (int j = 0; j < dim; ++j) {
		arr[j] = randRange(min, max);
	}

}

int searchArr(int val, int dim, int arr[dim]){
	int found = 0;
	for (int i = 0; i < dim; ++i) {
		if (arr[i] == val) {
			found = 1;
		}
	}

	return found;
}

int countArr(int val, int dim, int arr[dim]){
	int count = 0;
	for (int i = 0; i < dim; ++i) {
		if (arr[i] == val){
			++count;
		}
	}
	return count;
}