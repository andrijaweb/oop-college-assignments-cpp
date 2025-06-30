#pragma once

#include "Skor.h"
#include <vector>
#include <memory>

class Igra {
protected: 
	string naziv;
	vector<unique_ptr<Skor>> skorovi;
public:
	Igra(const string& naziv);

	Igra(const Igra& druga) = delete;
	Igra& operator=(const Igra& druga) = delete;

	string dohvatiNaziv() const;
	const vector<unique_ptr<Skor>>& dohvatiSkorove() const;

	Igra& operator+=(unique_ptr<Skor> skor);

	Skor* operator-(double vrednost) const;

	void sortirajSkoroveRastuci();
	void sortirajSkoroveOpadajuci();

	virtual void zapocniIgru() = 0;
	virtual void promeniBalansIgraca(Igrac& igrac, double iznos, double& budzet) = 0;

	friend ostream& operator<<(ostream& os, const Igra& igra);

	virtual ~Igra();
};