#include <stdio.h>

int cast() {
    int a, b, c;

    a = 4;
    b = 5;
    c = 2;

    float media = (a+b+c)/3; /* In questo caso l'espressione viene valutata come se fosse intera,
                              * quindi viene troncata prima di essere assegnata alla variabile
                              * CAST IMPLICITO */
    printf("%f", media);

    float media2 = (float)(a+b+c)/3; /* In questo caso la nostra espressione viene ha una discordanza di tipi,
                                      * in questi casi l'espressione viene valutata con il tipo con la precisione
                                      * più elevata CAST ESPLICITO */
    printf("\n%f", media2);
    return 0;
}
