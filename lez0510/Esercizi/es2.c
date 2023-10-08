#include <stdio.h>

int es2(){
    int a, b,c; // Dichiarazione variabili

    // Acquisizione valori
    printf("Inserire valore a: ");
    scanf("%d", &a);
    printf("\nInserire valore b: ");
    scanf("%d", &b);

    // Stampo i valori delle variabili prima
    printf("\na: %d, b: %d", a, b);

    // Utilizzando la var c di appoggio scambio i valori delle var
    c = a;
    a = b;
    b = c;

    // Stampo i valori dopo
    printf("\na: %d, b: %d", a, b);
    return 0;
}
