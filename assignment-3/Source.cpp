#include "MesecnaKarta.h"
#include "DnevnaKarta.h"
#include "Validator.h"

int main() {
    Validator validator;

    MesecnaKarta* mesecna = new MesecnaKarta("Bogdan Aleksic", Datum(9, 2024));
    DnevnaKarta* dnevna = new DnevnaKarta();

    validator += mesecna;
    validator += dnevna;

    std::cout << "Provera karata za 9/2024:" << std::endl;
    validator.proveriKarte(30, Datum(9, 2024));

    dnevna->dopuni(20);

    std::cout << "Provera karata za 10/2024:" << std::endl;
    validator.proveriKarte(30, Datum(10, 2024));

    delete mesecna;
    delete dnevna;

    return 0;
}
