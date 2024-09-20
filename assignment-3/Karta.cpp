#include "Karta.h"

int Karta::brojac = 1;

Karta::Karta() : identifikator(brojac++) {}

ostream& operator<<(ostream& os, const Karta& karta) {
	os << "Karta: " << karta.identifikator;
	
	return os;
}