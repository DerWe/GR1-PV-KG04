#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "Kaffeeautomat.h"


using namespace std;

#define TEST


//Hauptfunktion
int main()
{

	//Datenstruktur initial laden
	daten kaffee;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Variablendeklaration
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	bool bkaffee;
	bool bespresso;
	bool bmilch;
	bool bzucker;
	bool bservice;

	float user_price;
	float user_payment;
	float user_payment_change;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Dauerschleife, für die UI des Kaffeeautomaten
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	bool herunterfahren = false;

	while (!herunterfahren) {

		//Clearen des User-Interfaces
		system("cls");

		bkaffee = false;
		bespresso = false;
		bmilch = false;
		bzucker = false;
		bservice = false;

		//Unterfunktion des UI aufrufen
		herunterfahren = UI(&bkaffee, &bmilch, &bzucker, &bespresso, &bservice, kaffee);

		//nur, wenn auch etwas bestellt wurde, Preise berechnen
		if (bkaffee or bespresso) {
			//Zurücksetzen der User Variablen
			user_price = preis_berechnen(bkaffee, bmilch, bzucker, bespresso, kaffee);
			user_payment = 0;
			user_payment_change = 0;

			//Endpreis ausgeben und den User nach Geld bitten
			cout << "Bitte " << user_price << " Euro eingeben und ENTER dr""\x81""cken: ";
			cin >> user_payment;
			cout << "\n\n";

			//Eingeschmissenes Geld auswertem --> Schauen ob es Ausreicht. Wenn nicht, Schleifendurchgang abbrechen.
			if (user_payment >= user_price) {
				user_payment_change = user_payment - user_price;
			}
			else {
				cout << "Zu wenig Geld, Bestellung abgebrochen\n";
				system("pause");
				continue;
			}

			mengen_aktualisieren(bkaffee, bmilch, bzucker, bespresso, &kaffee);

			PRINTSTRING("Debug mode Aktiv, Verbleibend sind folgende Mengen");	//Debug Output
			PRINTVARIABLE(kaffee.coffeebeens);									//Gibt die Verbleibenden Mengen im Speicher aus
			PRINTVARIABLE(kaffee.espressobeens);
			PRINTVARIABLE(kaffee.milk);
			PRINTVARIABLE(kaffee.zugar);
			PRINTVARIABLE(kaffee.water);

			//Wenn bisher nicht abgebrochen, Getränkeausgabe Ligitimiert
			cout << "Ihr Getr\x84nk wird zubereitet";
			for (int i = 0; i < 4; i++) {	//Kleine Spielerei, dass der Zubereitungsprozess simuliert wird (Wartebalken)
				Sleep(800);
				cout << ".";
			}
			cout << "\n";

			//Benachrichtigung, dass das Getränk fertig ist & Rückgeld geben
			cout << "Bitte " << user_payment_change << " Euro R""\x81""ckgeld und das Getr\x84nk entnehmen -:)\n\n";
			system("pause");
		}
	}
	return 0;
}