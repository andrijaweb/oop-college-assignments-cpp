#include "Kvadar.h"
#include "Sfera.h"
#include "Sanduk.h"

int main() {
    Sanduk sanduk1(1000, 2000);
    Sanduk sanduk2(1000, 2000);

    std::unique_ptr<Predmet> sfera = std::make_unique<Sfera>(5, 3);
    std::unique_ptr<Predmet> kvadar = std::make_unique<Kvadar>(2, 2, 3, 4);

    sanduk1.dodajPredmet(std::move(sfera));
    sanduk1.dodajPredmet(std::move(kvadar));

    std::cout << "Sadrzaj sanduka 1: " << std::endl;
    sanduk1.ispisi();

    const Predmet* predmet = sanduk1.dohvatiPredmet(0);
    if (predmet) {
        sanduk2.dodajKopiraniPredmet(predmet);
    }

    std::cout << "\nSadrzaj sanduka 2: " << std::endl;
    sanduk2.ispisi();

    return 0;
}