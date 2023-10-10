//
// Created by Lorenzo Montalto on 08/10/23.
//
#include <stdio.h>

int es1(){
    // Variabili input
    int a, b, c;
    // Variabili calcoli
    int calc1, calc2, calc3;

    // Inserimento input
    printf("a: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);
    printf("\nc: ");
    scanf("%d", &c);

    // Effettuo i calcoli
    calc1 = a-b+c;
    calc2 = a-b+c*a;
    calc3 = (a/b)%c;

    // Restituisco i valori dei calcoli
    printf("\na - b + c = %d", calc1);
    printf("\na - b + c * a = %d", calc2);
    printf("\n(a / b) %% c = %d", calc3);

    return 0;
}