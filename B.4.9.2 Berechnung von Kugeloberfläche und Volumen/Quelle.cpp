#define _USE_MATH_DEFINES	//Lee fest, dass cmath auch Konstanten, wie PI definieren soll

#include <iostream>
#include <cmath>

using namespace std;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Funktion zur Berechnung von Oberfläche + Volumen einer Kugel
bool berechne_kugeldaten(float radius, double* oberfläche, double* volumen) {

	if (radius > 0) {								//Prüfe ob radius positiv
		*oberfläche = 4 * M_PI * pow(radius, 2);	//Berechne die Oberfläche und speichere es in der Pointervariablen
		*volumen = 4 * M_PI * pow(radius, 3) / 3;	//Berechne das Volumen und speichere es in der Pointervariablen
		return true;								//gebe True zurrück
	}
	else {
		return false;								//gebe false zurrück wenn der Radius nicht positiv war
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Hauptprogramm
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {

	//Variablen initial definieren

	double oberfläche = 0;
	double volumen = 0;
	float radius = 5;

	//Funktion mit den Parametern (teilweise umgewandelt als Pointer) ausführen. Rückgabe dem Bool Success zuweisen
	bool success = berechne_kugeldaten(radius, &oberfläche, &volumen);

	//Formatierte Ausgabe wenn die Berechnung erfolgreich war
	if (success) {
		cout << "Die Kugel hat die folgenden Daten \n"
			<< "Radius:" << radius << "\n"
			<< "Oberflaeche:" << oberfläche << "\n"
			<< "Volumen:" << volumen << "\n";
	}
	//Beschreibung eines möglichen Fehlers bei nicht erfolgreicher Berechnung
	else {
		cout << "Berechnung konnte nicht durchgefuehrt werden. Radius negativ!";
	}
}