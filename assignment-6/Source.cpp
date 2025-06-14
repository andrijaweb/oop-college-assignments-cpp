#include <iostream>
#include "Niz.h"
#include "Polinom.h"
#include "VelikiCeliBroj.h"

int main() {
    Niz niz(5);
    std::cout << "Unesi 5 celih brojeva: ";
    std::cin >> niz;
    std::cout << "Niz: " << niz << std::endl;

    Polinom p1(2), p2(1);
    std::cout << "Unesi 3 koeficijenta za p1: ";
    std::cin >> p1;
    std::cout << "Unesi 2 koeficijenta za p2: ";
    std::cin >> p2;
    std::cout << "p1(x) = " << p1 << std::endl;
    std::cout << "p2(x) = " << p2 << std::endl;
    std::cout << "p1 + p2 = " << (p1 + p2) << std::endl;
    std::cout << "p1 * p2 = " << (p1 * p2) << std::endl;

    VelikiCeliBroj b1("12345678901234567890");
    VelikiCeliBroj b2("98765432109876543210");
    std::cout << "Zbir: " << (b1 + b2) << std::endl;
    std::cout << "Poredjenje: " << (b1 < b2 ? "b1 < b2" : "b1 >= b2") << std::endl;

    return 0;
}