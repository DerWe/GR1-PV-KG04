#pragma once
#include <iostream>

using namespace std;

//Prototyp der Klasse "Auto"
class Auto
{
private:
	//Variablendeklaration aller ben�tigten Variablen
	unsigned int radzahl;
	string farbe;
	unsigned int ps;
	unsigned int anzahl_sitze;
	float spritverbrauch;
	float tankinhalt;
	float tankgroesse;

public:
	//Gettermethoden f�r alle Variablen
	unsigned int get_radzahl() const;
	string get_farbe() const;
	unsigned int get_ps() const;
	unsigned int get_anzahl_sitze() const;
	float get_spritverbrauch() const;
	float get_tankinhalt() const;
	float get_tankgroesse() const;

	//Settermethode f�r Tankinhalt
	bool set_tankinhalt(float getankte_liter);

	//Methode fahren
	float fahren(float strecke);
};