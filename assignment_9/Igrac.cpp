#include "Igrac.h"
#include "Izuzeci.h"
#include <cmath>

int Igrac::sledeci_id = 1;

Igrac::Igrac(const string& ime, double balans) {
	if (ime.length() > 80) {
		throw NevazeciIdIgracaIzuzetak();
	}
	if (balans < 0) {
		throw NedovoljniBalansIzuzetak();
	}

	this->id = sledeci_id++;
	this->ime = ime;
	this->balans = balans;
}

Igrac::Igrac(const Igrac& drugi) {
	this->id = sledeci_id++;
	this->ime = drugi.ime;
	this->balans = drugi.balans;
}

Igrac& Igrac::operator=(const Igrac& drugi) {
	if (this != &drugi) {
		this->ime = drugi.ime;
		this->balans = drugi.balans;
	}

	return *this;
}

int Igrac::dohvatiId() const {
	return id;
}

string Igrac::dohvatiIme() const {
	return ime;
}

double Igrac::dohvatiBalans() const {
	return balans;
}

void Igrac::podesiBalans(double noviBalans) {
	if (noviBalans < 0) {
		throw NedovoljniBalansIzuzetak();
	}

	this->balans = noviBalans;
}

void Igrac::promeniBalans(double iznos) {
	if (balans + iznos < 0) {
		throw NedovoljniBalansIzuzetak();
	}

	balans += iznos;
}

istream& operator>>(istream& in, Igrac& igrac) {
	string ime;
	double balans;

	cout << "Unesite ime igraca: ";
	getline(in, ime);

	cout << "Unesite balans igraca: ";
	in >> balans;
	in.ignore();

	if (ime.length() > 80) {
		throw NevazeciIdIgracaIzuzetak();
	}
	if (balans < 0) {
		throw NedovoljniBalansIzuzetak();
	}

	igrac.ime = ime;
	igrac.balans = balans;

	return in;
}

ostream& operator<<(ostream& out, const Igrac& igrac) {
	double zaokrezeniNaDveDecimale = round(igrac.balans * 100) / 100;

	int celi = static_cast<int>(zaokrezeniNaDveDecimale);
	int decimale = static_cast<int>(round((zaokrezeniNaDveDecimale - celi) * 100));

	out << "Id: " << igrac.id << ", Ime: " << igrac.ime << ", Balans: " << celi << ".";

	if (decimale < 10) out << "0";
	out << decimale;

	return out;
}

Igrac::~Igrac() {}