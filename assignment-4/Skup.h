#pragma once
#include "Niz.h"

class Skup :
    public Niz
{
protected:
    void pisi(ostream& os) const override;

public:
    void operator+=(int broj) override;
};

