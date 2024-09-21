#define _USE_MATH_DEFINES

#include "Sfera.h"
#include <cmath>

Sfera::Sfera(double specificnaTezina, double r): Predmet(specificnaTezina), r(r) {}

double Sfera::zapremina()const  {
	return (4.0 / 3.0) * M_PI * pow(r, 3);
}
void Sfera::ispisi()const  {
	cout << "Sfera, poluprecnik: " << r << ", zapremina: " << zapremina() << ", tezina: " << tezina() << endl;
}
unique_ptr<Predmet> Sfera::kopiraj()const  {
	return make_unique<Sfera>(*this);
}