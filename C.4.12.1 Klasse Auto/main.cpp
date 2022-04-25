#include <iostream>
#include "Auto.h"
using namespace std;

void main() {

	//Test Standartkonstruktor
	cout << "VWPolo ueber Standartkonstruktor erstellt und Test einiger Methoden" << endl;
	Auto VWPolo;

	//Test einiger Methoden
	cout << "Raeder: " << VWPolo.get_radzahl() << endl;
	cout << "Tankinhalt: " << VWPolo.get_tankinhalt() << endl;
	cout << "Versuch zu viel zu tanken (77L): " << VWPolo.set_tankinhalt(77) << endl;
	cout << "Tankinhalt: " << VWPolo.get_tankinhalt() << endl;
	cout << "tanken (33L): " << VWPolo.set_tankinhalt(33) << endl;
	cout << "Tankinhalt: " << VWPolo.get_tankinhalt() << endl;
	cout << "Fahren: " << VWPolo.fahren(60.5) << endl;
	cout << "Tankinhalt: " << VWPolo.get_tankinhalt() << endl;
	cout << "Zu weit fahren: " << VWPolo.fahren(600.5) << endl;
	cout << "Tankinhalt: " << VWPolo.get_tankinhalt() << endl;

	//Test allgemeiner Konstruktor
	cout << endl << "SkodaFabia ueber Standartkonstruktor erstellt" << endl;
	Auto SkodaFabia(4, "schwarz", 69, 5, 7.5, 10, 45);
	cout << SkodaFabia.get_farbe() << endl; //erwarteter Output: schwarz

	//Test allgemeiner Konstruktor auf Heap
	cout << endl << "Adrianspolo im Heap erstellt und anschliessend direkt geloescht" << endl;
	Auto* Adrianspolo;
	Adrianspolo = new Auto(3, "schwarz", 69, 5, 7.5, 10, 45);
	delete Adrianspolo;

	//Test Kopierkonstruktor
	cout << endl << "Adriansporsche aus VWPolo ueber Kopierkonstruktor erstellt" << endl;
	Auto Adriansporsche = VWPolo;
	cout << "Sitzanzahl: " << Adriansporsche.get_anzahl_sitze() << endl;

	// hier weird ein ganzer Fuhrpark aus ganz Vielen Autos angelegt
	cout << endl << "Kompletten Fuhrpark aus ganz Vielen Autos anlegen" << endl;
	const int Anzahl = 5;
	Auto* Fuhrpark[Anzahl];
	for (int i = 0; i < Anzahl; ++i) {

		// Speicherplatz für ein Auto auf dem Heap reservieren und direkt in das Pointer Array der Klasse Auto gespeichert
		Fuhrpark[i] = new Auto(4, "schwarz", 69, 5, 7.5, 10, 50);
	}

	cout << endl << "Nun mit den Autos eine zufällige Strecke Fahren und sie anschließend verschrotten, um verbrauchten Speicher ('Platz auf dem Parkplatz') wieder freigeben" << endl;
	for (int i = 0; i < Anzahl; ++i) {

		cout << "Zufaellige Straecke fahren: " << Fuhrpark[i]->fahren(rand() % 200 + 1) << endl;
		cout << "Restlicher Tankinhalt: " << Fuhrpark[i]->get_tankinhalt() << endl;
		// Speicherplatz für ein Auto auf dem Heap reservieren und direkt in das Pointer Array der Klasse Auto gespeichert
		delete Fuhrpark[i];
	}

	cout << endl << "Jetzt sieht man noch wie die restlichen Autos vom Stack geloescht werden:" << endl;
}