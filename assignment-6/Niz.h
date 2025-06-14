#pragma once

#include <iostream>

using namespace std;

class Niz
{
protected:
    int* podaci;
    int duzina;

    public:
        Niz(int n = 10);
        Niz(const Niz& drugi);
        Niz& operator=(const Niz& drugi);

        int dohvatiDuzinu() const;
        int& operator[](int i);
        const int& operator[](int i) const;

        friend istream& operator>>(istream& in, Niz& niz);
        friend ostream& operator<<(ostream& out, const Niz& niz);

        virtual ~Niz();
};

