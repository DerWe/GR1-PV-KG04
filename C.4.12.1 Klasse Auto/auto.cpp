#include <iostream>
#include "Auto.h"

using namespace std;

unsigned int Auto::get_radzahl() const { return radzahl; }
string Auto::get_farbe() const { return farbe; }
unsigned int Auto::get_ps() const { return ps; }
unsigned int Auto::get_anzahl_sitze() const { return anzahl_sitze; }
float Auto::get_spritverbrauch() const { return spritverbrauch; }
float Auto::get_tankinhalt() const { return tankinhalt; }
float Auto::get_tankgroesse() const { return tankgroesse; }

//Settermethode für Tankinhalt
bool Auto::set_tankinhalt(float getankte_liter) {
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
float Auto::fahren(float strecke) {
	//Prüfen ob gewüscnhte Strecke noch gefahren werden kann
	if ((abs(strecke) * (this->spritverbrauch/100)) < this->tankinhalt) {
		this->tankinhalt -= (abs(strecke) * (this->spritverbrauch/100));
		return abs(strecke);
	}
	else
	{
		return (this->tankinhalt / (this->spritverbrauch/100));
	}
}