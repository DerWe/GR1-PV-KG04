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
	unsigned int get_radzahl();
	string get_farbe();
	unsigned int get_ps();
	unsigned int get_anzahl_sitze();
	float get_spritverbrauch();
	float get_tankinhalt();
	float get_tankgroesse();

	//Settermethode f�r Tankinhalt
	bool set_tankinhalt(float getankte_liter);

	//Methode fahren
	float fahren(float strecke);
};