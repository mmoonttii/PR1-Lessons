//
// Created by Lorenzo Montalto on 08/10/23.
//
#include <stdio.h>

int es1(){
    int a, b, c; // Dichiarazione variabili

    // Acquisisco i valori delle variabili
    printf("Valore a: ");
    scanf("%d", &a);
    printf("\n Valore b: ");
    scanf("%d", &b);
    printf("\n Valore c: ");
    scanf("%d", &c);

    // Restituisco i valori dei calcoli
    printf("\na - b + c = %d", (a-b+c));
    printf("\na - b + c * a = %d", (a-b+c*a));
    printf("\n(a / b) %% c = %d", ((a/b)%c));

    return 0;
}