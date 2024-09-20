#include "Skup.h"
#include <algorithm>

void Skup::operator+=(int broj) {
    for (int i = 0; i < popunjeno; ++i) {
        if (niz[i] == broj) {
            return;
        }
    }
    Niz::operator+=(broj);
}

void Skup::pisi(std::ostream& os) const {
    os << "{";
    for (int i = 0; i < popunjeno; ++i) {
        os << niz[i];
        if (i != popunjeno - 1) {
            os << ",";
        }
    }
    os << "}";
}