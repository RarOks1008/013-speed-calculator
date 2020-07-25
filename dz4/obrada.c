/*lista.c Definise sve funkcije za obradu liste*/
#include "dz4.h"
#include <stdio.h>
#include <stdlib.h>

/*Funkcija za brisanje liste*/
void brisanje(DuzinaBrzina * frst) {
	while (frst) {
		DuzinaBrzina *stari = frst;
		frst = frst->sledeci;
		free(stari);
	}
}

/*Funkcija za ubacivanje jednog elementa na pocetak liste*/
DuzinaBrzina *na_prvi(DuzinaBrzina * frst, double m, double n) {
	DuzinaBrzina *noviel = malloc(sizeof(DuzinaBrzina));
	noviel->duzina = m;
	noviel->brzina = n;
	noviel->sledeci = frst;
	return noviel;
}

/*Funkcija za ubacivanje jednog elementa na kraj liste*/
DuzinaBrzina *na_zadnji(DuzinaBrzina * frst, double m, double n) {
	DuzinaBrzina *noviel = malloc(sizeof(DuzinaBrzina));
	noviel->duzina = m;
	noviel->brzina = n;
	noviel->sledeci = NULL;
	if (!frst) return noviel;
	else {
		DuzinaBrzina *tekuci = frst;
		while (tekuci->sledeci)
			tekuci = tekuci->sledeci;
		tekuci->sledeci = noviel;
		return frst;
	}
}

/*Funkcija za izbacivanje proizvodljnog elementa iz liste*/
DuzinaBrzina *izbacivanje(DuzinaBrzina * frst, int b) {
	DuzinaBrzina *tekuci = frst, *prethodni = NULL;
	int p = 0;
	if (b != p) {
		p++;
		prethodni = tekuci;
		tekuci = tekuci->sledeci;
	}
	else {
		DuzinaBrzina *stari = tekuci;
		tekuci = tekuci->sledeci;
		if (!prethodni)
			frst = tekuci;
		else prethodni->sledeci = tekuci;
		free(stari);
	}
	return frst;
}
/*Funkcija za obradu programa*/
DuzinaBrzina *obrada(DuzinaBrzina * frst, double t) {
	DuzinaBrzina *tekuci = frst;
	double temp = 0;
	while (tekuci != NULL)
		if (((tekuci->duzina) / (tekuci->brzina) * 60) <= t)
			tekuci = tekuci->sledeci;
		else {
			temp = tekuci->duzina - (t / 60)*tekuci->brzina;
			tekuci->duzina = (t / 60)*tekuci->brzina;
			if (tekuci->sledeci == NULL) {
				DuzinaBrzina *noviel, *prethodni = NULL;
				prethodni = tekuci;
				noviel = malloc(sizeof(DuzinaBrzina));
				noviel->duzina = temp;
				noviel->brzina = prethodni->brzina;
				tekuci->sledeci = noviel;
				noviel->sledeci = NULL;
				frst = noviel;
			}
			else {
				if (((temp + tekuci->sledeci->duzina) / tekuci->sledeci->brzina) < (t / 60)) {
					tekuci->sledeci->duzina = (temp + tekuci->sledeci->duzina);
					tekuci = tekuci->sledeci;
				}
				else {
					DuzinaBrzina *noviel, *prethodni = NULL;
					prethodni = tekuci;
					tekuci = tekuci->sledeci;
					noviel = malloc(sizeof(DuzinaBrzina));
					noviel->duzina = temp;
					noviel->brzina = prethodni->brzina;
					noviel->sledeci = tekuci;
					if (!prethodni) frst = noviel;
					else prethodni->sledeci = noviel;
				}
			}
		}
		return frst;
}
