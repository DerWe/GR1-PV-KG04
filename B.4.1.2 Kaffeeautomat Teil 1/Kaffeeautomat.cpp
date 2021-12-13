#include <iostream>
#include <conio.h>
using namespace std;

//Hauptfunktion
int main()
{
	//Variablendeklaration
	char input;

	//Clearen des User-Interfaces
	system("cls");

	//Textausgabe
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";
	//cin >> input;
	//Einlesen der ausgewählten option
	input = _getch();

	//Umwandlung der Auswahl.  Variable in einString und Ausgabe
	switch (input)
	{
	case 'k':
		cout << "Sie haben sich f\x81r Auswahl Kaffee entschieden.\n";
		break;
	case 'e':
		cout << "Sie haben sich f\x81r Auswahl Espresso entschieden.\n";
		break;
	case 's':
		cout << "Sie haben sich f\x81r Auswahl Service-Mode entschieden.\n";
	default:
		break;
	}
	system("pause");
	return 0;
}