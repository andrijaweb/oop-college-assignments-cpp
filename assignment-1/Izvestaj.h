#pragma once

#include "Formular.h"

class Izvestaj {
	int datum;
	int kapacitet;
	Formular** formulari;
	int brojFormulara;

public:
	Izvestaj(int datum, int kapacitet);

	Izvestaj(const Izvestaj&) = delete;

	friend ostream& operator<<(ostream& os, const Izvestaj& izvestaj);

	void dodajFormular(Formular* formular);
	Formular* dohvatiFormular(int i)const;

	~Izvestaj() {
		delete[] formulari;
	}
};