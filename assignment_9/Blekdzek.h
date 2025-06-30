#pragma once

#include "Igra.h"
#include <random>

class Blekdzek : public Igra {
private:
	int spil[52];
	int ruka[9];
	mt19937 generator;

public:
	Blekdzek();

	void resetujIgru();
	void inicijalizujSpil();
	void promesajSpil();
	
	int generisiSlucajanBroj();
	int izracunajRezultat() const;
	int izvuciKartu();

	bool prekiniIgru(Igrac& igrac, double& budzet);

	void zapocniIgru() override;
	void promeniBalansIgraca(Igrac& igrac, double iznos, double& budzet) override;

	void prikaziRuku() const;

	const int* dohvatiSpil() const;
	const int* dohvatiRuku() const;

	~Blekdzek();
};