#include <stdio.h>

int es2(){
    // Dichiarazione variabili
    int a, b;
    int aux;

    // Acquisizione valori
    printf("Inserire valore a: ");
    scanf("%d", &a);
    printf("\nInserire valore b: ");
    scanf("%d", &b);

    // Stampo i valori delle variabili prima
    printf("\na: %d, b: %d", a, b);

    // Utilizzando la var c di appoggio scambio i valori delle var
    aux = a;
    a = b;
    b = aux;

    // Stampo i valori dopo
    printf("\na: %d, b: %d", a, b);
    return 0;
}
