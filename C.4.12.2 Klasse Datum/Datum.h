#pragma once

#include <iostream>

using namespace std;

class Datum
{
private:
	unsigned int tag;
	unsigned int monat;
	unsigned int jahr;

public:

	//Standartkonstruktor
	Datum(unsigned int Tag, unsigned int Monat, unsigned int Jahr)
	{
		tag = Tag;
		monat = Monat;
		jahr = Jahr;
	}

	//Klassenmethode IstSchaltjahr
	static int IstSchaltjahr(int irgendeinJahr) {
		if ((irgendeinJahr%4 == 0) and (irgendeinJahr%100 != 0) or (irgendeinJahr%400 == 0))
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
		int tagesanzahl = 0;

		//Alle vollen Monate bis zum Datum Durchlaufen
		for (int i_monat = 1; i_monat < this->monat; i_monat++) {

			//Auswerten wie Viele Tage der gerade durchlaufene Monat hat
			switch (this->monat)
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

			//Monate mit 30 Tagen
			case 4:
			case 6:
			case 9:
			case 11:
				tagesanzahl += 30;

			//Separate betrachtung des Februar, aufgrund der Schaltjahresthematik
			case 2:
				if (IstSchaltjahr(this->jahr) == 1) {
					tagesanzahl += 29;

				}
				else {
					tagesanzahl += 28;
				}
			}
		}
		// Restliche Tage im angefangenen Monat hinzu addieren
		tagesanzahl += this->tag;
		return tagesanzahl;
	}
};