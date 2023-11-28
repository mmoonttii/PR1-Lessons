/* Scrivere un programma che stampi il calendario di un mese. L'utente deve
 * specificare il numero di giorni nel mese e il giorno della settimana in cui
 * questo comincia (0: lunedi', 6: domenica).
 */

#include <stdio.h>

void printCal(int start, int month);

int main(){
    int startDay,
        monthDays;

    printf("Inserisci il giorno in cui inizia il mese:"
           "\n[0] Lunedì"
           "\n[1] Martedì"
           "\n[2] Mercoledì"
           "\n[3] Giovedì"
           "\n[4] Venerdì"
           "\n[5] Sabato"
           "\n[6] Domenica");
    scanf("%d", &startDay);

    printf("\nInserisci quanti giorni in questo mese");
    scanf("%d", &monthDays);


    return 0;
}

void printCal(int start, int month){

    for (int i = 0; i < start; ++i) {
        putchar('\t');
    }
    for (int i = 1; i < month; ++i) {
        printf("%d\t", i);
        if (i % start)
        {}
    }

}