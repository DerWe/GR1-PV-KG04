#include<iostream>
#include <math.h>

using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Funktionen für die jeweiligen Aufgaben definieren
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Mittelwert berechnen
float f_mittelwert(float werte[], int size) {	//Pointer des Arrays und die länge übergeben

	float summe = 0;							//Variablen vordefinieren
	float mittelwert = 0;

	for (int i = 0; i < size; i++) {			//Schleife durch alle Werte des Arrays
		summe += werte[i];						//Einzelwerte auf Summe aufaddieren
	}

	mittelwert = summe / size;					//Durch size teilen --> Mittelwert
	return mittelwert;							//Mittelwert als float zurrückgeben
}

//Varianz berechnen
float f_varianz(float werte[], int size) {					//Pointer des Arrays und die länge übergeben

	float mittelwert = f_mittelwert(werte, size);			//Variablen vordefinieren und Mittelwert mit obriger Funktion berechnen
	float zwischensumme = 0;
	float varianz = 0;

	for (int i = 0; i < size; i++) {						//Schleife durch alle Werte des Arrays
		zwischensumme += pow(werte[i] - mittelwert, 2);		//Messwert - Mittelwert zum Quadrat aufaddieren
	}

	varianz = zwischensumme / (size - 1);					//Zwischensumme durch N-1 Teilen
	return varianz;											//Varianz als float zurrückgeben
}

//Array komplett ausgeben
void f_printarray(float werte[], int size) {	//Pointer des Arrays und die länge übergeben

	cout << "Messwerte [m] \n"					//Kopf ausgeben
		 << "------------- \n";

	for (int i = 0; i < size; i++) {			//Schleife durch alle Werte des Arrays
		cout << werte[i] << "\n";				//Jeden Messwert mit cout ausgeben
	}
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Hauptprogramm
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(){

	//Arrays und Variablen vordefinieren
	float messwerte[] { 99.975, 100.002, 99.999, 99.982, 100.100, 100.009, 99.826, 100.547, 100.023, 100.008 };
	int messwerte_size = sizeof(messwerte) / sizeof(*messwerte);

	//Oben geschriebene Funktionen zur Berechnung des Mittelwertes und Varianz verwenden
	float mittelwert = f_mittelwert(messwerte, messwerte_size);
	float varianz = f_varianz(messwerte, messwerte_size);

	//Array der Messwerte per Funktion ausgeben
	f_printarray(messwerte, messwerte_size);
	cout << "\n";

	//Schlusszeile mit Mittelwert und Varianz ausgeben
	cout << "Mittelwert = " << mittelwert << "m Varianz = " << varianz << " quadratmeter";

	return 0;
}