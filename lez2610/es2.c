/* Generare un carattere ASCII casuale (tra 1 e 255 estremi inclusi), stamparlo a
 * video e verificare se esso rappresenti una lettera mediante un costrutto IF
 *
 * Nel caso lo sia, utilizzare un costrutto SWITCH per determinare se essa sia una
 * vocale o una consonante stampando poi un messaggio per comunicarlo all'utente.
 * In caso contrario stampare un messaggio relativo.
 *
 * Tramite un costrutto IF verificare se la lettera sia maiuscola o minuscola,
 * stampando un messaggio per comunicarlo all’utente. In caso contrario stampare
 * un messaggio relativo.
 *
 * Modificare il programma per chiedere all’utente se vuole generare casualmente
 * il carattere oppure inserirlo in input
 *
 * Modificare il programma per gestire il caso in cui l’utente inserisca un input non
 * valido, permettendo di ripetere la scelta.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CHAR_MAX 255

int es2 (){
    char carattere;
    int choice;

    srand(time(NULL));

    do {
        printf("Inserire [0] per generare randomicamente il carattere");
        printf("\nInserire [1] per inserire manualmente il carattere: ");
        scanf("%d", &choice);
    } while (choice != 0 && choice != 1);

    if (choice == 0){

        carattere = 1 + rand() % CHAR_MAX;
        printf("\nCarattere generato: %c", carattere);

    } else if (choice == 1){

        printf("\nInserire carattere: ");
        scanf(" %c", &carattere);
    }


    if ((carattere > 65 && carattere < 90) || (carattere > 97 && carattere < 122)){
        switch (carattere) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                printf("\nIl carattere %c è una vocale", carattere);
            default:
                printf("\nIl carattere %c è una consonante", carattere);
        }
    }

    if (carattere > 65 && carattere < 90){
        printf("\nIl carattere è maiuscolo");
    } else if (carattere > 97 && carattere < 122){
        printf("\nIl carattere è minuscolo");
    }



    return 0;
}