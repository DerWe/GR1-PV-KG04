#include <iostream>
#include "Transportmittel.h"

using namespace std;

//Getter definieren
double Transportmittel::get_hoehe() const { return hoehe; }
double Transportmittel::get_breite() const { return breite; }
double LandTransportmittel::get_radzahl() const { return radzahl; }
double WasserTransportmittel::get_bruttoregistriertonnen() const { return bruttoregistriertonnen; }

//Methode "Bewegen"
void Transportmittel::bewegen(string Richtung) {
	cout << "In Richtung " + Richtung + " bewegen \n";
}

//Methode "fahren" (LandTransportmittel)
void LandTransportmittel::fahren(double km) {
	cout << "Fahre " << km << " Kilometer." << endl;
}

//Methode "schieben" (LandTransportmittel)
void LandTransportmittel::schieben(double km) {
	cout << "Schiebe " << km << " Kilometer." << endl;
}

//Methode "anlegen" (WasserTransportmittel)
void WasserTransportmittel::anlegen(string Anlegehafen) {
	cout << "Lege in  " << Anlegehafen << " an." << endl;
}

//Methode "ablegen" (WasserTransportmittel)
void WasserTransportmittel::ablegen(string Ablegehafen) {
	cout << "Lege in  " << Ablegehafen << " ab." << endl << "AHOI MATROSE!" << endl;
}