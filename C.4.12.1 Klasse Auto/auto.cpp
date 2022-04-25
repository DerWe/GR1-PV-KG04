#include <iostream>
#include "auto.h"
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
	
	//Settermethode für Tankinhalt
	bool set_tankinhalt(float getankte_liter){
		//Prüfen ob gewüschte menge noch in den Tank passt
		if (getankte_liter > 0 and (this->tankinhalt + getankte_liter) <= this->tankgroesse) {
			this->tankinhalt += getankte_liter;
			return true;
		} 
		else {
			return false;
		}
	}
	//Methode fahren
	float fahren(float strecke) {
		//Prüfen ob gewüscnhte Strecke noch gefahren werden kann
		if ((abs(strecke) * this->spritverbrauch) < this->tankinhalt) {
			this->tankinhalt -= (abs(strecke) * this->spritverbrauch);
			return abs(strecke);
		}
		else
		{
			return (this->tankinhalt / this->spritverbrauch);
		}
	}
};	