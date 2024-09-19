#include "Pitanje.h"
#include "Formular.h"
#include "Izvestaj.h"

int main() {
    Formular formular;
    formular.dodajPitanje(Pitanje("Kako Vam se svidja aplikacija?"));
    formular.dodajPitanje(Pitanje("Ocenite C++ programski jezik"));

    Formular formularKopija1 = formular;
    Formular formularKopija2 = formular;
    
    formularKopija1.postaviOdgovor(0, 5);
    formularKopija1.postaviOdgovor(1, 6);

    formularKopija2.postaviOdgovor(0, 3);
    formularKopija2.postaviOdgovor(1, 4);

    Izvestaj izvestaj(20230919, 10);
    izvestaj.dodajFormular(&formularKopija1);
    izvestaj.dodajFormular(&formularKopija2);

    cout << izvestaj;

    return 0;
}