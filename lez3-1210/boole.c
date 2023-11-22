#include <stdio.h>
#include <stdbool.h>

int boole(){

    int voto = 18;
    bool passato = voto >= 18;
    /*
     * if (18 <= voto <= 20) {
     *  printf("Sufficiente");
     * }
     * Quest'espressione è semanticamente errata
     */

    if (passato){
        printf("Sufficiente");
    }

    if (voto >= 18 && voto <= 20){ // Possiamo usare AND (&&) per valutare contemporaneamente
        printf("Sufficiente");     // le due variabili
    } else {
        printf("Altro");
    }

    if (voto >= 18 || voto <= 20){ // Possiamo usare OR (||) per valutare contemporaneamente
            printf("Sufficiente"); // le due variabili
        } else {
            printf("Altro");
        }

    return 0;
}