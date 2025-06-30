#pragma once
#include "Igra.h"
#include <random>

class Pseudorulet : public Igra {
private:
	int krajnji_ishod;
	bool brojevi[36];
	char boja;
	bool parni_brojevi;
	mt19937 generator;

public:

	Pseudorulet();

	using Igra::operator+=;

	int dohvatiKrajnjiIshod() const;
	bool dohvatiBroj(int indeks) const;
	char dohvatiBoju() const;
	bool dohvatiParneBrojeve() const;

	void resetujIgru();

	void generisiSlucajniBroj();

	bool jeParan(int broj) const;
	bool jeCrvena(int broj) const;

	bool& operator[](int indeks);
	Pseudorulet& operator+=(int broj);

	Pseudorulet& operator*=(char novaBoja);
	Pseudorulet& operator/=(bool parni);
	Pseudorulet& operator-=(bool ponisti);
	void operator+(Igrac& igrac);

	void zapocniIgru() override;
	void promeniBalansIgraca(Igrac& igrac, double iznos, double& budzet) override;

	bool proveriPogodak() const;

	~Pseudorulet();
};