#pragma once
#include "Funkcija.h"
#include <cmath>

class PrirodniLogaritam : public Funkcija {
private:
	double a, b;
public:
	PrirodniLogaritam(double a=1, double b=1): a(a), b(b) {}

	double operator()(double x) const override {
		return a * log(b * x);
	}

	void citaj(istream& in) override {
		cout << "Unesite a i b za alog(bx): ";
		in >> a >> b;
	}

	void pisi(ostream& out) const override {
		out << a << "log(" << b << "x)";
	}
};