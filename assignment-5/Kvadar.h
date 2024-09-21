#pragma once
#include "Predmet.h"

class Kvadar :
    public Predmet
{
    double a, b, c;
    
public:
    Kvadar(double specificnaTezina, double a, double b, double c);

    double zapremina()const override;
    void ispisi()const override;
    unique_ptr<Predmet> kopiraj()const override;
};

