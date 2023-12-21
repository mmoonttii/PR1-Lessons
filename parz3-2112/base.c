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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/** inclusione librerie studente **/
// inserire codice studente
/** fine inclusione librerie studente */

/** macro studente **/

#define STR_LEN 30
#define PREZZO_MIN 3.00
#define ETA_PELUCHE 0
#define ETA_VIDEOGAME 12
#define ETA_GIOCO_TAVOLO 8
#define ETA_PALLA 2
#define ETA_LIBRO 6

/** fine macro studente **/


/** === ESERCIZIO 1 (Definizioni) [4pt] ================================================================================
 * a) definire un'enumerazione TipoGiocattolo, che puo' assumere i seguenti valori: PELUCHE, VIDEOGAME, GIOCO_TAVOLO,
 * PALLA, LIBRO.
 * b) definire una struttura Giocattolo, con campi nome (stringa con 30 caratteri utili), prezzo (float),
 * eta_minima (intero) e tipo_giocattolo (enumerazione TipoGiocattolo).
 * c) definire una struttura Bambino, con campi nome (stringa con 30 caratteri utili), eta (intero)
 * e giocattolo (puntatore a Giocattolo). */

typedef enum {
	PELUCHE,
	VIDEOGAME,
	GIOCO_TAVOLO,
	PALLA,
	LIBRO
} TipoGiocattolo;

typedef struct {
	char nome[STR_LEN + 1];
	float prezzo;
	int eta_minima;
	TipoGiocattolo tipo_giocattolo;
} Giocattolo;

typedef struct {
	char nome[STR_LEN + 1];
	int eta;
	Giocattolo *giocattolo;
} Bambino;

/** prototipi docente **/
Bambino* allocaBambini( int n_bambini );                /// ESERCIZIO 2
Giocattolo* allocaGiocattoli( int n_giocattoli );       /// ESERCIZIO 3

void acquisisciBambino( Bambino* bambino );             /// ESERCIZIO 4
void acquisisciGiocattolo( Giocattolo* giocattolo );    /// ESERCIZIO 5

void babboNatale( int n_bambini, Bambino bambini[], int n_giocattoli, Giocattolo giocattoli[] );     /// ESERCIZIO 6

void stampaBambini( int n_bambini, Bambino bambini[] );  /// ESERCIZIO 7
/** fine prototipi docente **/

/** prototipi studente **/
void acquisisciTipoGiocattolo(Giocattolo *giocattolo);
int randRange(int min, int max);

/** fine prototipi studente **/

int main() {

    /** === ESERCIZIO 8 (Richiamare le subroutine) [2pt] ===============================================================
     * Richiamare in maniera opportuna le subroutine implementate negli esercizi precedenti per:
     * - acquisire da tastiera il numero di bambini e di giocattoli;
     * - allocare dinamicamente un array di elementi di tipo Bambino e un array di elementi di tipo Giocattolo;
     * - acquisire da tastiera i dati dei bambini e dei giocattoli;
     * - assegnare casualmente un giocattolo a ciascun bambino;
     * - stampare le informazioni relative ai bambini e al giocattolo, se ricevuto (nome del giocattolo e prezzo).
     * Se non è stato ricevuto un giocattolo, stampare "Carbone!". */
	int nBambini, nGiocattoli;
	Bambino *arrBambini = NULL;
	Giocattolo *arrGiocattoli = NULL;

	printf("Quanti bambini devono ricevere regali?");
	scanf("%d", &nBambini);
	printf("Quanti giocattoli ci sono?");
	scanf("%d", &nGiocattoli);

	arrBambini = allocaBambini(nBambini);
	arrGiocattoli = allocaGiocattoli(nGiocattoli);

	for (int i = 0; i < nBambini; ++i) {
		 acquisisciBambino(&arrBambini[i]);
	}

	for (int i = 0; i < nGiocattoli; ++i) {
		acquisisciGiocattolo(&arrGiocattoli[i]);
	}

	babboNatale(nBambini, arrBambini, nGiocattoli, arrGiocattoli);

	stampaBambini(nBambini, arrBambini);

	if (arrGiocattoli != NULL) {
		free(arrGiocattoli);
		arrGiocattoli = NULL;
	}
	if (arrBambini != NULL) {
		free(arrBambini);
		arrBambini = NULL;
	}
	return 0;
}


