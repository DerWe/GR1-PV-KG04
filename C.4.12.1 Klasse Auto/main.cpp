#include <iostream>
#include "Auto.h"
using namespace std;

void main() {

	//Test Standartkonstruktor
	Auto VWPolo;

	//Test allgemeiner Konstruktor
	Auto SkodaFabia(4, "schwarz", 69, 5, 7.5, 10, 45);
	cout << SkodaFabia.get_farbe() << endl; //erwarteter Output: schwarz

	//Test allgemeiner Konstruktor auf Heap
	Auto* Adrianspolo;
	Adrianspolo = new Auto(3, "schwarz", 69, 5, 7.5, 10, 45);
	delete Adrianspolo;

	//Test einiger Methoden
	cout << VWPolo.get_radzahl() << endl;
	cout << VWPolo.get_tankinhalt() << endl;
	cout << VWPolo.set_tankinhalt(30) << endl;
	cout << VWPolo.get_tankinhalt() << endl;
	cout << VWPolo.fahren(60.5) << endl;
	cout << VWPolo.get_tankinhalt() << endl;

	//Test Kopierkonstruktor
	Auto Adriansporsche = VWPolo;
	cout << Adriansporsche.get_anzahl_sitze() << endl; //Output: 5 (erfolgreich)



}