#include "Polinom.h"
#include <cmath>

Polinom::Polinom(int stepen):Niz(stepen+1){}

double Polinom::operator()(double x) const {
	double rezultat = 0;

	for (int i = 0; i < duzina; ++i) {
		rezultat += podaci[i] * pow(x, i);
	}

	return rezultat;
}

Polinom Polinom::operator+(const Polinom& p) const {
	int maxStep = max(duzina, p.duzina);
	Polinom rez(maxStep - 1);

	for (int i = 0; i < maxStep; ++i) {
		int a = (i < duzina) ? podaci[i] : 0;
		int b = (i < p.duzina) ? p.podaci[i] : 0;
		rez[i] = a + b;
	}

	return rez;
}

Polinom& Polinom::operator+=(const Polinom& p) {
	*this = *this + p;

	return *this;
}

Polinom Polinom::operator*(const Polinom& p) const {
	Polinom rez(duzina + p.duzina - 2);
	
	for (int i = 0; i < duzina; ++i) {
		for (int j = 0; j < p.duzina; ++j) {
			rez[i + j] += podaci[i] * p.podaci[j];
		}
	}

	return rez;
}

Polinom& Polinom::operator*=(const Polinom& p) {
	*this = *this * p;
	return *this;
}

ostream& operator<<(ostream& out, const Polinom& p) {
	for (int i = p.duzina - 1; i >= 0; --i) {
		if (p.podaci[i] == 0) continue;
		if (i != p.duzina - 1 && p.podaci[i] > 0) out << "+";
		if (i == 0) {
			out << p.podaci[i];
		}
		else if (i == 1) {
			out << p.podaci[i] << "x";
		}
		else {
			out << p.podaci[i] << "x^" << i;
		}
	}

	return out;
}