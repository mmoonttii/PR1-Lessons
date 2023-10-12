#include <stdio.h>

int ifelse(){
    // Acquisizione valori
    int voto;
    int cfu = 0;
    printf("Inserire voto di PR1: ");
    scanf("%d", &voto);

    // Verfico il voto inserito
    if (voto >= 18){
        /* È convenzione avere la parte di codice maggiore nel branch if,
         * oppure la condizione positiva */
        printf("Ho finalmente superato PR1!");
        cfu += 12;

        if (voto > 30){
            // Gli if possono anche essere concatenati o non avere un else
            printf("Ho preso 30 e lode");
        }
    } else
        // Se l'istruzione è solo di una riga possono essere omesse le graffe
        printf("Non mi libererò mai di PR1 :(");

    return 0;
}