//
// Created by Monti on 14/12/23.
//

#ifndef LEZ14_1412_ESERCIZI_H
#define LEZ14_1412_ESERCIZI_H

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int info;
	struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *aggiungiNodoInTesta(Nodo *lista);
Nodo *eliminaLista(Nodo *lista);
Nodo *cercaInLista(Nodo *lista, int num);
Nodo *aggiungiInMezzo(Nodo *nodo);
void stampaLista(Nodo *lista);
void stampaListaRicorsiva(Nodo *lista);


#endif //LEZ14_1412_ESERCIZI_H
