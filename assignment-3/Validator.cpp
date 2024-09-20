#include "Validator.h"

Validator::Validator(size_t kapacitet): kapacitet(kapacitet) {}

Validator::Validator(const Validator& drugi): kapacitet(drugi.kapacitet) {
	for (Karta* karta : drugi.karte) {
		karte.push_back(karta);
	}
}

Validator& Validator::operator=(const Validator& drugi) {
	if (this != &drugi) {
		for (Karta* karta : karte)
			delete karta;
		
		karte.clear();

		kapacitet = drugi.kapacitet;
		for (Karta* karta : drugi.karte)
			karte.push_back(karta);
	}

	return *this;
}

void Validator::operator+=(Karta* karta) {
	if (karte.size() < kapacitet) karte.push_back(karta);
}

void Validator::proveriKarte(double cena, const Datum& datum) const {
	for (Karta* karta : karte) {
		cout << *karta << '/';
		if (karta->jeIspravna(cena, datum))
			cout << "vazi";
		else cout << "ne vazi";

		cout << endl;
	}
}