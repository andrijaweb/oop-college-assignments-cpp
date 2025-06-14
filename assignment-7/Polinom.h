#pragma once
#include "Funkcija.h"
#include <vector>
#include <cmath>

class Polinom : public Funkcija {
private:
	vector<double> koef;
public:
	Polinom(int stepen = 0) : koef(stepen + 1, 1) {}

	double operator()(double x) const override {
		double suma = 0;
		int n = koef.size();

		for (int i = 0; i < n; ++i) {
			suma += koef[i] * pow(x, n - i - 1);
		}

		return suma;
	}

	void citaj(istream& in) override {
		cout << "Unesi " << koef.size() << " koeficijenata za polinom: ";

		for (auto& k : koef) {
			in >> k;
		}
	}

	void pisi(ostream& out) const override {
		out << "p(x)[";
		for (size_t i = 0; i < koef.size(); ++i) {
			out << koef[i];
			if (i != koef.size() - 1) {
				out << ",";
			}
		}

		out << "]";
	}

	int red() const {
		return koef.size() - 1;
	}

	double& operator[](int i) {
		return koef[i];
	}

	const double& operator[](int i) const {
		return koef[i];
	}
};