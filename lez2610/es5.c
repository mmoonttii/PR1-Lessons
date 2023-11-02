//
//  es5.c
//  esercitazione pt2
//
//	Stampare i primi n numeri della serie di Fibonacci, con n scelto dall'utente.
//	La serie di Fibonacci inizia con 1, 1 e ogni numero successivo è dato dalla
//	somma dei due precedenti:
//	1, 1, 2, 3, 5, 8, 13, 21
//	F(i) = F(i-1)+F(i-2) se i>=3
//	F(1) = F(2) = 1 altrimenti
//
//  Created by Monti on 01/11/23.


#include <stdio.h>

int es5(){
	int counter = 0, numbers, n, n1 = 1, n2 = 0;
	
	printf("Quanti n di fibionacci vuoi stampare? ");
	scanf("%d", &numbers);
	
	while (counter < numbers) {
		n = n1 + n2;
		
		printf("%d\n", n);
		
		n1 = n2;
		n2 = n;
		counter++;
	}
	
	return 0;
}
