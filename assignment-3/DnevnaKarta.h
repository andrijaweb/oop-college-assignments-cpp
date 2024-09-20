#pragma once
#include "Karta.h"

class DnevnaKarta :
    public Karta
{
    float iznos;

public:
    DnevnaKarta(float iznos = 50);

    void dopuni(float dodatak);
    bool jeIspravna(float cena, const Datum&) const;
    void umanjiIznos(float cena);

    friend std::ostream& operator<<(std::ostream& os, const DnevnaKarta& karta);
};

