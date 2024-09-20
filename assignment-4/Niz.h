#pragma once
#include <iostream>

using namespace std;

class Niz
{
protected:
    int* niz;
    int kapacitet, korakPovecanja, popunjeno;

    virtual void pisi(ostream& os) const;

public:
    Niz(int kapacitet = 10, int korakPovecanja = 4);
    Niz(const Niz& drugi);

    Niz& operator=(const Niz& drugi);

    virtual void operator+=(int broj);
    int operator[](int i)const;
    int operator+()const;
    int zbir()const;

    friend ostream& operator<<(std::ostream& os, const Niz& niz);
    friend ofstream& operator<<(std::ofstream& ofs, const Niz& niz);

    virtual ~Niz() {
        delete[] niz;
    }
};

