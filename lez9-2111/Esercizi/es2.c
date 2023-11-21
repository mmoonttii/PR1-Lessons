/* Scrivere un programma che acquisisca un numero e stampi un conto alla rovescia a partire dal
 * numero acquisito. Realizzare una procedura che si occupi di stampare il conto alla rovescia.
 */


#include <stdio.h>

void printReverse(int num);

int es2(){

	int num;

	printf("inserire num: ");
	scanf("%d", &num);

	printReverse(num);

    return 0;
}

void printReverse(int num){
	while (num >= 0){
		printf("\n%d", num);
		--num;
	}

}