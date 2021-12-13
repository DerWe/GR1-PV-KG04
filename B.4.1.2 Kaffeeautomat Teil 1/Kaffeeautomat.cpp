#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

//Hauptfunktion
int main()
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Variablendeklaration
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	char user_input;
	char user_input_supplements;
	string user_product;
	bool user_milk;
	bool user_zugar;
	float user_price;
	float user_payment;
	float user_payment_change;


	// VorratsVariablen
	unsigned int coffeebeens	= 1000;
	unsigned int espressobeens	= 1000;
	unsigned int water			= 5000;
	unsigned int milk			= 1000;
	unsigned int zugar			= 500;

	// Portionsmengen pro Tasse
	const unsigned int used_beens			= 5;
	const unsigned int used_water_coffee	= 125;
	const unsigned int used_water_espresso	= 25;
	const unsigned int used_milk			= 25;
	const unsigned int used_zugar			= 25;

	//Preise
	const float cup		= 1.0f;
	const float supplement	= 0.1f;


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Dauerschleife, für die UI des Kaffeeautomaten
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	while (true) {

		//Clearen des User-Interfaces
		system("cls");

		//Zurücksetzen der User Variablen
		user_price = 0;
		user_payment = 0;
		user_payment_change = 0;

		//Textausgabe das Willkommensbildschirms
		cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Preis pro Tasse:\n"
			"Kaffee oder Espresso: " << cup << " Euro\n"
			"Milch oder Zucker: " << supplement << " Euro\n\n"

			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";

		//cin >> user_input;
		//Einlesen der ausgewählten option (alternativ, per _getch --> Schöner wenn man kein Enter drücken muss)
		user_input = _getch();

		//Umsetzung des eingegebenen Buchstabens zu einem ganzen Wort. Außerdem vorläufigen Preis berechnen
		switch (user_input)
		{
		case 'k':	//Kaffee wurde ausgewählt
			user_product = "Kaffee";
			user_price += cup;
			break;
		case 'e':	//Espresso wurde gewählt
			user_product = "Espresso";
			user_price += cup;
			break;
		case 's':	//Servicemode wurde gewählt
			system("cls");
			user_product = "Service-Mode";
			cout << "Service-Interface\n"
					"-------------------------------------------\n"
					"Noch vorhandene Mengen:\n"
					"Kaffee : "<< coffeebeens <<" g Milch: "<< milk <<" ml\n"
					"Espresso: "<< espressobeens <<" g Wasser: "<< water <<" ml\n"
					"Zucker: "<< zugar <<" g\n"
					"-------------------------------------------\n"
					"Mengen pro Tasse :\n"
					"Kaffee: "<< used_beens <<" g Milch: "<< used_milk <<" ml\n"
					"Espresso: "<< used_beens <<" g Wasser fuer Kaffee: "<< used_water_coffee <<" ml\n"
					"Zucker: "<< used_zugar <<" g Wasser fuer Espresso: "<< used_water_espresso <<" ml\n"
					"-------------------------------------------\n";
			system("pause");
			continue;
		default:	// Wenn nichts passendes gefunden wurde, breche ab und beginne von vorne
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		//Bestätigung der Eingabe
		cout << "Sie haben sich f\x81r die Auswahl " << user_product << " Entschieden\n\n";

		//Auswahlmenü Zucker
		cout << "M""\x94""chten Sie Zucker (j/n)?\n";

		//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Außerdem vorläufigen Preis berechnen
		user_input_supplements = _getch();
		if (user_input_supplements == 'j') {
			user_zugar = true;
			user_price += supplement;
		}
		else if (user_input_supplements == 'n') {
			user_zugar = false;
		}
		else {
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		//Auswahlmenü Milch
		cout << "M""\x94""chten Sie Milch (j/n)?\n";

		//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Außerdem vorläufigen Preis berechnen
		user_input_supplements = _getch();
		if (user_input_supplements == 'j') {
			user_milk = true;
			user_price += supplement;
		}
		else if (user_input_supplements == 'n') {
			user_milk = false;
		}
		else {
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

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

		//Wenn bisher nicht abgebrochen, Getränkeausgabe Ligitimiert
		cout << "Ihr Getr\x84nk wird zubereitet";
		for (int i = 0; i < 4; i++) {	//Kleine Spielerei, dass der Zubereitungsprozess simuliert wird (Wartebalken)
			Sleep(800);
			cout << ".";
		}
		cout << "\n";

		// Die Verbrauchten Zutatenmenge aus dem Bestand nehmen
		if (user_input == 'k') {
			coffeebeens -= used_beens;
			water -= used_water_coffee;
		}
		else if (user_input == 'e') {
			espressobeens -= used_beens;
			water -= used_water_coffee;
		}
		if (user_zugar) {
			zugar -= used_milk;
		}
		if (user_milk) {
			milk -= used_milk;
		}

		//Benachrichtigung, dass das Getränk fertig ist & Rückgeld geben
		cout << "Bitte " << user_payment_change << " Euro R""\x81""ckgeld und das Getr\x84nk entnehmen -:)\n\n";
		system("pause");
	}
	system("pause");
	return 0;
}