/** === ESERCIZIO 2 (Creazione di array dinamici) [3pt] ================================================================
 * Scrivere una subroutine allocaBambini che, ricevuto un valore intero n corrispondente al numero di bambini,
 * allochi dinamicamente un array di elementi di tipo Bambino, di dimensione n, e lo restituisca.
 * NB: effettuare gli opportuni controlli sulle dimensioni. */

Bambino* allocaBambini(int n_bambini) {
	Bambino *arr = NULL;

	if (n_bambini < 1) { // Mi assicuro che il numero di bambini sia valido
		printf("Numero di bambini minore di 1, riprovare: ");
		scanf("%d", &n_bambini);
	}

	arr = (Bambino *) calloc(n_bambini, sizeof(Bambino));
	if (arr == NULL) exit(-1); // Chiudo il programma se non è possibile allocare l'array

	return arr;
}

/** === ESERCIZIO 3 (Creazione di array dinamici) [3pt] ================================================================
 * Scrivere una subroutine allocaGiocattoli che, ricevuto un valore intero n corrispondente al numero di giocattoli,
 * allochi dinamicamente un array di elementi di tipo Giocattolo, di dimensione n, e lo restituisca.
 * NB: effettuare gli opportuni controlli sulle dimensioni. */

Giocattolo* allocaGiocattoli(int n_giocattoli) {
	Giocattolo *arr = NULL;

	if (n_giocattoli < 0) { // Mi assicuro che il numero di giocattolo sia valido
		printf("Numero di giocattoli minore di 0, riprovare: ");
		scanf("%d", &n_giocattoli);
	}

	arr = (Giocattolo *) calloc(n_giocattoli, sizeof(Giocattolo));
	if (arr == NULL) exit(-2); // Chiudo il programma se non è possibile allocare l'array

	return arr;
}

/** === ESERCIZIO 4 (Acquisizione dati) [2pt] ==========================================================================
 * Scrivere una subroutine acquisisciBambino che, ricevuto un puntatore a Bambino, permetta di acquisire da tastiera
 * i dati di un bambino e li assegni al bambino puntato.
 * NB: il nome di un bambino non puo' essere vuoto e l'eta' di un bambino non puo' essere inferiore a 0. */

void acquisisciBambino(Bambino* bambino){

	do {
		printf("\nInserire nome bambino: ");
		scanf(" %[^\n]30s", bambino->nome);

		// Se il nome del bambino è vuoto riporvo ad acquisire il nome
		if (strlen(bambino->nome) <= 0)
			printf("\nIl campo nome non può essere vuoto, riprovare");

	} while (strlen(bambino->nome) <= 0);

	do {
		printf("\nInserire eta bambino: ");
		scanf("%d", &bambino->eta);

		// Se l'età del bambino è minore di 0, riacquisisco il valore
		if (bambino->eta < 0){
			printf("\nEtà non può essere minore di 0, riprovare");
		}
	} while (bambino->eta < 0);
}

/** === ESERCIZIO 5 (Acquisizione dati) [2pt] ==========================================================================
 * Scrivere una subroutine acquisisciGiocattolo che, ricevuto un puntatore a Giocattolo, permetta di acquisire da
 * tastiera i dati di un giocattolo e li assegni al giocattolo puntato.
 * NB: il nome di un giocattolo non puo' essere vuoto e il prezzo di un giocattolo non puo' essere inferiore a 3 euro. */

