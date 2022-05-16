#include <iostream>
#include "Transportmittel.h"

using namespace std;

//Getter definieren
double Transportmittel::get_hoehe() const { return hoehe; }
double Transportmittel::get_breite() const { return breite; }
double LandTransportmittel::get_radzahl() const { return radzahl; }
double WasserTransportmittel::get_bruttoregistriertonnen() const { return bruttoregistriertonnen; }
int Fahrrad::get_anzahlgaenge() const { return anzahlgaenge; }
string Rikscha::get_farbe() const { return farbe; }
double xAuto::get_spritverbrauch() const { return spritverbrauch; }

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

//Methode "freihändigfahren" (Fahrrad)
void Fahrrad::freihändigfahren(string name) {
	cout << name << " f\x84hrt freih\x84ndig mit dem Fahrrad." << endl;
}

//Methode "schieben" (Fahrrad)
void Fahrrad::schieben(double km) {
	cout << "Wer sein Fahrrad liebt, der schiebt es " << km << " Kilometer. :D" << endl;
}

//Methode "ziehen" (Rikscha)
void Rikscha::ziehen(int anzahlpersonen) {
	cout << "Die Rikscha wird von " << anzahlpersonen << " gezogen." << endl;
}

//Methode "schieben" (Rikscha)
void Rikscha::schieben(double km) {
	cout << "Nach dem Ziehen kommt das Schieben der Rikscha f\x81r " << km << " Kilometer." << endl;
}

//Methode "tanken" (Auto)
void xAuto::tanken(int liter) {
	cout << "Weil der Sprit aktuell so g\x81nstig ist, tanke ich " << liter << " Liter." << endl;
}

//Methode "fahren" (Auto)
void xAuto::fahren(double km) {
	cout << "Fahre meinen Kraftfahrzeug " << km << " Kilometer." << endl;
}