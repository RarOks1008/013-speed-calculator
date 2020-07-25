/*lista.c Definise sve funkcije za obradu liste*/
#include "dz4.h"
#include <stdio.h>
#include <stdlib.h>

/*Funkcija za unos liste*/
DuzinaBrzina *ucitavanje(int n) {
	DuzinaBrzina *prvi = NULL, *poslednji = NULL;
	int i;
	for (i = 0; i < n; i++) {
		DuzinaBrzina *novi = malloc(sizeof(DuzinaBrzina));
		scanf("%lf%lf", &novi->duzina, &novi->brzina);
		novi->sledeci = NULL;
		if (!prvi)
			prvi = novi;
		else
			poslednji->sledeci = novi;
		poslednji = novi;
	}
	return prvi;
}