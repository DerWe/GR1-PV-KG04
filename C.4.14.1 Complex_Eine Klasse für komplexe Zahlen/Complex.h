#pragma once
#include <iostream>

using namespace std;

//Klasse "Complex"
class Complex {
private:
	double realteil;
	double imaginaerteil;

public:
	//Allgemeiner Konstruktor
	Complex(double Realteil, double Imaginaerteil)
	{
		realteil = Realteil;
		imaginaerteil = Imaginaerteil;
	}

	//Gettermethoden f�r alle Variablen
	double get_realteil() {
		return realteil;
	}
	double get_imaginaerteil() {
		return imaginaerteil;
	}

	//Settermethoden f�r Real- und Imagin�rteil
	double set_realteil(double Realteil) {
		realteil = Realteil;
	}
	double set_imaginaerteil(double Imaginaerteil) {
		imaginaerteil = Imaginaerteil;
	}

	//Methode Addieren
	string addieren(double TeilComplex);
	string subtrahieren(double TeilComplex);
};