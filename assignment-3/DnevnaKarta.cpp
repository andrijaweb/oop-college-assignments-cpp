#include "DnevnaKarta.h"

DnevnaKarta::DnevnaKarta(float iznos) : iznos(iznos) {}

void DnevnaKarta::dopuni(float dodatak) {
    iznos += dodatak;
}

bool DnevnaKarta::jeIspravna(float cena, const Datum&) const {
    return iznos >= cena;
}

void DnevnaKarta::umanjiIznos(float cena) {
    if (jeIspravna(cena, Datum(0, 0))) {
        iznos -= cena;
    }
}

std::ostream& operator<<(std::ostream& os, const DnevnaKarta& karta) {
    os << karta.iznos << "(dnevna karta)";
    return os;
}
