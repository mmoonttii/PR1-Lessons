#include <stdio.h>

void doppio (int *num);

int pointers(){
//	int *puntatore, variabile; // Puntatore è un pointer perchè ha la *, variabile una variable perchè non ha *
//	float *f1, *f2; // Sono entrambi puntatori a float
	int num = 25;

	// I pointer vanno SEMPRE inizializzati, la macro NULL, ci aiuta in questo
	int *pointer = NULL;

	// Per assegnare a *pointer il valore dell'indirizzo di num usaimo l'operatore &
	pointer = &num;

	printf("Indirizzo dalla variabile %p", &num);
	printf("\nIl pointer %p", pointer);

	printf("\nNumero vale: %d", num);

	*pointer = 8; // L'operatore * permette di accedere alla cella indicata dal pointer

	doppio(pointer); // doppio(&num);

	printf("\nValroe di numero %d", num);



    return 0;
}

void doppio (int *num){
	(*num) = 2 * (*num);
}