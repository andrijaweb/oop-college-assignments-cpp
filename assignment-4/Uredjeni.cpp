#include "Uredjeni.h"
#include <algorithm>

void Uredjeni::operator+=(int broj) {
    Niz::operator+=(broj);
    sort(niz, niz + popunjeno);
}

void Uredjeni::pisi(std::ostream& os) const {
    os << "(";
    for (int i = 0; i < popunjeno; ++i) {
        os << niz[i];
        if (i != popunjeno - 1) {
            os << ",";
        }
    }
    os << ")";
}