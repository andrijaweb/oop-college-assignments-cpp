#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Pitanje {
	char* tekst;
	int odgovor;

public:
	Pitanje(const char* tekstPitanja);

	Pitanje(const Pitanje& drugo);

	friend ostream& operator<<(ostream& os, const Pitanje& pitanje);

	const char* dohvatiTekst() const;
	int dohvatiOdgovor() const;
	void postaviOdgovor(int noviOdg);

	~Pitanje() {
		delete[] tekst;
	}
};

