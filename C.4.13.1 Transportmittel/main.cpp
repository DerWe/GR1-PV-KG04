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

	//Test der Methode "ablegen"
	Tretboot.ablegen("Hamburg");

	//Test der Methode "anlegen"
	Tretboot.anlegen("Rotterdam");

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Fahrrad testen>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//Test allgemeiner Konstruktor
	cout << endl << "Fahrrad \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	Fahrrad Pedelec(0.8, 0.35, 2, 21); //es handelt sich hier um einen handelsüblichen Bollerwagen

	//Test Gettermethoden
	cout << "H\x94he des Pedelecs: " << Pedelec.get_hoehe() << endl;
	cout << "Breite des Pedelecs: " << Pedelec.get_breite() << endl;
	cout << "Radzahl des Pedelecs: " << Pedelec.get_radzahl() << endl;
	cout << "Ganganzahl des Pedelecs: " << Pedelec.get_anzahlgaenge() << endl << endl;

	//Test der Methode "freihändigfahren"
	Pedelec.freihändigfahren("Peter");

	//Test der Methode "schieben"
	Pedelec.schieben(1.1);

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Rikscha testen>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//Test allgemeiner Konstruktor
	cout << endl << "Rikscha \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	Rikscha Minikutsche(1.5, 1.0, 2, "rot"); //es handelt sich hier um eine handelsüblichen Minikutsche

	//Test Gettermethoden
	cout << "H\x94he der Minikutsche: " << Minikutsche.get_hoehe() << endl;
	cout << "Breite der Minikutsche: " << Minikutsche.get_breite() << endl;
	cout << "Radzahl der Minikutsche: " << Minikutsche.get_radzahl() << endl;
	cout << "Farbe der Minikutsche: " << Minikutsche.get_farbe() << endl << endl;

	//Test der Methode "ziehen"
	Minikutsche.ziehen(4);

	//Test der Methode "schieben"
	Minikutsche.schieben(9.1);

	//Test der geerbten Methode "fahren"
	Minikutsche.fahren(0.1);


	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Auto testen>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//Test allgemeiner Konstruktor
	cout << endl << "Auto \x81 \bber allgemeinen Konstruktor erstellt" << endl;
	xAuto BMW(1.5, 2.1, 4, 9.5); //es handelt sich hier um einen handelsüblichen BMW

	//Test Gettermethoden
	cout << "H\x94he des BMW: " << BMW.get_hoehe() << endl;
	cout << "Breite des BMW: " << BMW.get_breite() << endl;
	cout << "Radzahl des BMW: " << BMW.get_radzahl() << endl;
	cout << "Farbe des BMW: " << BMW.get_spritverbrauch() << endl << endl;

	//Test der Methode "ziehen"
	BMW.tanken(80);

	//Test der Methode "schieben"
	BMW.schieben(4.1);

	//Test der geerbten Methode "fahren"
	BMW.fahren(100.93);
}