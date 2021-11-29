#include <iostream>
using namespace std;

//Hauptfunktion
int main()
{
	char input;

	system("cls");
	cout << "Herzlich Willkommen beim Kaffee-Automaten!\n"
			"Bitte w\x84hlen Sie aus:\n"
			"(k) Kaffee\n"
			"(e) Espresso\n"
			"(s) Service-Mode\n";
	cin >> input;
	cout << "Sie haben sich f\x81r Auswahl " << input << " entschieden\n";
	system("pause");
	return 0;
}