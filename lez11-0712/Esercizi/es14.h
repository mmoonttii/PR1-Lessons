//
// Created by Monti on 14/12/23.
//

#ifndef LEZ11_0712_ES14_H
#define LEZ11_0712_ES14_H


#include <stdio.h>
#include <string.h>

#define LEN 30
#define DIM 5

typedef struct {
	int giorno;
	int mese;
	int anno;
} Data;

typedef struct {
	char nome[LEN + 1];
	char cognome[LEN + 1];
	Data dataNascita;
} Studente;

typedef struct {
	Data dataEsame;
	char luogoEsame[LEN + 1];
	char nomeProf[LEN + 1];
	int voti[DIM];
} Esame;

Data acquisisciData();
Studente acquisisciStudente();
void popolaArray(int dim, Studente studenti[]);
void acquisisciEsame(int dim, Esame *esame, Studente studenti[]);
void checkStudente(int dim, Studente studenti[]);
int contaPositivi(int dim, Esame *esame);
void topStudenti(int dim, Studente studenti[], Esame *esame);


#endif //LEZ11_0712_ES14_H
