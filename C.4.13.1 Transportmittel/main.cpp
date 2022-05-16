#include <iostream>
#include "Transportmittel.h"
using namespace std;

void main() {
	//Test allgemeiner Konstruktor
	cout << endl << "Transportmittel \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	Transportmittel Auto(1.43, 1.86); //es handelt sich hier um einen Audi A3 Sportsback

	//Test Gettermethoden
	cout << "H\x94he des Autos: " << Auto.get_hoehe() << endl;
	cout << "Breite des Autos: " << Auto.get_breite() << endl << endl;

	//Test der Methode "Bewegen"
	Auto.bewegen("x");

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Landtransportmittel testen>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//Test allgemeiner Konstruktor
	cout << endl << "Landtransportmittel \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	LandTransportmittel Bollerwagen(0.5, 1.2, 4); //es handelt sich hier um einen handelsüblichen Bollerwagen

	//Test Gettermethoden
	cout << "H\x94he des Bollerwagen: " << Bollerwagen.get_hoehe() << endl;
	cout << "Breite des Bollerwagen: " << Bollerwagen.get_breite() << endl;
	cout << "Radzahl des Bollerwagen: " << Bollerwagen.get_radzahl() << endl << endl;

	//Test der Methode "fahren"
	Bollerwagen.fahren(7.2);

	//Test der Methode "schieben"
	Bollerwagen.schieben(5.1);

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Wassertransportmittel testen>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//Test allgemeiner Konstruktor
	cout << endl << "Wassertransportmittel \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	WasserTransportmittel Tretboot(2.4, 1.8, 1.7); //es handelt sich hier um einen handelsüblichen Bollerwagen

	//Test Gettermethoden
	cout << "H\x94he des Tretboot: " << Tretboot.get_hoehe() << endl;
	cout << "Breite des Tretboot: " << Tretboot.get_breite() << endl;
	cout << "Bruttoregistriertonnen des Tretboot: " << Tretboot.get_bruttoregistriertonnen() << endl << endl;

	//Test der Methode "fahren"
	Tretboot.ablegen("Hamburg");

	//Test der Methode "schieben"
	Tretboot.anlegen("Rotterdam");
}