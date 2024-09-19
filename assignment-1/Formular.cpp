#include "Formular.h"

Formular::Formular(int odKoliko, int doKoliko) : odKoliko(odKoliko), doKoliko(doKoliko) {}

ostream& operator<<(ostream& os, const Formular& formular)
{
	for (const auto& pitanje : formular.pitanja) os << pitanje << endl;
	return os;
}

void Formular::dodajPitanje(const Pitanje& pitanje) {
	pitanja.push_back(pitanje);
}

void Formular::postaviOdgovor(int i, int odgovor) {
	if (i >= 0 && i < pitanja.size() && odgovor >= odKoliko && odgovor <= doKoliko) pitanja[i].postaviOdgovor(odgovor);
}