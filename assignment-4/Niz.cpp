#include "Niz.h"
#include <algorithm>

Niz::Niz(int kapacitet, int korakPovecanja): kapacitet(kapacitet), korakPovecanja(korakPovecanja), popunjeno(0) {
	niz = new int[kapacitet];
}
Niz::Niz(const Niz& drugi) {
	kapacitet = drugi.kapacitet;
	korakPovecanja = drugi.korakPovecanja;
	popunjeno = drugi.popunjeno;

	niz = new int[kapacitet];
	copy(drugi.niz, drugi.niz + popunjeno, niz);
}

Niz& Niz::operator=(const Niz& drugi) {
	if (this != &drugi) {
		delete[] niz;

		kapacitet = drugi.kapacitet;
		popunjeno = drugi.popunjeno;
		korakPovecanja = drugi.korakPovecanja;

		niz = new int[kapacitet];
		copy(drugi.niz, drugi.niz + popunjeno, niz);
	}

	return *this;
}

void Niz::operator+=(int broj) {
	if (popunjeno == kapacitet) {
		kapacitet += korakPovecanja;
		int* niz2 = new int[kapacitet];
		copy(niz, niz + popunjeno, niz2);

		delete[] niz;
	}

	niz[popunjeno++] = broj;
}

int Niz::operator[](int i)const {
	if (i < 0 || i >= popunjeno) throw exception("Indeks je van dometa");

	return niz[i];
}

int Niz::operator+()const {
	return popunjeno;
}

int Niz::zbir()const {
	int sum = 0;
	for (int i = 0; i < popunjeno; i++)
		sum += niz[i];

	return sum;
}

void Niz::pisi(std::ostream& os) const {
	for (int i = 0; i < popunjeno; ++i) {
		os << niz[i] << " ";
	}
}

ostream& operator<<(ostream& os, const Niz& niz) {
	for (int i = 0; i < niz.popunjeno; ++i) {
		os << niz.niz[i];
		if (i != niz.popunjeno - 1) {
			os << " ";
		}
	}
	return os;
}
ofstream& operator<<(ofstream& ofs, const Niz& niz) {
	for (int i = 0; i < niz.popunjeno; ++i) {
		ofs << niz.niz[i];
		if (i != niz.popunjeno - 1) {
			ofs << ' ';
		}
	}
	return ofs;
}