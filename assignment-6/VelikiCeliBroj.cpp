#include "VelikiCeliBroj.h"

VelikiCeliBroj::VelikiCeliBroj(string broj) : Niz(broj.length()) {
	for (int i = 0; i < duzina; ++i) {
		podaci[i] = broj[duzina - 1 - i] - '0';
	}
}

VelikiCeliBroj VelikiCeliBroj::operator+(const VelikiCeliBroj& b) const {
	int maxD = max(duzina, b.duzina);
	VelikiCeliBroj rez;
	rez.duzina = maxD + 1;
	delete[] rez.podaci;
	rez.podaci = new int[rez.duzina]();

	int prenos = 0;
	for (int i = 0; i < rez.duzina; ++i) {
		int a = (i < duzina) ? podaci[i] : 0;
		int b2 = (i < b.duzina) ? b.podaci[i] : 0;
		int zbir = a + b2 + prenos;
		rez.podaci[i] = zbir % 10;
		prenos = zbir / 10;
	}

	if (rez.podaci[rez.duzina - 1] == 0) {
		--rez.duzina;
	}

	return rez;
}

VelikiCeliBroj& VelikiCeliBroj::operator+=(const VelikiCeliBroj& b) {
	*this = *this + b;

	return *this;
}

bool VelikiCeliBroj::operator==(const VelikiCeliBroj& b) const {
	if (duzina != b.duzina) return false;

	for (int i = 0; i < duzina; ++i) {
		if (podaci[i] != b.podaci[i]) {
			return false;
		}
	}

	return true;
}

bool VelikiCeliBroj::operator<(const VelikiCeliBroj& b) const {
	if (duzina != b.duzina) {
		return duzina < b.duzina;
	}

	for (int i = duzina - 1; i >= 0; --i) {
		if (podaci[i] != b.podaci[i]) {
			return podaci[i] < b.podaci[i];
		}
	}

	return false;
}

bool VelikiCeliBroj::operator!=(const VelikiCeliBroj& b) const { return !(*this == b); }
bool VelikiCeliBroj::operator<=(const VelikiCeliBroj& b) const { return *this < b || *this == b; }
bool VelikiCeliBroj::operator>(const VelikiCeliBroj& b) const { return !(*this <= b); }
bool VelikiCeliBroj::operator>=(const VelikiCeliBroj& b) const { return !(*this < b); }

ostream& operator <<(ostream& out, const VelikiCeliBroj& b) {
	for (int i = b.duzina - 1; i >= 0; --i) {
		out << b.podaci[i];
	}

	return out;
}