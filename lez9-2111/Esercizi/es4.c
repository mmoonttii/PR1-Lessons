/*
 * Scrivere una funzione calcolaGiorno(giorno, mese, anno) che restituisca il giorno dell'anno (un numero
 * compreso tra 1 e 366) specificato dai tre argomenti. La funzione deve verificare se l'anno è bisestile o
 * meno, ed effettuare il calcolo di conseguenza. Nel main, impostare una data e stampare in output il
 * giorno dell'anno.
 * • NB: un anno è bisestile se è divisibile per 400; altrimenti se è divisibile per 4 ma non per 100.
 * • Modificare, poi, l'esercizio per rendere il calcolo dell'anno bisestile una funzione.
 */

#include <stdio.h>
#include <stdbool.h>

#define DIC 12
#define NOV 11
#define OTT 10
#define SET 9
#define AGO 8
#define LUG 7
#define GIU 6
#define MAG 5
#define APR 4
#define MAR 3
#define FEB 2
#define GEN 1


int calcolaGiorno (int day, int month, int year);
bool bisestile(int year);

int es4(){
	int day,
	    month,
	    year,
	    giorno;

	printf("Inserisci giorno: ");
	scanf("%d", &day);
	printf("Inserisci mese: ");
	scanf("%d", &month);
	printf("Inserisci anno: ");
	scanf("%d", &year);

	giorno = calcolaGiorno(day, month, year);

	printf("Il %d.%d.%d è il %d° giorno dell'anno", day, month, year, giorno);
    return 0;
}

int calcolaGiorno (int day, int month, int year){
	int giorno = 0, febDays = 28;

	if (bisestile(year)){
		febDays = 29;
	}
	switch (month) {
		case DIC: giorno += 30;
		case NOV: giorno += 31;
		case OTT: giorno += 30;
		case SET: giorno += 31;
		case AGO: giorno += 31;
		case LUG: giorno += 30;
		case GIU: giorno += 31;
		case MAG: giorno += 30;
		case APR: giorno += 31;
		case MAR: giorno += febDays;
		case FEB: giorno += 31;
		case GEN:
			break;
	}

	giorno += day;

	return giorno;
}

bool bisestile(int year){
	bool bis;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		bis = true;
	} else {
		bis = false;
	}
	return bis;
}
