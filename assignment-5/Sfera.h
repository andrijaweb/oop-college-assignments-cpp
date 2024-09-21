#pragma once
#include "Predmet.h"

class Sfera :
    public Predmet
{
    double r;

public:
    Sfera(double specificnaTezina, double r);

    double zapremina()const override;
    void ispisi()const override;
    unique_ptr<Predmet> kopiraj()const override;
};

