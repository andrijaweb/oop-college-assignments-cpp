#pragma once
#include "Karta.h"

class MesecnaKarta :
    public Karta
{
    char vlasnik[40];
    Datum vazenje;

public:
    MesecnaKarta(const char* vl, const Datum& datum);

    void produziVazenje(int mesec, int godina);

    bool jeIspravna(float, const Datum& datum)const override; 

    friend ostream& operator<<(ostream& os, const MesecnaKarta& mesecnaKarta);
};

