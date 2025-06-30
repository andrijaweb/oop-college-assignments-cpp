#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class KazinoIzuzetak : public runtime_error {
public:
	KazinoIzuzetak(const string& poruka) : runtime_error(poruka) {}
};

class NevazeciIdIgracaIzuzetak : public KazinoIzuzetak {
public:
	NevazeciIdIgracaIzuzetak() : KazinoIzuzetak("Nevazeci id igraca!") {}
};

class NedovoljniBalansIzuzetak : public KazinoIzuzetak {
public:
	NedovoljniBalansIzuzetak() : KazinoIzuzetak("Nedovoljan balans igraca!") {}
};

class NedovoljniBudzetKazinaIzuzetak : public KazinoIzuzetak {
public:
	NedovoljniBudzetKazinaIzuzetak() : KazinoIzuzetak("Nedovoljan budzet kazina!") {}
};

class NevazeciNazivIgreIzuzetak : public KazinoIzuzetak {
public: NevazeciNazivIgreIzuzetak() : KazinoIzuzetak("Nevazeci naziv igre!") {}
};

class NevazeciRezultatIzuzetak : public KazinoIzuzetak {
public:
	NevazeciRezultatIzuzetak() : KazinoIzuzetak("Nevazeci rezultat!") {}
};

class NevazeciIndeksIzuzetak : public KazinoIzuzetak {
public:
	NevazeciIndeksIzuzetak() : KazinoIzuzetak("Nevazeci indeks!") {}
};

class PraznaListaIzuzetak : public KazinoIzuzetak {
public:
	PraznaListaIzuzetak() : KazinoIzuzetak("Prazna lista!") {}
};

class PrekidIgreIzuzetak : public KazinoIzuzetak {
public:
	PrekidIgreIzuzetak(const string& poruka) : KazinoIzuzetak(poruka) {}
};
