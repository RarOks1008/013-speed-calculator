/*Glavni program*/
#include "dz4.h"
#include <stdio.h>

void main() {
	DuzinaBrzina * frst = NULL;
	int zavrsetak = 0, biranje, k, l;
	double duzina, brzina, T;
	while (!zavrsetak) {
		printf("\n1. Ubacivanje nove deonice na pocetak liste\n"
			"2. Ubacivanje nove deonice na kraj liste\n"
			"3. Izbacivanje jedne od deonica\n"
			"4. Ispisivanje svih deonica i srednjih brzina\n"
			"5. Brisanje svih deonica i brzina\n"
			"6. Unos svih deonica i brzina i njihova obrada\n"
			"0. Kraj rada\n\n"
			"Izaberite jednu od opcija: ");
		scanf("%d", &biranje);
		switch (biranje) {
		case 1: case 2:
			printf("Unesite duzinu deonice i srednju brzinu respektivno: ");
			scanf("%lf%lf", &duzina, &brzina);
			switch (biranje) {
			case 1:
				frst = na_prvi(frst, duzina, brzina); break;
			case 2:
				frst = na_zadnji(frst, duzina, brzina); break;
			}
			break;
		case 3:
			printf("Unesite redni broj deonice koju zelite da izbacite: ");
			scanf("%d", &k);
			frst = izbacivanje(frst, k); break;
		case 4:
			pisanje(frst);
			putchar('\n'); break;
		case 5:
			brisanje(frst);
			frst = NULL; break;
		case 6:
			printf("Duzina liste je: ");
			scanf("%d", &l);
			printf("Duzina deonica i brzina: ");
			brisanje(frst);
			frst = ucitavanje(l);
			printf("Vremenski period po deonici je (u minutima): ");
			scanf("%lf", &T);
			obrada(frst, T);
			break;
		case 0:
			zavrsetak = 1; break;
		default:
			printf("POGRESAN IZBOR!!! Pokusajte ponovo...\a\n"); break;
		}
	}
}