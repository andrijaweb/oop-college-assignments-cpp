#include "Niz.h"

Niz::Niz(int n) : duzina(n) {
	podaci = new int[duzina]();
}

Niz::Niz(const Niz& drugi) :duzina(drugi.duzina) {
	podaci = new int[duzina];

	for (int i = 0; i < duzina; ++i) {
		podaci[i] = drugi.podaci[i];
	}
}

	Niz& Niz::operator=(const Niz & drugi) {
		if (this != &drugi) {
			delete[] podaci;

			duzina = drugi.duzina;
			podaci = new int[duzina];
			for (int i = 0; i < duzina; ++i) {
				podaci[i] = drugi.podaci[i];
			}
		}

		return *this;
	}

	int Niz::dohvatiDuzinu() const {
		return duzina;
	}

	int& Niz::operator[](int i) {
		if (i < 0 || i >= duzina) {
			throw out_of_range("Indeks van opsega");
		}

		return podaci[i];
	}

	const int& Niz::operator[](int i) const{
		if (i < 0 || i >= duzina) {
			throw out_of_range("Indeks van opsega");
		}

		return podaci[i];
	}

	istream& operator>>(istream& in, Niz& niz) {
		for (int i = 0; i < niz.duzina; ++i) {
			in >> niz.podaci[i];
		}

		return in;
	}

	ostream& operator<<(ostream& out, const Niz& niz) {
		for (int i = 0; i < niz.duzina; ++i) {
			out << niz.podaci[i] << " ";
		}

		return out;
	}

	Niz::~Niz() {
		delete[] podaci;
	}