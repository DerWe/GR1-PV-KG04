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
	void set_realteil(double Realteil) {
		realteil = Realteil;
	}
	void set_imaginaerteil(double Imaginaerteil) {
		imaginaerteil = Imaginaerteil;
	}

	//Operator�berladung zur Berechnung
	Complex operator+(Complex& other) {
		return Complex(realteil + other.realteil, imaginaerteil + other.imaginaerteil);
	}
	Complex operator-(Complex& other) {
		return Complex(realteil - other.realteil, imaginaerteil - other.imaginaerteil);
	}

	friend ostream& operator<<(ostream& os, const Complex& c) {
		if (c.imaginaerteil >= 0) {
			os << c.realteil << "+" << c.imaginaerteil << "i";
		}
		else {
			os << c.realteil << c.imaginaerteil << "i";
		}
		return os;
	}

	friend istream& operator>>(istream& is, Complex& c) {
			is >> c.realteil >> c.imaginaerteil;
		return is;
	}


};