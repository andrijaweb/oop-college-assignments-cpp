#pragma once
#include "Niz.h"

class Polinom :
    public Niz
{
public:
    Polinom(int stepen = 0);

    double operator()(double x)const;
    Polinom operator+(const Polinom& p) const;
    Polinom& operator+=(const Polinom& p);
    Polinom operator*(const Polinom& p) const;
    Polinom& operator *=(const Polinom& p);

    friend ostream& operator<<(ostream& out, const Polinom& p);
};

