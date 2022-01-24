//Stellt sicher, dass diese Headerdatei nur ein mal in einer cpp Datei includet werden kann.
#pragma once

// nur wenn TEST definiert wurde, tut das Makro etwas
//Das #X steht für den verhandenen code als solchen. mit dem # wird dieser 1:1 genommen, hier eingesetzt und weiterverarbeitet. Dieser kann bei Bedarf erweitert werden.
//#define TEST
#ifdef TEST
#define TESTAUSGABE(X) X												//Führt ein beliebiges testcommand aus
#define PRINTVARIABLE(X) cout << endl << (#X) << "=" << (X) << endl		//Nimmt eine Variable entgegen und gibt dessen Namen mit ihrem Wert aus
#define PRINTSTRING(X) cout << endl << X << endl						//Gibt Debug Text aus
#else
#define TESTAUSGABE(X)		//Mache nichts
#define PRINTVARIABLE(X)	//Mache nichts
#define PRINTSTRING(X)		//Mache nichts
#endif


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Struct Definition
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Daten für das Vorratsmanagement und Verbrauchsmanagement

struct daten {
	// VorratsVariablen
	unsigned int coffeebeens = 1000;
	unsigned int espressobeens = 1000;
	unsigned int water = 5000;
	unsigned int milk = 1000;
	unsigned int zugar = 500;

	// Portionsmengen pro Tasse
	const unsigned int used_beens = 5;
	const unsigned int used_water_coffee = 125;
	const unsigned int used_water_espresso = 25;
	const unsigned int used_milk = 30;
	const unsigned int used_zugar = 3;

	//Preise
	const float cup = 1.0f;
	const float supplement = 0.1f;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen definieren
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Funktion für die Authorisierung eines Users
bool f_authenticate_user(char password[], int password_size);

//Funktion für die Additive des Kaffees
void UI_zusaetze_kaffee(bool beide, bool* pbmilch, bool* pbzucker);

//Funktion für das Service Interface
void SI(daten kaffee);

//Funktion für das generelle UI
bool UI(bool* pbkaffee, bool* pbmilch, bool* pbzucker, bool* pbespresso, bool* pbservice, daten kaffee);

//Funktion zur Berechnung des Preises
float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee);

//Funktion zur Aktualiesierung der Mengen
void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten* pkaffee);