#pragma once
#include <vector>
#include <memory>

#include "Predmet.h"

using namespace std;

class Sanduk
{
	double ukupnaZapremina;
	double ukupnaTezina;
	vector<unique_ptr<Predmet>> predmeti;

public:
	Sanduk(double ukupnaZapremina, double ukupnaTezina);

	const Predmet* dohvatiPredmet(size_t i) const;

	bool dodajKopiraniPredmet(const Predmet* predmet);

	double trenutnaZapremina()const;
	double trenutnaTezina()const;
	bool dodajPredmet(unique_ptr<Predmet> predmet);
	void izbaciNajlaksi();
	void izbaciNajtezi();
	void izbaciPoRednomBroju(size_t i);
	void ispisi()const;
	size_t brojPredmeta() const;
};

