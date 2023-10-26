#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

int main() {

    //dichiarazione variabili
    float a, b, ris = 0;        //variabili operazioni
    float aux;                  //variabile d'appoggio
    int numCifreDec;            //numero di cifre decimali nella generazione casuale
    char op;                    //sceglie l'operazione da effettuare
    bool check = true;          //controlla che il flusso del codice prosegua in maniera corretta
    bool random;                //generazione casuale dell'input

    //inizializzazione seed generazione casuale
    srand(time(NULL));

    //acquisisco un booleano per decidere se generare casualmente i numeri o prenderli dall'utente
    printf("Inserisci [0] per inserire i numeri manualmente o [1] per generarli casualmente nel range 1-10: ");
    scanf("%f", &aux);
    random = aux == 0 ? false : true;
    //NOTA: non esiste un segnaposto per un booleano, quindi devo acquisire prima una variabile d'appoggio e poi assegnare il booleano

    if(random) {
        //generazione casuale
        a = MIN + rand()%(MAX-MIN+1);
        b = MIN + rand()%(MAX-MIN+1);
        printf("I valori estratti sono: %f e %f", a, b);
    } else {
        //inserimento valori
        printf("Inserisci il primo valore: ");
        scanf("%f", &a);
        printf("Inserisci il secondo valore: ");
        scanf("%f", &b);
    }

    //check per vedere se entrambi sono pari (intanto per ripassare AND, OR e cast)
    //NOTA BENE: il resto della divisione lo possiamo calcolare solo con numeri interi, quindi dobbiamo effettuare un cast esplicito
    if((int)a % 2 == 0 && (int)b % 2 == 0)
        printf("\nLa parte intera di entrambi i numeri è pari!\n");
    if((int)a % 2 != 0 || (int)b % 2 != 0)
        printf("\nLa parte intera di almeno uno dei numeri è dispari!\n");

    //loop operazioni
    do {

        //reset del valore (nel caso si stia ripetendo il ciclo una seconda volta)
        check = true;

        //inserimento operazione
        printf("\nChe operazione vuoi fare?"
               "\n[+ somma, - sottrazione, * moltiplicazione, / divisione]"
               "\n[^ potenza, s radice quadrata (del primo numero)]"
               "\n[r numero casuale intero, g numero casuale decimale]"
               "\nInserisci operazione: ");
        scanf(" %c", &op);  //lo spazio davanti di %c ci permette di pulire l'input buffer

        //esecuzione delle operazioni
        switch (op) {

            case '+':                   //somma
                ris = a + b;
                break;

            case '-':                   //sottrazione
                ris = a - b;
                break;

            case '*':                   //moltiplicazione
                ris = a * b;
                break;

            case '/':                   //divisione
                while (b == 0) {
                    printf("\nNon puoi effettuare una divisione per zero!"
                           "\nInserisci un nuovo valore per [b]: ");
                    scanf("%f", &b);
                }
                ris = a / b;
                break;

            case '^':                   //potenza
                ris = pow(a, b);
                break;

            case 's':                   //radice
                ris = sqrt(a);
                break;

            case 'r':
                //se a è maggiore di b scambiamo i due valori
                if (b < a) {
                    aux = a;    //backup di a
                    a = b;      //salviamo b in a
                    b = aux;    //ripristiniamo il backup di a
                }
                ris = a + rand() % (int) (b - a + 1); //a => min, b => max
                break;

            case 'g':
                //decisione numero cifre decimali
                printf("\nInserisci il numero di cifre decimali che vuoi: ");
                scanf("%d", &numCifreDec);
                numCifreDec = abs( numCifreDec);     //il numero di cifre decimali deve essere un numero non negativo

                //se a è maggiore di b scambiamo i due valori
                if (b < a) {
                    aux = a;    //backup di a
                    a = b;      //salviamo b in a
                    b = aux;    //ripristiniamo il backup di a
                }

                //generazione casuale
                a *= pow(10, numCifreDec);          //moltiplico gli estremi per una potenza di 10
                b *= pow(10, numCifreDec);
                ris = a + rand() % (int) (b - a + 1);    //a => min, b => max
                ris /= pow(10, numCifreDec);        //divido il numero casuale per la stessa potenza in modo da ottenere i decimali
                break;

            default:                    //errore
                check = false;
                printf("\nL'operazione inserita non è valida!");
                break;
        }

    } while(!check); //se il controllo è andato male allora richiedo l'operazione dall'utente (attenzione alla negazione)

    printf("\nIl risultato è %f", ris);

    return 0;
}
