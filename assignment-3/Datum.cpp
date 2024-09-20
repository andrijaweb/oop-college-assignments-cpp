#include "Datum.h"

Datum::Datum(int mesec, int godina): mesec(mesec), godina(godina) {}

int Datum::dohvatiMesec()const {
	return mesec;
}
int Datum::dohvatiGodina()const{
	return godina;
}

bool Datum::operator==(const Datum& other) const {
	return mesec == other.mesec && godina == other.godina;
}
bool Datum::operator!=(const Datum& drugi)const {
	return !(*this == drugi);
}

ostream& operator<<(ostream& os, const Datum& datum) {
	os << datum.mesec << '/' << datum.godina;
	return os;
}