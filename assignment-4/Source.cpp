#include "Niz.h"
#include "Skup.h"
#include "Uredjeni.h"
#include <vector>
#include <algorithm>

void procitajNiz(Niz& niz) {
    int broj;
    while (true) {
        cin >> broj;
        if (broj == 9999) 
            break;
        niz += broj;
    }
}

int main() {
    std::vector<Niz*> nizovi;

    while (true) {
        int tipNiza;
        std::cout << "Odaberi tip niza (1-Niz, 2-UredjeniNiz, 3-Skup): ";
        std::cin >> tipNiza;

        Niz* niz = nullptr;
        if (tipNiza == 1) 
            niz = new Niz();

        if (tipNiza == 2) 
            niz = new Uredjeni();

        if (tipNiza == 3)
            niz = new Skup();

        if (niz) {
            std::cout << "Unesi broj (9999 za kraj): ";
            procitajNiz(*niz);
            nizovi.push_back(niz);

            std::cout << "Niz: " << *niz << std::endl;
            std::cout << "Zbir elemenata niza: " << niz->zbir() << std::endl;
        }

        std::cout << "Nastavi unos? (0-Ne, 1-Da): ";
        int nastavi;
        std::cin >> nastavi;
        if (nastavi == 0) {
            break;
        }
    }

    sort(nizovi.begin(), nizovi.end(), [](Niz* n1, Niz* n2) {
        return n1->zbir() < n2->zbir();
        });

    std::cout << "Sortirani nizovi: " << std::endl;
    for (Niz* niz : nizovi) {
        std::cout << *niz << " Zbir: " << niz->zbir() << std::endl;
    }

    for (Niz* niz : nizovi) {
        delete niz;
    }

    return 0;
}