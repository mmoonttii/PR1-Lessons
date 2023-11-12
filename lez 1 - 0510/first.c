#include <stdio.h> // Direttiva di preprocessing

int nonmain() { /* Entry point del programma -- le tonde identificano un sottoprogramma
                 * int indica che il blocco main resituisce un intero */
    printf("Hello, World!\n"); // printf è un'istruzione
    return 0; /* Exit point -- ogni istruzione deve terminare con un ;
               * -- si usa 0 per indicare che il programma ha terminato senza errore */
}             // le graffe identificano un "blocco", in questo caso il blocco main
