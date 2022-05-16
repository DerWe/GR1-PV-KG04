#include <iostream>
#include "Transportmittel.h"
using namespace std;

void main() {
	//Test allgemeiner Konstruktor
	cout << endl << "Transportmittel \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	Transportmittel Auto(1.43, 1.86);

	//Test Gettermethoden
	cout << "H\x94he des Autos: " << Auto.get_hoehe() << endl;
	cout << "Breite des Autos: " << Auto.get_breite() << endl << endl;

	//Test der Methode "Bewegen"
	Auto.bewegen("x");
}