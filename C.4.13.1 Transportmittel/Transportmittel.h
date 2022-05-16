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

class LandTransportmittel : public Transportmittel
{
public:
	//Methode fahren
	virtual void fahren(double km);

	//Methode schieben
	virtual void schieben(double km);

	//Getter für alle Variablen
	double get_radzahl() const;

	//Allgemeiner Konstruktor für beide Klassen
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
	//Methode anlegen
	void anlegen(string Anlegehafen);

	//Methode ablegen
	void ablegen(string Ablegehafen);

	//Getter für alle Variablen
	double get_bruttoregistriertonnen() const;

	//Allgemeiner Konstruktor für beide Klassen
	WasserTransportmittel(double Hoehe, double Breite, double Bruttoregistriertonnen) : Transportmittel(Hoehe, Breite)
	{
		bruttoregistriertonnen = Bruttoregistriertonnen;
	}

private:
	double bruttoregistriertonnen;
};

class Fahrrad : public LandTransportmittel
{
private:
	int anzahlgaenge;

public: 
	//Methode freihändigfahren
	void freihändigfahren(string name);

	//Methode schieben
	void schieben(double km) override;

	//Getter für alle Variablen
	int get_anzahlgaenge() const;

	//Allgemeiner Konstruktor für beide Klassen
	Fahrrad(double Hoehe, double Breite, int Radzahl, int Anzahlgaenge) : LandTransportmittel(Hoehe, Breite, Radzahl)
	{
		anzahlgaenge = Anzahlgaenge;
	}
};

class Rikscha : public LandTransportmittel
{
private:
	string farbe;

public:
	//Methode ziehen
	void ziehen(int anzahlpersonen);

	//Methode schieben
	void schieben(double km) override;

	//Getter für alle Variablen
	string get_farbe() const;

	//Allgemeiner Konstruktor für beide Klassen
	Rikscha(double Hoehe, double Breite, int Radzahl, string Farbe) : LandTransportmittel(Hoehe, Breite, Radzahl)
	{
		farbe = Farbe;
	}
};

class xAuto : public LandTransportmittel
{
private:
	double spritverbrauch;

public:
	//Methode tanken
	void tanken(int liter);

	//Methode fahren
	void fahren(double km) override;

	//Getter für alle Variablen
	double get_spritverbrauch() const;

	//Allgemeiner Konstruktor für beide Klassen
	xAuto(double Hoehe, double Breite, int Radzahl, double Spritverbrauch) : LandTransportmittel(Hoehe, Breite, Radzahl)
	{
		spritverbrauch = Spritverbrauch;
	}
};