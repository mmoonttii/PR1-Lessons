/* Scrivere una funzione che esegua l'acquisizione da input di un numero e il controllo che il numero si
 * trovi all'interno di un determinato intervallo (min, max), mediante l'acquisizione ripetuta del numero. La
 * funzione deve restituire sempre un valore compreso tra min e max. Stampare tale numero nel main.
*/

#include <stdio.h>

#define MIN 1
#define MAX 20
int acquire(int min, int max);

int es3(){
	int num = acquire(MIN, MAX);

	printf("\n%d", num);
    return 0;
}

int acquire(int min, int max){
	int num;

	do{
		printf("\nInserisci numero: ");
		scanf("%d", &num);
	} while (num > max || num < min);

	return num;
}