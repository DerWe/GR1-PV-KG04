#include <iostream>
#include <auto.h>
using namespace std;

class Auto
{
private:
	unsigned int radzahl;
	string farbe;
	unsigned int ps;
	unsigned int anzahl_sitze;
	float spritverbrauch;
	float tankinhalt;
	float tankgroesse;

public:
	unsigned int get_radzahl() const { return radzahl; }
	string get_farbe() const { return farbe; }
	unsigned int get_ps() const { return ps; }
	unsigned int get_anzahl_sitze() const { return anzahl_sitze; }
	float get_spritverbrauch() const { return spritverbrauch; }
	float get_tankinhalt() const { return tankinhalt; }
	float get_tankgroesse() const { return tankgroesse; }
};