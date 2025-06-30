#include "Kazino.h"
#include "Izuzeci.h"
#include <iomanip>

Kazino::Kazino(double pocetni_budzet) {
    if (pocetni_budzet < 0) {
        throw NedovoljniBudzetKazinaIzuzetak();
    }

    this->budzet = pocetni_budzet;
}

Kazino::~Kazino() {}

double Kazino::dohvatiBudzet() const {
    return budzet;
}

void Kazino::dodajIgru(unique_ptr<Igra> igra) {
    if (!igra) {
        throw NevazeciNazivIgreIzuzetak();
    }
    igre.push_back(move(igra));
}

void Kazino::prikaziListuIgara() const {
    if (igre.empty()) {
        cout << "Nema dostupnih igara." << endl;
        return;
    }

    cout << "\n=== DOSTUPNE IGRE ===" << endl;
    cout << setw(5) << "Br." << setw(20) << "Naziv igre" << endl;
    cout << string(25, '-') << endl;

    for (size_t i = 0; i < igre.size(); ++i) {
        cout << setw(5) << (i + 1)
            << setw(20) << igre[i]->dohvatiNaziv() << endl;
    }
    cout << endl;
}

void Kazino::povecajBalansIgraca(Igrac& igrac, double iznos) {
    if (iznos < 0) {
        throw NevazeciRezultatIzuzetak();
    }
    if (budzet < iznos) {
        throw NedovoljniBudzetKazinaIzuzetak();
    }

    igrac.promeniBalans(iznos);
    budzet -= iznos;

    cout << "Balans igraca povecan za " << iznos << ". Novi balans: " << igrac.dohvatiBalans() << endl;
}

Igra* Kazino::odaberiIgru(int indeks, const Igrac& igrac) const {
    if (indeks < 1 || indeks > static_cast<int>(igre.size())) {
        throw NevazeciIndeksIzuzetak();
    }

    if (budzet <= 500) {
        throw NedovoljniBudzetKazinaIzuzetak();
    }

    if (igrac.dohvatiBalans() <= 10) {
        throw NedovoljniBalansIzuzetak();
    }

    return igre[indeks - 1].get();
}

const vector<unique_ptr<Igra>>& Kazino::dohvatiIgre() const {
    return igre;
}

void Kazino::promeniBudzet(double iznos) {
    if (budzet + iznos < 0) {
        throw NedovoljniBudzetKazinaIzuzetak();
    }

    budzet += iznos;
}