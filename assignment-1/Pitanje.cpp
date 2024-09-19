#define _CRT_SECURE_NO_WARNINGS 1
#include "Pitanje.h"

Pitanje::Pitanje(const char* tekstPitanja) : odgovor() {
	tekst = new char[strlen(tekstPitanja) + 1];
	strcpy(tekst, tekstPitanja);
}

Pitanje::Pitanje(const Pitanje& drugo) : odgovor(0) {
	tekst = new char[strlen(drugo.tekst) + 1];
	strcpy(tekst, drugo.tekst);
}

ostream& operator<<(ostream& os, const Pitanje& pitanje) {
	os << pitanje.tekst << " (" << pitanje.odgovor << ")";
	return os;
}

const char* Pitanje::dohvatiTekst()const {
	return tekst;
}

int Pitanje::dohvatiOdgovor()const {
	return odgovor;
}

void Pitanje::postaviOdgovor(int noviOdg) {
	if (noviOdg > 0) odgovor = noviOdg;
}