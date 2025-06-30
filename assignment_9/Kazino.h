#pragma once

#include "Igra.h"
#include "Igrac.h"
#include <vector>
#include <memory>

class Kazino {
private:
	vector<unique_ptr<Igra>> igre;
	double budzet;

public:
	Kazino(double pocetni_budzet);

	Kazino(const Kazino& drugi) = delete;
	Kazino& operator=(const Kazino& drugi) = delete;

	double dohvatiBudzet() const;
	void dodajIgru(unique_ptr<Igra> igra);
	void prikaziListuIgara() const;
	void povecajBalansIgraca(Igrac& igrac, double iznos);
	Igra* odaberiIgru(int indeks, const Igrac& igrac) const;
	
	const vector<unique_ptr<Igra>>& dohvatiIgre() const;
	void promeniBudzet(double iznos);

	~Kazino();
};