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
	double get_realteil() const;
	double get_imaginaerteil() const;

	//Settermethoden f�r Real- und Imagin�rteil
	double set_realteil();
	double set_imaginaerteil();

	//Methode Addieren
	string addieren(double TeilComplex);
	string subtrahieren(double TeilComplex);
};