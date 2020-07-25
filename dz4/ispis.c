/*lista.c Definise sve funkcije za obradu liste*/
#include "dz4.h"
#include <stdio.h>
#include <stdlib.h>

/*Funkcija za ispisivanje liste*/
void pisanje(DuzinaBrzina * frst) {
	while (frst) {
		printf("Duzina deonice je: %.2lf\n", frst->duzina);
		printf("Prosecna brzina na deonici je: %.2lf\n", frst->brzina);
		frst = frst->sledeci;
	}
}