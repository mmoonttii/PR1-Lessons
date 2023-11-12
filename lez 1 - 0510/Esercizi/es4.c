#include <stdio.h>

int es4(){
    int gatti, gattiPerFila, file, resto;

    printf("Numero gatti: ");
    scanf("%d", &gatti);
    printf("\nGatti per fila: ");
    scanf("%d", &gattiPerFila);

    file = gatti / gattiPerFila;
    resto = gatti % gattiPerFila;

    printf("file: %d, resto: %d", file, resto);

    return 0;
}