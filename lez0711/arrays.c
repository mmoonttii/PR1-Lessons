// Gli ARRAY sono un tipo di dato non primitico che permette di aggregare dati semanticamente affini
// Specificato: tipo nomeVettore[dimensione]

// int matricole[150];
// float votoEsame[150];

// Lo spazio viene allocato linearmente (una cella dopo l'altra) e staticamente (noto a compile-time, quindi non posso usare una variabile)
// L'accesso non è sequenziale, ma si può accedere a qualunque indice utilizzando le quadre [indice]

// int n;
// int array[n];
// Questa scrittura è sintaticcamente valida, ma in C90 è un undefined behaviour

int arrays(){

	int voti[20];
	int i;

	// Init array: Modo 1
	for (i = 0; i < 20; i++){
		voti[i] = 0;
	}

	// Init array: in dichiarazione
	int values[5] = {22, 24, 14, 28, 30}; // Se inserisco più elementi della capienza dell'array vengono presi i primi n valori
	// Se inserisco meno valori dei posti disponibili, quelli non inizializzati sono impostati a 0
	int marks[] = {1, 2, 3}; // Non impostando la dimensione l'array viene definito con i posti dei valori dichiarati

	return 0;
}