void acquisisciGiocattolo (Giocattolo* giocattolo){

	do {
		printf("\nInserisci nome giocattolo: ");
		scanf(" %[^\n]30s", giocattolo->nome);

		// Se il nome del giocattolo è vuoto riporvo ad acquisire il nome
		if (strlen(giocattolo->nome) <= 0) {
			printf("\nIl campo nome non può essere vuoto, riprovare");
		}
	} while (strlen(giocattolo->nome) <= 0);

	do {
		printf("\nInserisci prezzo giocattolo: ");
		scanf("%f", &giocattolo->prezzo);

		// Se il prezzo del bambino è minore di 3€, riacquisisco il valore
		if (giocattolo->prezzo < PREZZO_MIN) {
			printf("\n Prezzo giocattolo non può essere minore di 3.00€, riprovare");
		}

	} while (giocattolo->prezzo < PREZZO_MIN);

	acquisisciTipoGiocattolo(giocattolo);

}

void acquisisciTipoGiocattolo(Giocattolo *giocattolo) {
	int etaMinime[] = { // L'array contiene le età minime per ogni giocattolo
			ETA_PELUCHE,
			ETA_VIDEOGAME,
			ETA_GIOCO_TAVOLO,
			ETA_PALLA,
			ETA_LIBRO
	};

	do {
		printf("\nInserisci tipo giocattolo [0 - 4]"
			   "\n\t[0] Peluche"
			   "\n\t[1] Videogame"
			   "\n\t[2] Gioco da Tavolo"
			   "\n\t[3] Palla"
			   "\n\t[4] Libro"
			   "\nInserisci: ");
		scanf("%d", &giocattolo->tipo_giocattolo);

		// Mi assicuro che il tipo di giocattolo faccia parte dell'enumerazione
		if (giocattolo->tipo_giocattolo < PELUCHE || giocattolo->tipo_giocattolo > LIBRO){
			printf("\nTipo di giocattolo non valido, riprovare");
		}
	} while (giocattolo->tipo_giocattolo < PELUCHE || giocattolo->tipo_giocattolo > LIBRO);

	// L'età minima del giocattolo è l'eta contenita nella posizione tipo_giocattolo dell'array delle eta minime
	giocattolo->eta_minima = etaMinime[giocattolo->tipo_giocattolo];

}

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

void babboNatale(int n_bambini, Bambino bambini[], int n_giocattoli, Giocattolo giocattoli[]){

	bool flag;


	for (int i = 0; i < n_bambini; ++i) { // Per ogni bambino
		for (int j = 0; j < n_giocattoli; ++j) {
			if (bambini[i].eta >= giocattoli[j].eta_minima) {
				flag = true;
			} else flag = false;
		}

		do {
			bambini[i].giocattolo = &giocattoli[randRange(0, n_giocattoli)];
			flag = false;

			if (bambini[i].giocattolo->eta_minima > bambini[i].eta) flag = true;
		} while (flag);
	}


}

int randRange(int min, int max){
	int result;
	result = min + rand() % (max - min + 1);
	return result;
}

/** === ESERCIZIO 7 (Stampa informazioni) [6pt] ========================================================================
 * Scrivere una subroutine stampaBambini che, ricevuti in ingresso un valore intero n_bambini e un array di elementi
 * di tipo Bambino, stampi a video le informazioni relative ai bambini e al giocattolo, se ricevuto (nome del giocattolo
 * e prezzo). Nel caso in cui il bambino non abbia ricevuto un giocattolo, deve essere stampato "Carbone!". */

void stampaBambini( int n_bambini, Bambino bambini[] ) {
	char tipiGiocattoli[LIBRO + 1][STR_LEN] = {
			"Peluche",
			"Videogame",
			"Gioco da Tavolo",
			"Palla",
			"Libro"
	};

	for (int i = 0; i < n_bambini; ++i) {
		printf("===BAMBINO %d===\n"
			   "\tNome: %s\n"
			   "\tEta: %d\n",
			   i, bambini[i].nome, bambini[i].eta);

		if (bambini[i].giocattolo != NULL){
			printf("\t==Giocattolo:\n"
				   "\t\tNome: %s\n"
				   "\t\tPrezzo: %.2f\n"
				   "\t\tTipo giocattolo: %s\n",
				   bambini[i].giocattolo->nome,
				   bambini[i].giocattolo->prezzo,
				   tipiGiocattoli[bambini[i].giocattolo->tipo_giocattolo]);
		} else {
			printf("Carbone!\n");
		}
	}


}