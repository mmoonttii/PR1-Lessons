#include <stdio.h>

int forjump() {
    int i, j;

    for (i = 0; i < 10; i++) { // Inizializzazione; condizione; incremento
        printf("%d\n", i);         // Da 0 a 9
    }

    for (j = 10; j > 0; j--){ // Da 10 a 1
        printf("%d\n", j);
    }

    /* for (int k = 0; k < 10; k += 2){ // Da C99 in poi è possibile dichiarare la variabile nello scope del for
        printf("%d\n", k);  // Da 0 a 8, solo i pari
    }
     */
    // NB Il controllo della condizione viene effettuato prima dell'esecuzione

    /* Il ciclo for può essere interrotto da un break (uscendo da tutto il ciclo)
     * Oppure può servire saltare solo l'iterazione attuale usando la keyword continue
     * SONO OPERAZIONI DA EVITARE
     */
    return 0;
}
