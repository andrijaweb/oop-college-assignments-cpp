#include "Skor.h"
#include "Izuzeci.h"
#include <cmath>

Skor::Skor(const Igrac& igrac, double rezultat) : igrac(igrac) {
    this->rezultat = rezultat;
}

double Skor::dohvatiRezultat() const {
    return rezultat;
}

const Igrac& Skor::dohvatiIgraca () const {
    return igrac;
}

void Skor::podesiRezultat(double noviRezultat) {
    this->rezultat = noviRezultat;
}

void Skor::podesiIgraca(const Igrac& noviIgrac) {
    this->igrac = noviIgrac;
}

ostream& operator<<(ostream& out, const Skor& skor) {
    double zaokrezeniNaDveDecimale = round(skor.rezultat * 100) / 100.0;
    int celi = static_cast<int>(zaokrezeniNaDveDecimale);
    int decimale = static_cast<int>(round((zaokrezeniNaDveDecimale - celi) * 100));

    out << skor.igrac << ", Rezultat: " << celi << ".";
    if (decimale < 10) out << "0";
    out << decimale;

    return out;
}

Skor::~Skor() {}