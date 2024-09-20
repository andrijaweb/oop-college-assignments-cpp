#define _CRT_SECURE_NO_WARNINGS 1
#include "MesecnaKarta.h"

MesecnaKarta::MesecnaKarta(const char* vl, const Datum& datum): vazenje(datum) {
	strncpy(vlasnik, vl, sizeof(vlasnik));
	vlasnik[sizeof(vlasnik) - 1] = '\0';
}

void MesecnaKarta::produziVazenje(int mesec, int godina) {
	vazenje = Datum(mesec, godina);
}

bool MesecnaKarta::jeIspravna(float, const Datum& datum)const {
	return datum == vazenje;
}

ostream& operator<<(ostream& os, const MesecnaKarta& mesecnaKarta) {
	os << mesecnaKarta.vlasnik << " (mesecna karta) " << mesecnaKarta.vazenje;

	return os;
}
