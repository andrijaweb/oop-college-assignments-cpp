#include "Tacka.h"
#include "Trougao.h"
#include "Ravan.h"

int main() {
    Tacka t1(1.0, 2.0);
    Tacka t2(3.0, 4.0);
    Tacka t3(5.0, 6.0);
    Tacka t4(0.0, 0.0);
    Tacka t5(7.0, 8.0);

    Trougao tr1("T1", &t1, &t2, &t3);
    Trougao tr2("T2", &t2, &t3, &t4);
    Trougao tr3("T3", &t1, &t4, &t5);

    Ravan ravan("MojaRavan");
    ravan.dodajTrougaoURavan(tr1);
    ravan.dodajTrougaoURavan(tr2);
    ravan.dodajTrougaoURavan(tr3);

    cout << "Originalna ravan:" << endl;
    cout << ravan;

    Ravan novaRavan = ravan.kreirajRavan(2.0, 6.0);
    cout << "Ispis nove ravni nakon kreiranja: " << endl;
    cout << novaRavan << endl;

    return 0;
}