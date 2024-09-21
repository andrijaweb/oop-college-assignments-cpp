#include "Sanduk.h"
#include <algorithm>

const Predmet* Sanduk::dohvatiPredmet(size_t i) const {
	if (i < predmeti.size()) {
		return predmeti[i].get();
	}
	return nullptr;
}

bool Sanduk::dodajKopiraniPredmet(const Predmet* predmet) {
	if (predmet && trenutnaZapremina() + predmet->zapremina() <= ukupnaZapremina &&
		trenutnaTezina() + predmet->tezina() <= ukupnaTezina) {
		predmeti.push_back(predmet->kopiraj());
		return true;
	}
	return false;
}

Sanduk::Sanduk(double ukupnaZapremina, double ukupnaTezina): ukupnaZapremina(ukupnaZapremina), ukupnaTezina(ukupnaTezina) {}

double Sanduk::trenutnaZapremina()const {
	double zapr = 0;
	for (const auto& predmet : predmeti)
		zapr += predmet->zapremina();

	return zapr;
}

double Sanduk::trenutnaTezina()const {
	double tez = 0;
	for (const auto& predmet : predmeti)
		tez += predmet->tezina();
	
	return tez;
}

bool Sanduk::dodajPredmet(unique_ptr<Predmet> predmet) {
	if (trenutnaZapremina() + predmet->zapremina() <= ukupnaZapremina && trenutnaTezina() + predmet->tezina() <= ukupnaTezina) {
		predmeti.push_back(move(predmet));
		return true;
	}

	return false;
}

void Sanduk::izbaciNajlaksi() {
	if (predmeti.empty()) return;
	auto it = min_element(predmeti.begin(), predmeti.end(), [](const unique_ptr<Predmet>& p1, const unique_ptr<Predmet>& p2) {
		return p1->tezina() < p2->tezina();
		});
	predmeti.erase(it);
}

void Sanduk::izbaciNajtezi() {
	if (predmeti.empty()) return;
	auto it = std::max_element(predmeti.begin(), predmeti.end(),
		[](const std::unique_ptr<Predmet>& p1, const std::unique_ptr<Predmet>& p2) {
			return p1->tezina() < p2->tezina();
		});
	predmeti.erase(it);
}

void Sanduk::izbaciPoRednomBroju(size_t i) {
	if (i < predmeti.size())
		predmeti.erase(predmeti.begin() + i);
}

void Sanduk::ispisi()const {
	cout << "Sanduk (trenutna zapremina: " << trenutnaZapremina() << ", trenutna tezina: " << trenutnaTezina() << ')' << endl;
	for (const auto& predmet : predmeti)
		predmet->ispisi();
}

size_t Sanduk::brojPredmeta() const {
	return predmeti.size();
}