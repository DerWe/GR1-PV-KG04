#pragma once
#include <iostream>

using namespace std;

//Prototyp der Klasse "Auto"
class Auto
{
private:
	//Variablendeklaration aller benötigten Variablen
	unsigned int radzahl;
	string farbe;
	unsigned int ps;
	unsigned int anzahl_sitze;
	float spritverbrauch;
	float tankinhalt;
	float tankgroesse;

public:
	//Standartkonstruktor
	Auto()
	{
		radzahl = 4;
		farbe = "silber";
		ps = 100;
		anzahl_sitze = 5;
		spritverbrauch = 7.0;
		tankinhalt = 10;
		tankgroesse = 50;
	}

	//Allgemeiner Konstruktor
	Auto(unsigned int Radzahl, string Farbe, unsigned int Ps, unsigned int Anzahl_sitze, float Spritverbrauch, float Tankinhalt, float Tankgroesse)
	{
		radzahl = Radzahl;
		farbe = Farbe;
		ps = Ps;
		anzahl_sitze = Anzahl_sitze;
		spritverbrauch = Spritverbrauch;
		tankinhalt = Tankinhalt;
		tankgroesse = Tankgroesse;
	}

	//Kopierkonstruktor
	Auto(const Auto & c)
	{
		radzahl = c.radzahl;
		farbe = c.farbe;
		ps = c.ps;
		anzahl_sitze = c.anzahl_sitze;
		spritverbrauch = c.spritverbrauch;
		tankinhalt = c.tankinhalt;
		tankgroesse = c.tankgroesse;
	}

	//Destruktor
	~Auto()
	{
		cout << "Das Auto ist erfolgreich (ausversehen) die Klippe heruntergerollt. Passiert.... :D" << endl;
	}

	//Gettermethoden für alle Variablen
	unsigned int get_radzahl() const;
	string get_farbe() const;
	unsigned int get_ps() const;
	unsigned int get_anzahl_sitze() const;
	float get_spritverbrauch() const;
	float get_tankinhalt() const;
	float get_tankgroesse() const;

	//Settermethode für Tankinhalt
	bool set_tankinhalt(float getankte_liter);

	//Methode fahren
	float fahren(float strecke);
};