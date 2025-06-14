#pragma once
#include "Funkcija.h"
#include <cmath>

class Sinusoida : public Funkcija {
private:
	double a, b, c;
public:
	Sinusoida(double a = 1, double b=1, double c = 0):a(a), b(b), c(c) {}

	double operator()(double x) const override {
		return a * sin(b * x + c);
	}

	void citaj(istream& in) override {
		cout << "Unesite a, b, c za sinusoidu: ";
		in >> a >> b >> c;
	}

	void pisi(ostream& out) const override {
		out << a << "sin(" << b << "x+" << c << ")";
	}
};