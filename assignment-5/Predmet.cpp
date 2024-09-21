#include "Predmet.h"

Predmet::Predmet(double specificnaTezina): specificnaTezina(specificnaTezina) {}

double Predmet::tezina()const {
	return specificnaTezina * zapremina();
}