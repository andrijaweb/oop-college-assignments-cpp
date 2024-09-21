#include "Kvadar.h"

Kvadar::Kvadar(double specificnaTezina, double a, double b, double c): Predmet(specificnaTezina), a(a), b(b), c(c) {}

double Kvadar::zapremina()const {
	return a * b * c;
}
void Kvadar::ispisi()const {
	cout << "Kvadar, dimenzije: " << a << " x " << b << " x " << c << ", zapremina: " << zapremina() << ", tezina: " << tezina() << endl;
}

unique_ptr<Predmet> Kvadar::kopiraj()const {
	return make_unique<Kvadar>(*this);
}