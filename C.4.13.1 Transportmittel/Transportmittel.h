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

	//Getter f�r alle Variablen
	double get_hoehe() const;
	double get_breite() const;

private:
	double hoehe;
	double breite;
};

class LandTransportmittel : public Transportmittel
{
public:
	void fahren(double km);
	void schieben(double km);

	//Getter f�r alle Variablen
	double get_radzahl() const;

	//Allgemeiner Konstruktor f�r beide Klassen
	LandTransportmittel(double Hoehe, double Breite, int Radzahl) : Transportmittel(Hoehe, Breite)
	{	
		radzahl = Radzahl;
	}

private:
	int radzahl;
};

class WasserTransportmittel : public Transportmittel
{
public:
	void anlegen(string Anlegehafen);
	void ablegen(string Ablegehafen);

	//Getter f�r alle Variablen
	double get_bruttoregistriertonnen() const;

	//Allgemeiner Konstruktor f�r beide Klassen
	WasserTransportmittel(double Hoehe, double Breite, double Bruttoregistriertonnen) : Transportmittel(Hoehe, Breite)
	{
		bruttoregistriertonnen = Bruttoregistriertonnen;
	}

private:
	double bruttoregistriertonnen;
};