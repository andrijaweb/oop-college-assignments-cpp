#include "Blekdzek.h"
#include "Izuzeci.h"
#include <algorithm>
#include <chrono>

Blekdzek::Blekdzek() : Igra("Blekdzek"), generator(chrono::steady_clock::now().time_since_epoch().count()) {
	resetujIgru();
}

void Blekdzek::resetujIgru() {
	inicijalizujSpil();
	promesajSpil();

	for (int i = 0; i < 9; ++i) {
		ruka[i] = 0;
	}
}

void Blekdzek::inicijalizujSpil() {
	int indeks = 0;

	for (int broj = 1; broj <= 13; ++broj) {
		for (int i = 0; i < 4; i++) {
			spil[indeks++] = broj;
		}
	}
}

void Blekdzek::promesajSpil() {
	shuffle(spil, spil + 52, generator);
}

int Blekdzek::generisiSlucajanBroj() {
	uniform_int_distribution<int> dis(1, 13);
	
	return dis(generator);
}

int Blekdzek::izracunajRezultat() const {
	int rezultat = 0;
	int asovi = 0;

	for (int i = 0; i < 9 && ruka[i] != 0; ++i) {
		int karta = ruka[i];

		if (karta == 1) {
			asovi++;
			rezultat += 11;
		}
		else if (karta >= 11 && karta <= 13) {
			rezultat += 10;
		}
		else {
			rezultat += karta;
		}
	}

	while (asovi > 0 && rezultat > 21) {
		rezultat -= 10;
		asovi--;
	}

	return rezultat;
}

int Blekdzek::izvuciKartu() {
	for (int i = 0; i < 52; ++i) {
		if (spil[i] != 0) {
			int karta = spil[i];
			spil[i] = 0;

			for (int j = 0; j < 9; ++j) {
				if (ruka[j] == 0) {
					ruka[j] = karta;
					break;
				}
			}

			int rezultat = izracunajRezultat();
			if (rezultat > 21) {
				throw PrekidIgreIzuzetak("Rezultat je veci od 21. Igra je zavrsena.");
			}

			return rezultat;
		}
	}

	throw PraznaListaIzuzetak();
}

bool Blekdzek::prekiniIgru(Igrac& igrac, double& budzet) {
	uniform_int_distribution<int> dis(15, 25);
	int generisanBroj = dis(generator);
	int trenutniRezultat = izracunajRezultat();

	cout << "Generisan broj: " << generisanBroj << ", trenutni rezultat: " << trenutniRezultat << endl;

	if (generisanBroj > trenutniRezultat && generisanBroj >= 15 && generisanBroj <= 21) {
		igrac.promeniBalans(-3.0);
		budzet += 3.0;
		cout << "Kuca pobedjuje. Balans smanjen za 3." << endl;
		return false;
	}
	else {
		igrac.promeniBalans(3.0);
		budzet -= 3.0;
		cout << "Igrac pobedjuje! Balans povecan za 3." << endl;
		return true;
	}
}

void Blekdzek::zapocniIgru() {
	resetujIgru();
	cout << "Blekdzek je zapocet! Spil je promesan." << endl;

	try {
		izvuciKartu();
		izvuciKartu();
		cout << "Podeljene su dve pocetne karte." << endl;
		prikaziRuku();
	}
	catch (const PrekidIgreIzuzetak& e) {
		cout << "Igra se zavrsila odmah: " << e.what() << endl;
	}
}

void Blekdzek::promeniBalansIgraca(Igrac& igrac, double iznos, double& budzet) {
	try {
		int rezultat = izvuciKartu();
		cout << "Nova karta izvucena! Trenutni rezultat: " << rezultat << endl;
		prikaziRuku();
	}
	catch (const PrekidIgreIzuzetak& e) {
		cout << e.what() << endl;
		igrac.promeniBalans(-3.0);
		budzet += 3.0;
		cout << "Balans smanjen za 3 zbog premasivanja 21." << endl;
	}
}

void Blekdzek::prikaziRuku() const {
	cout << "Ruka igraca: ";
	for (int i = 0; i < 9 && ruka[i] != 0; i++) {
		cout << ruka[i] << " ";
	}
	cout << "| Rezultat: " << izracunajRezultat() << endl;
}

const int* Blekdzek::dohvatiSpil() const {
	return spil;
}

const int* Blekdzek::dohvatiRuku() const {
	return ruka;
}

Blekdzek::~Blekdzek() {}