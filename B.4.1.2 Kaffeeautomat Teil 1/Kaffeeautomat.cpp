#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen definieren
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Funktion f�r die Authorisierung eines Users
bool f_authenticate_user(char password[], int password_size) {	//Pointer des Arrays und die l�nge �bergeben

	char user_input[6]{};										//Leeres Array f�r den Userinput erstellen
	bool authenticated = false;

	cout << "Bitte geben Sie das Passwort ein:";

	for (int i = 0; i < password_size-1; i++) {					//Schleife, die das Chararray in der passenden l�nge des Passwords abfragt
		user_input[i] = _getch();								//Input in chararray speichern
		cout << "*";
	}

	for (int i = 0; i < password_size-1; i++) {					//Schleife um die beiden chararrays zu vergleichen
		if (user_input[i] == password[i]) {						//�bereinstimmung --> Authenticated True
			authenticated = true;
		}
		else {													//Keine �bereinstimmung --> Authenticated false --> break
			authenticated = false;
			break;
		}
	}

	return authenticated;										//Return Bool ob login erfolgreich oder nicht
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Struct Definition
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Daten f�r das Vorratsmanagement und Verbrauchsmanagement
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
	const unsigned int used_milk = 25;
	const unsigned int used_zugar = 25;

	//Preise
	const float cup = 1.0f;
	const float supplement = 0.1f;
};

//Hauptfunktion
int main()
{

	daten stock;

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

	// Passwort f�r den Servicemode
	char service_password[] = "passwd";
	int service_password_size = sizeof(service_password) / sizeof(*service_password);

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Dauerschleife, f�r die UI des Kaffeeautomaten
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	while (true) {

		//Clearen des User-Interfaces
		system("cls");

		//Zur�cksetzen der User Variablen
		user_price = 0;
		user_payment = 0;
		user_payment_change = 0;

		//Textausgabe das Willkommensbildschirms
		cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Preis pro Tasse:\n"
			"Kaffee oder Espresso: " << stock.cup << " Euro\n"
			"Milch oder Zucker: " << stock.supplement << " Euro\n\n"

			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";

		//cin >> user_input;
		//Einlesen der ausgew�hlten option (alternativ, per _getch --> Sch�ner wenn man kein Enter dr�cken muss)
		user_input = _getch();

		//Umsetzung des eingegebenen Buchstabens zu einem ganzen Wort. Au�erdem vorl�ufigen Preis berechnen
		switch (user_input)
		{
		case 'k':	//Kaffee wurde ausgew�hlt
			user_product = "Kaffee";
			user_price += stock.cup;
			break;
		case 'e':	//Espresso wurde gew�hlt
			user_product = "Espresso";
			user_price += stock.cup;
			break;
		case 's':	//Servicemode wurde gew�hlt
			system("cls");
			user_product = "Service-Mode";

			//Wenn der user Erfolgreich mit der unterfunktion authentifiziert werden konnte
			if (f_authenticate_user(service_password, service_password_size)) {
				system("cls");
				cout << "Service-Interface\n"
						"-------------------------------------------\n"
						"Noch vorhandene Mengen:\n"
						"Kaffee : " << stock.coffeebeens << " g Milch: " << stock.milk << " ml\n"
						"Espresso: " << stock.espressobeens << " g Wasser: " << stock.water << " ml\n"
						"Zucker: " << stock.zugar << " g\n"
						"-------------------------------------------\n"
						"Mengen pro Tasse :\n"
						"Kaffee: " << stock.used_beens << " g Milch: " << stock.used_milk << " ml\n"
						"Espresso: " << stock.used_beens << " g Wasser fuer Kaffee: " << stock.used_water_coffee << " ml\n"
						"Zucker: " << stock.used_zugar << " g Wasser fuer Espresso: " << stock.used_water_espresso << " ml\n"
						"-------------------------------------------\n";
				system("pause");
			}
			//Wenn der User nicht authentifiziert werden kann
			else {
				system("cls");
				cout << "Falsches Passwort! Zugang zum Service-Interface verweigert!\n";
				system("pause");
			}
			continue;
		default:	// Wenn nichts passendes gefunden wurde, breche ab und beginne von vorne
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		//Best�tigung der Eingabe
		cout << "Sie haben sich f\x81r die Auswahl " << user_product << " Entschieden\n\n";

		//Auswahlmen� Zucker
		cout << "M""\x94""chten Sie Zucker (j/n)?\n";

		//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Au�erdem vorl�ufigen Preis berechnen
		user_input_supplements = _getch();
		if (user_input_supplements == 'j') {
			user_zugar = true;
			user_price += stock.supplement;
		}
		else if (user_input_supplements == 'n') {
			user_zugar = false;
		}
		else {
			cout << "Falsche Eingabe!\n";
			system("pause");
			continue;
		}

		//Auswahlmen� Milch
		cout << "M""\x94""chten Sie Milch (j/n)?\n";

		//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Au�erdem vorl�ufigen Preis berechnen
		user_input_supplements = _getch();
		if (user_input_supplements == 'j') {
			user_milk = true;
			user_price += stock.supplement;
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

		//Wenn bisher nicht abgebrochen, Getr�nkeausgabe Ligitimiert
		cout << "Ihr Getr\x84nk wird zubereitet";
		for (int i = 0; i < 4; i++) {	//Kleine Spielerei, dass der Zubereitungsprozess simuliert wird (Wartebalken)
			Sleep(800);
			cout << ".";
		}
		cout << "\n";

		// Die Verbrauchten Zutatenmenge aus dem Bestand nehmen
		if (user_input == 'k') {
			stock.coffeebeens -= stock.used_beens;
			stock.water -= stock.used_water_coffee;
		}
		else if (user_input == 'e') {
			stock.espressobeens -= stock.used_beens;
			stock.water -= stock.used_water_coffee;
		}
		if (user_zugar) {
			stock.zugar -= stock.used_milk;
		}
		if (user_milk) {
			stock.milk -= stock.used_milk;
		}

		//Benachrichtigung, dass das Getr�nk fertig ist & R�ckgeld geben
		cout << "Bitte " << user_payment_change << " Euro R""\x81""ckgeld und das Getr\x84nk entnehmen -:)\n\n";
		system("pause");
	}
	system("pause");
	return 0;
}