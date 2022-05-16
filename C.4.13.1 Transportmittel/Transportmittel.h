#pragma once

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Transportmittel
{
public:
	//Allgemeiner Konstruktor
	Transportmittel(double Hoehe, double Breite)
	{
		hoehe = Hoehe;
		breite = Breite;
	}

	//Methode bewegen
	void bewegen(string Richtung);

	//Getter für alle Variablen
	double get_hoehe() const;
	double get_breite() const;

private:
	double hoehe;
	double breite;
};