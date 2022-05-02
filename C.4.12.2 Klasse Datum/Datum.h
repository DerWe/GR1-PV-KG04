#pragma once

#include <iostream>

using namespace std;

class Datum
{
private:
	unsigned int tag;
	unsigned int monat;
	unsigned int jahr;
	static unsigned int anzahl_instanzen;
	unsigned int instanznummer;
	static bool plappermodus;

public:

	//Standartkonstruktor
	Datum(unsigned int Tag, unsigned int Monat, unsigned int Jahr)
	{
		tag = Tag;
		monat = Monat;
		jahr = Jahr;
		instanznummer = anzahl_instanzen;

		if (plappermodus)
		{
			cout << "Datumsinstanz Nummer " << this->instanznummer << " wurde erstellt." << endl;
		}

		if (anzahl_instanzen >= 10) {
			cout << "Es wurden mehr als 10 Instanzen vom Typ Datum erstellt!" << endl;
		}
		anzahl_instanzen++;
	}

	//Destruktor
	~Datum() {
		anzahl_instanzen--;
		if (plappermodus)
		{
			cout << "Datumsinstanz Nummer " << this->instanznummer << " wurde gelöscht." << endl;
		}
	}

	//Klassenmethode IstSchaltjahr
	static int IstSchaltjahr(int irgendeinJahr) {

		if (plappermodus)
		{
			cout << "Methode IstSchaltjahr() wurde aufgerufen." << endl;
		}

		if ((irgendeinJahr % 4 == 0) and (irgendeinJahr % 100 != 0) or (irgendeinJahr % 400 == 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//Klassenmethode TagDesJahres
	int TagDesJahres() {

		if (plappermodus)
		{
			cout << "Methode TagDesJahres() der Instanz Nummer " << this->instanznummer <<" wurde aufgerufen." << endl;
		}

		int tagesanzahl = 0;

		//Alle vollen Monate bis zum Datum Durchlaufen
		for (int i_monat = 1; i_monat < this->monat; i_monat++) {

			//Auswerten wie Viele Tage der gerade durchlaufene Monat hat
			switch (i_monat)
			{
				//Monate mit 31 Tagen
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				tagesanzahl += 31;
				break;

				//Monate mit 30 Tagen
			case 4:
			case 6:
			case 9:
			case 11:
				tagesanzahl += 30;
				break;

				//Separate betrachtung des Februar, aufgrund der Schaltjahresthematik
			case 2:
				if (IstSchaltjahr(this->jahr) == 1) {
					tagesanzahl += 29;
					break;
				}
				else {
					tagesanzahl += 28;
					break;
				}
			}
		}
		// Restliche Tage im angefangenen Monat hinzu addieren
		tagesanzahl += this->tag;
		return tagesanzahl;
	}

	static void Plappern(bool flag) {
		plappermodus = flag;
	}
};