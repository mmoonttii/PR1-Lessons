/** === DESCRIZIONE ====================================================================================================
 * CONTESTO: Babbo Natale vi ha chiesto di scrivere un programma per gestire la distribuzione dei giocattoli ai bambini
 * per il prossimo Natale. Il programma deve permettere di acquisire da tastiera i dati di un insieme di bambini e di
 * un insieme di giocattoli, e di assegnare casualmente un giocattolo a ciascun bambino. Il programma deve inoltre
 * stampare le informazioni relative ai bambini e al giocattolo, se ricevuto.
 *
 * SVOLGIMENTO: Il compito consiste nell'implementazione di alcune subroutine, di cui sono stati forniti i prototipi,
 * e della loro opportuna invocazione nel main. Leggere attentamente il testo degli esercizi.
 *
 * CONSIGLI: Risolvere gli esercizi in ordine di numerazione, ma non rimanere bloccati su un esercizio troppo a lungo,
 * dal momento in cui l'ordine degli esercizi non rappresenta una difficoltà crescente.
 *
 * VALUTAZIONE: Gli esercizi hanno un punteggio. Se svolti tutti correttamente si raggiunge il 30.
 * Sono valutati, inoltre, i seguenti aspetti: stile, organizzazione del codice, best practices e commenti.
 *
 * NOTA BENE: È severamente vietato modificare i prototipi forniti.
 * Rispettare, inoltre, i campi richiesti per le strutture e i valori possibili per l'enumerazione.
 */

#include <stdio.h>

/** inclusione librerie studente **/
// inserire codice studente
/** fine inclusione librerie studente */

/** macro studente **/
// inserire macro studente
/** fine macro studente **/

/** prototipi docente **/
Bambino* allocaBambini( int n_bambini );                /// ESERCIZIO 2
Giocattolo* allocaGiocattoli( int n_giocattoli );       /// ESERCIZIO 3

void acquisisciBambino( Bambino* bambino );             /// ESERCIZIO 4
void acquisisciGiocattolo( Giocattolo* giocattolo );    /// ESERCIZIO 5

void babboNatale( int n_bambini, Bambino bambini[], int n_giocattoli, Giocattolo giocattoli[] );     /// ESERCIZIO 6

void stampaBambini( int n_bambini, Bambino bambini[] );  /// ESERCIZIO 7
/** fine prototipi docente **/

/** prototipi studente **/
//sostituire il commento con i propri prototipi
/** fine prototipi studente **/

/** === ESERCIZIO 1 (Definizioni) [4pt] ================================================================================
 * a) definire un'enumerazione TipoGiocattolo, che puo' assumere i seguenti valori: PELUCHE, VIDEOGAME, GIOCO_TAVOLO,
 * PALLA, LIBRO.
 * b) definire una struttura Giocattolo, con campi nome (stringa con 30 caratteri utili), prezzo (float),
 * eta_minima (intero) e tipo_giocattolo (enumerazione TipoGiocattolo).
 * c) definire una struttura Bambino, con campi nome (stringa con 30 caratteri utili), eta (intero)
 * e giocattolo (puntatore a Giocattolo). */

int main() {

    /** === ESERCIZIO 8 (Richiamare le subroutine) [2pt] ===============================================================
     * Richiamare in maniera opportuna le subroutine implementate negli esercizi precedenti per:
     * - acquisire da tastiera il numero di bambini e di giocattoli;
     * - allocare dinamicamente un array di elementi di tipo Bambino e un array di elementi di tipo Giocattolo;
     * - acquisire da tastiera i dati dei bambini e dei giocattoli;
     * - assegnare casualmente un giocattolo a ciascun bambino;
     * - stampare le informazioni relative ai bambini e al giocattolo, se ricevuto (nome del giocattolo e prezzo).
     * Se non è stato ricevuto un giocattolo, stampare "Carbone!". */

    return 0;
}


/** === ESERCIZIO 2 (Creazione di array dinamici) [3pt] ================================================================
 * Scrivere una subroutine allocaBambini che, ricevuto un valore intero n corrispondente al numero di bambini,
 * allochi dinamicamente un array di elementi di tipo Bambino, di dimensione n, e lo restituisca.
 * NB: effettuare gli opportuni controlli sulle dimensioni. */


/** === ESERCIZIO 3 (Creazione di array dinamici) [3pt] ================================================================
 * Scrivere una subroutine allocaGiocattoli che, ricevuto un valore intero n corrispondente al numero di giocattoli,
 * allochi dinamicamente un array di elementi di tipo Giocattolo, di dimensione n, e lo restituisca.
 * NB: effettuare gli opportuni controlli sulle dimensioni. */


/** === ESERCIZIO 4 (Acquisizione dati) [2pt] ==========================================================================
 * Scrivere una subroutine acquisisciBambino che, ricevuto un puntatore a Bambino, permetta di acquisire da tastiera
 * i dati di un bambino e li assegni al bambino puntato.
 * NB: il nome di un bambino non puo' essere vuoto e l'eta' di un bambino non puo' essere inferiore a 0. */


/** === ESERCIZIO 5 (Acquisizione dati) [2pt] ==========================================================================
 * Scrivere una subroutine acquisisciGiocattolo che, ricevuto un puntatore a Giocattolo, permetta di acquisire da
 * tastiera i dati di un giocattolo e li assegni al giocattolo puntato.
 * NB: il nome di un giocattolo non puo' essere vuoto e il prezzo di un giocattolo non puo' essere inferiore a 3 euro. */


/** === ESERCIZIO 6 (Distribuzione giocattoli) [8pt] ===================================================================
 * Scrivere una subroutine babboNatale che, ricevuti in ingresso un valore intero n_bambini, un array di elementi di tipo
 * Bambino, un valore intero n_giocattoli, un array di elementi di tipo Giocattolo, selezioni un giocattolo casuale
 * per ogni bambino. Nel caso in cui il giocattolo non sia adatto al bambino, il bambino rimarrà senza giocattolo.
 * Tenere anche conto che:
 * - i giocattoli devono essere assegnati casualmente e lo stesso giocattolo puo' essere assegnato a piu' bambini;
 * - un bambino non puo' ricevere un giocattolo non adatto alla sua eta';
 * - un bambino non puo' ricevere piu' di un giocattolo;
 * - l'eta' minima di un PELUCHE e' 0, di un VIDEOGAME e' 12, di un GIOCO_TAVOLO e' 8, di una PALLA e' 2
 * e di un LIBRO e' 6;
 * OPZIONALE: realizzare una subroutine verificaEta che, ricevuti un Giocattolo e un Bambino, verifichi
 * se il giocattolo e' adatto ad un bambino, tenendo conto dell'eta' minima del giocattolo e dell'eta' del bambino. */


/** === ESERCIZIO 7 (Stampa informazioni) [6pt] ========================================================================
 * Scrivere una subroutine stampaBambini che, ricevuti in ingresso un valore intero n_bambini e un array di elementi
 * di tipo Bambino, stampi a video le informazioni relative ai bambini e al giocattolo, se ricevuto (nome del giocattolo
 * e prezzo). Nel caso in cui il bambino non abbia ricevuto un giocattolo, deve essere stampato "Carbone!". */