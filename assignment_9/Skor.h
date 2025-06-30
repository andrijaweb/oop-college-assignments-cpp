#pragma once
#include "Igrac.h"

class Skor {
private:
	double rezultat;
	Igrac igrac;

public:
	Skor(const Igrac& igrac, double rezultat = 0.0);
	Skor(const Skor& drugi) = delete;
	
	Skor& operator=(const Skor& drugi) = delete;

	double dohvatiRezultat() const;
	const Igrac& dohvatiIgraca() const;

	void podesiRezultat(double noviRezultat);
	void podesiIgraca(const Igrac& noviIgrac);

	friend ostream& operator<<(ostream& out, const Skor& skor);

	~Skor();
};