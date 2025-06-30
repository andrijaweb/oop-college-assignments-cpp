#include "PseudoRulet.h"
#include "Izuzeci.h"
#include <chrono>

Pseudorulet::Pseudorulet() : Igra("Pseudorulet"), generator(chrono::steady_clock::now().time_since_epoch().count()) {
	resetujIgru();
}

int Pseudorulet::dohvatiKrajnjiIshod() const {
	return krajnji_ishod;
}

bool Pseudorulet::dohvatiBroj(int indeks) const {
	if (indeks < 0 || indeks >= 36) {
		throw NevazeciIndeksIzuzetak();
	}

	return brojevi[indeks];
}

char Pseudorulet::dohvatiBoju() const {
	return boja;
}

bool Pseudorulet::dohvatiParneBrojeve() const {
	return parni_brojevi;
}

void Pseudorulet::resetujIgru() {
	krajnji_ishod = 0;

	for (int i = 0; i < 36; ++i) {
		brojevi[i] = false;
	}
	
	boja = 'r';
	parni_brojevi = false;
}

void Pseudorulet::generisiSlucajniBroj() {
	uniform_int_distribution<int> dis(0, 36);
	krajnji_ishod = dis(generator);
}

bool Pseudorulet::jeParan(int broj) const {
	if (broj == 0) return false;

	return broj % 2 == 0;
}

bool Pseudorulet::jeCrvena(int broj) const {
	if (broj == 0) return false;

	if (broj >= 1 && broj <= 10) {
		return broj % 2 == 1;
	}
	else if (broj >= 11 && broj <= 18) {
		return broj % 2 == 0;
	}
	else if (broj >= 19 && broj <= 28) {
		return broj % 2 == 1;
	}
	else if (broj >= 29 && broj <= 36) {
		return broj % 2 == 0;
	}

	return false;
}

bool& Pseudorulet::operator[](int indeks) {
	if (indeks < 0 || indeks >= 36) {
		throw NevazeciIndeksIzuzetak();
	}
	return brojevi[indeks];
}

Pseudorulet& Pseudorulet::operator*=(char novaBoja) {
	if (novaBoja != 'r' && novaBoja != 'c') {
		throw NevazeciRezultatIzuzetak();
	}

	boja = novaBoja;
	return *this;
}

Pseudorulet& Pseudorulet::operator/=(bool parni) {
	parni_brojevi = parni;

	return *this;
}

Pseudorulet& Pseudorulet::operator-=(bool ponisti) {
	if (ponisti) {
		parni_brojevi = false;
	}

	return *this;
}


void Pseudorulet::operator+(Igrac& igrac) {
	if (proveriPogodak()) {
		igrac.promeniBalans(1.0);
		cout << "Pogodak! Balans uvecan za 1." << endl;
	}
	else {
		igrac.promeniBalans(-1.0);
		cout << "Promasaj! Balans smanjen za 1." << endl;
	}
}

void Pseudorulet::zapocniIgru() {
	resetujIgru();
	generisiSlucajniBroj();

	cout << "Igra zapoceta. Krajnji ishod: " << krajnji_ishod << endl;
}

void Pseudorulet::promeniBalansIgraca(Igrac& igrac, double iznos, double& budzet) {
	if (proveriPogodak()) {
		igrac.promeniBalans(iznos);
		budzet -= iznos;
		cout << "Pogodak. Balans je uvecan za " << iznos << endl;
	}
	else {
		igrac.promeniBalans(-iznos);
		budzet += iznos;
		cout << "Promasaj. Balans je smanjen za " << iznos << endl;
	}
}

Pseudorulet& Pseudorulet::operator+=(int broj) {
	if (broj < 0 || broj >= 36) {
		throw NevazeciIndeksIzuzetak();
	}
	brojevi[broj] = true;
	return *this;
}

bool Pseudorulet::proveriPogodak() const {
	if (brojevi[krajnji_ishod]) {
		return true;
	}

	if (boja == 'c' && !jeCrvena(krajnji_ishod) && krajnji_ishod != 0) {
		return true;
	}
	if (boja == 'r' && jeCrvena(krajnji_ishod)) {
		return true;
	}

	if (parni_brojevi && jeParan(krajnji_ishod)) {
		return true;
	}

	return false;
}

Pseudorulet::~Pseudorulet() {}