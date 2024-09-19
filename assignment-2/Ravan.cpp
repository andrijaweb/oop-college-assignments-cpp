#define _CRT_SECURE_NO_WARNINGS 1
#include "Ravan.h"


Ravan::Ravan(const char* ime) {
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);
}

Ravan::Ravan(const Ravan& druga) {
	// ista situacija, fiksni broj 6 za karaktere
	this->ime = new char[strlen(druga.ime) + 6];
	strcpy(this->ime, druga.ime);
	strcat(this->ime, "_novi");
}

ostream& operator<<(ostream& os, const Ravan& ravan) {
	os << ravan.ime << endl;
	for (const auto& trougao : ravan.trouglovi) {
		os << "Trougao: " << endl;
		os << trougao << endl;
	}

	return os;
}

void Ravan::dodajTrougaoURavan(const Trougao& trougao) {
	cout << "Dodajem trougao: " << trougao << endl;
	trouglovi.push_back(trougao);
}

Ravan Ravan::kreirajRavan(float min, float max)const {
	Ravan novaRavan(ime);
	for (const auto& trougao : trouglovi) {
		float aritmeticka = trougao.aritmetickaSredinaOdPocetka();
		cout << "Aritmeticka sredina za trougao: " << aritmeticka << endl;
		if (aritmeticka <= max && aritmeticka >= min) {
			cout << "Dodajem trougao u novu ravan: " << trougao << endl;
			novaRavan.dodajTrougaoURavan(trougao);
		}
	}

	cout << "Nova ravan pre povratka:" << endl;
	cout << novaRavan << endl;

	return novaRavan;
}