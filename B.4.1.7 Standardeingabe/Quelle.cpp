#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//eigene Funktion, um int in String zu wandeln (angelehnt an den Lösungshinweis im Script)
string converttostring(int zahl) {
	ostringstream wandler;
	wandler << zahl;
	return wandler.str();
}

//Hauptfunktion
int main()
{
	//Deklaration aller Variablen
	string vorname;
	string nachname;
	int postleitzahl;
	string wohnort;
	string straßenname;
	int hausnummer;
	string ausgabe;

	system("cls");

	// NAch und nach alle Eingaben abfragen und in Variablen überladen
	cout << "Hallo, bitte geben sie ihren Vornamen ein\n";
	cin >> vorname;
	
	cout << "Bitte geben sie ihren Nachnamen ein\n";
	cin >> nachname;

	cout << "Bitte geben sie ihre Postleitzahl ein\n";
	cin >> postleitzahl;

	cout << "Bitte geben sie ihren Wohnort ein\n";
	cin >> wohnort;

	cout << "Bitte geben sie ihren Stra" << "\xE1" << "enamen ein\n";
	cin >> straßenname;

	cout << "Bitte geben sie ihre Hausnummer ein\n";
	cin >> hausnummer;

	//Ausgabestring zusammensetzen und formatieren (hier findet auch die konvertierung von in > string statt)
	ausgabe =
			vorname + " " + nachname + "\n" + 
			converttostring(postleitzahl) + " " + wohnort + "\n" +
			straßenname + " " + converttostring(hausnummer) + "\n";

	//Eingabeausforderung nochmal Clearen, zur beseren Übersicht
	system("cls");

	//String ausgeben
	cout << ausgabe;

	system("pause");
	return 0;
}