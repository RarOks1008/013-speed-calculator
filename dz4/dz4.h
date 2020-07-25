#pragma once

#define TRUE 1
#define FALSE 0

typedef struct duzinabrzina {
	double duzina, brzina;
	struct duzinabrzina *sledeci;
} DuzinaBrzina;
