#include <iostream>
#include "Transportmittel.h"

using namespace std;

//Getter definieren
double Transportmittel::get_hoehe() const { return hoehe; }
double Transportmittel::get_breite() const { return breite; }

//Methode "Bewegen"
void Transportmittel::bewegen(string Richtung) {
	cout << "In Richtung " + Richtung + " bewegen \n";
}