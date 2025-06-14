#include <iostream>
#include "Sinusoida.h"
#include "Polinom.h"
#include "NizFunkcija.h"

int main() {
	try
	{
		NizFunkcija niz;

		Funkcija* f = new Sinusoida();
		f->citaj(cin);
		niz.postavi(0, f);

		Funkcija* f2 = new Polinom(2);
		f2->citaj(cin);
		niz.postavi(1, f2);

		double x;
		cout << "Unesite x za racunanje vrednosti svih funkcija: ";
		cin >> x;

		cout << "Funkcije u nizu:\n";
		niz.pisi();

		cout << "Zbir vrednosti svih funkcija u tacki x = " << x << " je: " << niz(x) << endl;
	}
	catch (const exception& e)
	{
		cerr << "Greska: " << e.what() << endl;
	}

	return 0;
}