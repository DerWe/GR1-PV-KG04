#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;


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
bool f_authenticate_user(char password[], int password_size) {	//Pointer des Arrays und die länge übergeben

	char user_input[6]{};										//Leeres Array für den Userinput erstellen
	bool authenticated = false;

	cout << "Bitte geben Sie das Passwort ein:";

	for (int i = 0; i < password_size-1; i++) {					//Schleife, die das Chararray in der passenden länge des Passwords abfragt
		user_input[i] = _getch();								//Input in chararray speichern
		cout << "*";
	}

	for (int i = 0; i < password_size-1; i++) {					//Schleife um die beiden chararrays zu vergleichen
		if (user_input[i] == password[i]) {						//Übereinstimmung --> Authenticated True
			authenticated = true;
		}
		else {													//Keine Übereinstimmung --> Authenticated false --> break
			authenticated = false;
			break;
		}
	}

	return authenticated;										//Return Bool ob login erfolgreich oder nicht
}

//Funktion für die Additive des Kaffees
void UI_zusaetze_kaffee(bool beide, bool* pbmilch, bool* pbzucker) {
	
	//Arbeitsvariablen definieren
	char user_input_supplements;
	bool user_input_successful = false;
	
	while (!user_input_successful){
		//Auswahlmenü Zucker
		cout << "M""\x94""chten Sie Zucker (j/n)?\n";

		//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Außerdem vorläufigen Preis berechnen
		user_input_supplements = _getch();
		if (user_input_supplements == 'j') {
			*pbzucker = true;
			user_input_successful = true;
		}
		else if (user_input_supplements == 'n') {
			*pbzucker = false;
			user_input_successful = true;
		}
		else {
			cout << "Eingabe falsch, bitte ausWahl der Zusätze wiederholen?\n";
			system("timeout 3");
			system("cls");
			user_input_successful = false;
			continue;
		}

		if (beide) {
			//Auswahlmenü Milch
			cout << "M""\x94""chten Sie Milch (j/n)?\n";

			//Char einlesen und auswerten. Bei falsche Eingabe Schleifendurchgang abbrechen. Außerdem vorläufigen Preis berechnen
			user_input_supplements = _getch();
			if (user_input_supplements == 'j') {
				*pbmilch = true;
				user_input_successful = true;
			}
			else if (user_input_supplements == 'n') {
				*pbmilch = false;
				user_input_successful = true;
			}
			else {
				cout << "Eingabe falsch, bitte ausWahl der Zusätze wiederholen?\n";
				system("timeout 3");
				system("cls");
				user_input_successful = false;
				continue;
			}
		}
	}
}

//Funktion für das Service Interface
void SI(daten kaffee) {
	// Passwort für den Servicemode
	char service_password[] = "passwd";
	int service_password_size = sizeof(service_password) / sizeof(*service_password);
	//Wenn der user Erfolgreich mit der unterfunktion authentifiziert werden konnte
	if (f_authenticate_user(service_password, service_password_size)) {
		system("cls");
		cout << "Service-Interface\n"
			"-------------------------------------------\n"
			"Noch vorhandene Mengen:\n"
			"Kaffee : " << kaffee.coffeebeens << " g Milch: " << kaffee.milk << " ml\n"
			"Espresso: " << kaffee.espressobeens << " g Wasser: " << kaffee.water << " ml\n"
			"Zucker: " << kaffee.zugar << " g\n"
			"-------------------------------------------\n"
			"Mengen pro Tasse :\n"
			"Kaffee: " << kaffee.used_beens << " g Milch: " << kaffee.used_milk << " ml\n"
			"Espresso: " << kaffee.used_beens << " g Wasser fuer Kaffee: " << kaffee.used_water_coffee << " ml\n"
			"Zucker: " << kaffee.used_zugar << " g Wasser fuer Espresso: " << kaffee.used_water_espresso << " ml\n"
			"-------------------------------------------\n";
		system("pause");
	}
	//Wenn der User nicht authentifiziert werden kann
	else {
		system("cls");
		cout << '\a';	//Error Sound abspielen
		cout << "Falsches Passwort! Zugang zum Service-Interface verweigert!\n";
		system("pause");
	}
}

//Funktion für das generelle UI
bool UI(bool* pbkaffee, bool* pbmilch, bool* pbzucker, bool* pbespresso, bool* pbservice, daten kaffee) {

	//Arbeitsvariablen definieren
	char user_input;

	//Textausgabe das Willkommensbildschirms
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
		"Preis pro Tasse:\n"
		"Kaffee oder Espresso: " << kaffee.cup << " Euro\n"
		"Milch oder Zucker: " << kaffee.supplement << " Euro\n\n"

		"Bitte w\x84hlen Sie aus:\n"
		"(k) Kaffee\n"
		"(e) Espresso\n"
		"(s) Service-Mode\n"
		"(h) System Herunterfahren\n";

	//cin >> user_input;
	//Einlesen der ausgewählten option (alternativ, per _getch --> Schöner wenn man kein Enter drücken muss)
	user_input = _getch();

	//Umsetzung des eingegebenen Buchstabens zu einem ganzen Wort. Außerdem vorläufigen Preis berechnen
	switch (user_input)
	{
	case 'k':	//Kaffee wurde ausgewählt
		*pbkaffee = true;
		//Bestätigung der Eingabe
		cout << "Sie haben sich f\x81r die Auswahl Kaffee Entschieden\n\n";
		UI_zusaetze_kaffee(true, pbmilch, pbzucker);
		return false;
	case 'e':	//Espresso wurde gewählt
		*pbespresso = true;
		//Bestätigung der Eingabe
		cout << "Sie haben sich f\x81r die Auswahl Espresso Entschieden\n\n";
		UI_zusaetze_kaffee(false, pbmilch, pbzucker);
		return false;
	case 's':	//Servicemode wurde gewählt
		*pbservice = true;
		//Bestätigung der Eingabe
		cout << "Sie haben sich f\x81r die Auswahl Service Mode Entschieden\n\n";
		SI(kaffee);
		return false;
	case 'h':	//System soll Heruntergefahren werden
		return true;
	default:
		cout << "Eingabe falsch, bitte Auswahl wiederholen?\n";
		system("timeout 3");
		return false;
	}
}

//Funktion zur Berechnung des Preises
float preis_berechnen(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten kaffee) {
	
	float preis = 0;

	//Wenn die Jeweilige Zutat benötigt wird, den Preis aufrechenen
	if (bkaffee) {
		preis += kaffee.cup;
	}
	if (bespresso) {
		preis += kaffee.cup;
	}
	if (bmilch) {
		preis += kaffee.supplement;
	}
	if (bzucker) {
		preis += kaffee.supplement;
	}

	return preis;
}

//Funktion zur Aktualiesierung der Mengen
void mengen_aktualisieren(bool bkaffee, bool bmilch, bool bzucker, bool bespresso, daten* pkaffee) {

	//Wenn die Jeweilige Zutat benötigt wird, vordefinierte Menge aus dem Speicher nehmen
	if (bkaffee) {
		pkaffee->coffeebeens -= pkaffee->used_beens;
		pkaffee->water -= pkaffee->used_water_coffee;
	}
	if (bespresso) {
		pkaffee->espressobeens -= pkaffee->used_beens;
		pkaffee->water -= pkaffee->used_water_espresso;
	}
	if (bmilch) {
		pkaffee->milk -= pkaffee->used_milk;
	}
	if (bzucker) {
		pkaffee->zugar -= pkaffee->used_zugar;
	}
}
//Hauptfunktion
int main()
{

	daten stock;

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

		//Datenstruktur initial laden
		daten kaffee;

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