#pragma once
#include "Funkcija.h"
#include "Greske.h"

class NizFunkcija {
private:
	Funkcija** funkcije;
	int kapacitet;
public:
	NizFunkcija(int k = 5): kapacitet(k) {
		funkcije = new Funkcija * [kapacitet];
		for (int i = 0; i < kapacitet; ++i) {
			funkcije[i] = nullptr;
		}
	}

	void postavi(int i, Funkcija* f) {
		if (i < 0 || i >= kapacitet) throw Greska("Indeks nije ispravan (u nizu funkcija)!");

		delete funkcije[i];
		funkcije[i] = f;
	}

	double operator()(double x) const {
		double suma = 0;
		for (int i = 0; i < kapacitet; ++i) {
			if (funkcije[i]) suma += (*funkcije[i])(x);
		}

		return suma;
	}

	void pisi() const {
		for (int i = 0; i < kapacitet; ++i) {
			if (funkcije[i]) {
				cout << i << ": ";
				funkcije[i]->pisi(cout);
				cout << endl;
			}
		}
	}

	~NizFunkcija() {
		for (int i = 0; i < kapacitet; ++i) {
			delete funkcije[i];
		}

		delete[] funkcije;
	}
};