#include "Igra.h"
#include "Izuzeci.h"
#include <algorithm>

Igra::Igra(const string& naziv) {
	if (naziv.length() > 30) {
		throw NevazeciNazivIgreIzuzetak();
	}

	this->naziv = naziv;
}

string Igra::dohvatiNaziv() const {
	return naziv;
}

const vector<unique_ptr<Skor>>& Igra::dohvatiSkorove() const {
	return skorovi;
}

Igra& Igra::operator+=(unique_ptr<Skor> skor) {
	if (!skor) {
		throw NevazeciRezultatIzuzetak();
	}
	skorovi.push_back(move(skor));
	return *this;
}

Skor* Igra::operator-(double vrednost) const {
	for (const auto& skor : skorovi) {
		if (skor->dohvatiRezultat() == vrednost) {
			return skor.get();
		}
	}

	return nullptr;
}

void Igra::sortirajSkoroveRastuci() {
	sort(skorovi.begin(), skorovi.end(),
		[](const unique_ptr<Skor>& a, const unique_ptr<Skor>& b) {
			return a->dohvatiRezultat() < b->dohvatiRezultat();
		});
}

void Igra::sortirajSkoroveOpadajuci() {
	sort(skorovi.begin(), skorovi.end(),
		[](const unique_ptr<Skor>& a, const unique_ptr<Skor>& b) {
			return a->dohvatiRezultat() > b->dohvatiRezultat();
		});
}

ostream& operator<<(ostream& out, const Igra& igra) {
	out << "Naziv igre: " << igra.naziv << endl;
	out << "Skorovi:" << endl;

	out << "Br.  "
		<< string(25 - 4, ' ') << "Ime igraca"
		<< string(15 - 9, ' ') << "Rezultat" << endl;
	out << string(45, '-') << endl;

	if (igra.skorovi.empty()) {
		out << "Nema skorova." << endl;
	}
	else {
		for (size_t i = 0; i < igra.skorovi.size(); ++i) {
			string ime = igra.skorovi[i]->dohvatiIgraca().dohvatiIme();
			double rezultat = igra.skorovi[i]->dohvatiRezultat();

			double zaokruzen = round(rezultat * 100) / 100.0;
			int ceo = static_cast<int>(zaokruzen);
			int decimale = static_cast<int>(round((zaokruzen - ceo) * 100));

			string rezultatStr = to_string(ceo) + ".";
			if (decimale < 10) rezultatStr += "0";
			rezultatStr += to_string(decimale);

			string brStr = to_string(i + 1);
			out << brStr << string(5 - brStr.length(), ' ')
				<< ime << string(25 - ime.length(), ' ')
				<< rezultatStr << endl;
		}
	}

	return out;
}

Igra::~Igra() {}