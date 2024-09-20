#pragma once

#include <vector>
#include "Karta.h"

class Validator 
{
    std::vector<Karta*> karte;
    size_t kapacitet;

public:
    Validator(size_t kapacitet = 20);
    Validator(const Validator& drugi);
    Validator& operator=(const Validator& drugi);

    void operator+=(Karta* karta);
    void proveriKarte(double cena, const Datum& datum) const;

    ~Validator() {
        for (Karta* karta : karte) {
            delete karta;
        }
    }
};

