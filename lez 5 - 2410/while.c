#include <stdio.h>

int ilwhile() {

    int voto, numStudenti, counter = 0;
    float media = 0;

    printf("Inserisci num studenti: ");
    scanf("%d", &numStudenti);

    while (counter < numStudenti) {
        printf("Inserisci voto di uno studente");
        scanf("%d", &voto);

        media += (float)voto;

        counter++;
    }

    media /= (float)numStudenti;
    printf("La media è %f", media);
    return 0;
}
