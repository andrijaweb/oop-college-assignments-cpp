#pragma once
#include "Niz.h"
class VelikiCeliBroj :
    public Niz
{
public:
    VelikiCeliBroj(string broj = "0");

    VelikiCeliBroj operator+(const VelikiCeliBroj& b) const;
    VelikiCeliBroj& operator+=(const VelikiCeliBroj& b);

    bool operator==(const VelikiCeliBroj& b) const;
    bool operator<(const VelikiCeliBroj& b) const;

    bool operator!=(const VelikiCeliBroj& b) const;
    bool operator<=(const VelikiCeliBroj& b) const;
    bool operator>(const VelikiCeliBroj& b) const;
    bool operator>=(const VelikiCeliBroj& b) const;

    friend ostream& operator<<(ostream& out, const VelikiCeliBroj& b);
};

