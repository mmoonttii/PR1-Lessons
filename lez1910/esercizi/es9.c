/* Scrivere un programma per calcolare se un anno è bisestile
 * oppure no. In particolare, il programma deve
 * Richiedere all'utente l'anno
 * Verificare che l'anno sia maggiore di zero
 * Nel caso in cui non lo sia, stampare un messaggio d'errore
 * Diversamente, effettuare la verifica secondo il seguente
 * schema: un anno è bisestile se è divisibile per 400, oppure se è
 * divisibile per 4 ma non per 100.
 * In output, dire se l'anno è bisestile oppure no
 */
#include <stdio.h>

int es9(){
    // Inizializzazione e acquisizione variabli
    int year;

    printf("Inserire anno: ");
    scanf("%d", &year);

    // Verifica semantica anno
    if (year <= 0){
        printf("\nL'anno inserito è minore di 0");
        return 1;
    } else if (year % 4 == 0){
        printf("Anno bisestile");
    } else {
        printf("Anno NON bisestile");
    }
    return 0;
}