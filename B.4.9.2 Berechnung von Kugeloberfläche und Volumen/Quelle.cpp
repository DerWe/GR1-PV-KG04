#define _USE_MATH_DEFINES	//Lee fest, dass cmath auch Konstanten, wie PI definieren soll

#include <iostream>
#include <cmath>

using namespace std;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Funktion zur Berechnung von Oberfl�che + Volumen einer Kugel
bool berechne_kugeldaten(float radius, double* oberfl�che, double* volumen) {

	if (radius > 0) {								//Pr�fe ob radius positiv
		*oberfl�che = 4 * M_PI * pow(radius, 2);	//Berechne die Oberfl�che und speichere es in der Pointervariablen
		*volumen = 4 * M_PI * pow(radius, 3) / 3;	//Berechne das Volumen und speichere es in der Pointervariablen
		return true;								//gebe True zurr�ck
	}
	else {
		return false;								//gebe false zurr�ck wenn der Radius nicht positiv war
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Hauptprogramm
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {

	//Variablen initial definieren

	double oberfl�che = 0;
	double volumen = 0;
	float radius = 5;

	//Funktion mit den Parametern (teilweise umgewandelt als Pointer) ausf�hren. R�ckgabe dem Bool Success zuweisen
	bool success = berechne_kugeldaten(radius, &oberfl�che, &volumen);

	//Formatierte Ausgabe wenn die Berechnung erfolgreich war
	if (success) {
		cout << "Die Kugel hat die folgenden Daten \n"
			<< "Radius:" << radius << "\n"
			<< "Oberflaeche:" << oberfl�che << "\n"
			<< "Volumen:" << volumen << "\n";
	}
	//Beschreibung eines m�glichen Fehlers bei nicht erfolgreicher Berechnung
	else {
		cout << "Berechnung konnte nicht durchgefuehrt werden. Radius negativ!";
	}
}