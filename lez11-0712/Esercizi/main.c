
#include "es14.h"

int main(){
	Studente studenti[DIM];
	Esame esame;

	popolaArray(DIM, studenti);
	acquisisciEsame(DIM, &esame, studenti);
	checkStudente(DIM, studenti);
	printf("Studenti positivi: %d", contaPositivi(DIM, &esame));
	topStudenti(DIM, studenti, &esame);
	return 0;
}