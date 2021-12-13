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
	string user_product;
	bool user_milk;
	bool user_zugar;
	float user_price = 0;
	float user_payment = 0;
	float user_payment_change = 0;


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
	const float cup		= 1.0;
	const float supplement	= 0.1;


	while (true) {

		//Clearen des User-Interfaces
		system("cls");

		//Zurücksetzen der User Variablen
		user_price = 0;
		user_payment = 0;
		user_payment_change = 0;

		//Textausgabe
		cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Preis pro Tasse:\n"
			"Kaffee oder Espresso: " << cup << " Euro\n"
			"Milch oder Zucker: " << supplement << " Euro\n\n"

			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";

		//cin >> input;
		//Einlesen der ausgewählten option
		user_input = _getch();

		//Umwandlung der Auswahl.  Variable in einString und Ausgabe
		switch (user_input)
		{
		case 'k':
			user_product = "Kaffee";
			break;
		case 'e':
			user_product = "Espresso";
			break;
		case 's':
			user_product = "Service-Mode";
			break;
		default:
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		cout << "Sie haben sich f\x81r die Auswahl " << user_product << " Entschieden\n\n";
		cout << "M""\x94""chten Sie Zucker (j/n)?\n";

		if (_getch() == 'j') {
			user_zugar = true;
		}
		else if (_getch() == 'n') {
			user_zugar = false;
		}
		else {
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		cout << "M""\x94""chten Sie Milch (j/n)?\n";

		if (_getch() == 'j') {
			user_milk = true;
		}
		else if (_getch() == 'n') {
			user_milk = false;
		}
		else {
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		if (user_input == 'k') {
			user_price += cup;
		}
		else if (user_input == 'e') {
			user_price += cup;
		}
		if (user_zugar) {
			user_price += supplement;
		}
		if (user_milk) {
			user_price += supplement;
		}

		cout << "Bitte " << user_price << " Euro eingeben und ENTER dr""\x81""cken: ";
		cin >> user_payment;
		cout << "\n\n";

		if (user_payment >= user_price) {
			user_payment_change = user_payment - user_price;
		}
		else {
			cout << "Zu wenig Geld, Bestellung abgebrochen\n";
			system("pause");
			continue;
		}

		cout << "Ihr Getr\x84nk wird zubereitet";

		for (int i = 0; i < 4; i++) {
			Sleep(800);
			cout << ".";
		}

		cin << "\n";

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

		cout << "Bitte " << user_payment_change << " Euro R""\x81""ckgeld und das Getr\x84nk entnehmen -:)\n\n";
		system("pause");
	}
	system("pause");
	return 0;
}