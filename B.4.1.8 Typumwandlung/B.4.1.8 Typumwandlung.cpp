#include <iostream>
#include <string>
using namespace std;

//Gibt das erste digit eines double als int zurrück
int first_digit_of_double(double input) {

	int input_rounded = static_cast<int>(round(input));							// Rundet die Eingabe und speichert sie als int
	string input_string = to_string(input_rounded);								// Konvertiert das gerundete Ergebnis zu einem String
	int input_length = static_cast<int>(input_string.length());					// Berechnet die Länge des gerundeten ints und speichert diese als int
	double input_exponentialized = input * pow(10, (-1 * (input_length-1)));	// Kommaverschiebung per Exponenten

	int first_digit = static_cast<int>(round(input_exponentialized));			//anschließend runden um nur noch 1 Stelle zu haben

	return first_digit;
}

int main()
{
	int l;
	double laenge{ 100.05 };
	char zeichen;

	// Es wird eine Zahl von double in int konvertiert, Double ist eine Kommazahl, die von Int nicht unterstützt wird. Nachkommastellen werden gerundet und weggelassen.
	// Korrektur: laenge zuerst runden und dann zu int casten
	// alt: l = laenge;
	l = static_cast<int>(round(laenge));

	// Es wird eine Zahl von Double in Char konvertiert. Die Ersten 8 Bit werden übernommen. Allerdings wird dadurch der Sinn verfälscht. Es handelt sich nicht mehr um die 1. Stelle der Zahl
	// Korrektur: das Double vorher in int umwandeln. Das int wird dann per ASCII als char interpretiert
	// alt: zeichen = laenge;
	// Alternative Lösung: Siehe eigene Funtion oberhalb von Main. Das zurrückgegebene int wirs dann an die "0" angefügt, sie dinet als Terminator für das char
	// Alternative Lösung: zeichen =  first_digit_of_double(laenge) + '0';
	zeichen = static_cast<int>(laenge);

	cout << laenge << " " << l << " " << zeichen << endl;

	/*
	Das Script nimmt eine Kommazahl mit 2 Nachkommsatellen (double) entgegen. Diese wird dann gerundet und als Ganzzahl (Int) gespeichert.
	Wenn man die Umwandlung als char "einfach" nimmt und die Warnung nur beseitigt, kann die Kommazahl vorab in eine Ganzzahl konvertiert werden. Diese wird dann als ASCII Zeichen interpretiert.

	Wenn man den Sinn der Zeile andereitig interpretiert, wird es entsprechend komplexer (Angabe des ersten Digit als Char)
	Um das zu realisieren, hatten wir Anfangs die obige Funktion geschrieben, die dann dur das Erste Zeichen der Zahl als Int zurrückgibt.
	Diese Lösung kam uns allerdings etwas zu schwer vor, aber man weiß ja nie :)

	In Cout werden die 3 einzelnen Variablen dann alle hintereinander ausgegeben.
	*/


	string messlatte{ "777.77" };
	// Die Zahl 777.77 wurde als string gespeichert und soll in double konvertiert werden. Allerdings gehört string nicht zu den elementaren Datentypen und wird daher von static_cast nicht unterstützt
	// Korrektur anstelle des cast eine eingebaute Funktion der Library, bzw. Funktion "string" benutzen --> stod() (stringtodouble)
	// alt: laenge = ststic_cast<double>(messlatte);
	laenge = stod(messlatte);
	return 1;
}