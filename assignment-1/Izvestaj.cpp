#include "Izvestaj.h"

Izvestaj::Izvestaj(int datum, int kapacitet) : datum(datum), kapacitet(kapacitet), brojFormulara(0) {
	formulari = new Formular * [kapacitet];
}

ostream& operator<<(ostream& os, const Izvestaj& izvestaj) {
	os << "Datum: " << izvestaj.datum << endl;
	for (int i = 0; i < izvestaj.brojFormulara; i++) {
		os << endl << *(izvestaj.formulari[i]) << endl;
	}

	return os;
}

void Izvestaj::dodajFormular(Formular* formular) {
	if (brojFormulara < kapacitet) formulari[brojFormulara++] = formular;
}

Formular* Izvestaj::dohvatiFormular(int i)const {
	if (i >= 0 && i < brojFormulara) return formulari[i];

	return nullptr;
}