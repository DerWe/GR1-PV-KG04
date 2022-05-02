#include <iostream>
#include "Datum.h"

using namespace std;

unsigned int Datum::anzahl_instanzen{ 0 };
bool Datum::plappermodus{ false };

void main() {
	Datum heute(02, 05, 2022);
	cout << heute.TagDesJahres() << endl; //erwarteter Output: 122 
	cout << Datum::IstSchaltjahr(2020) << endl;  //erwarteter Output: 1, da 2020 ein Schaltjahr war
	//9 weitere Instanzen des Typs Datum um die Warnung zu testen
	Datum heute1(02, 05, 2022);
	Datum heute2(02, 05, 2022);
	Datum heute3(02, 05, 2022);
	Datum heute4(02, 05, 2022);
	Datum heute5(02, 05, 2022);
	Datum heute6(02, 05, 2022);
	Datum heute7(02, 05, 2022);
	Datum heute8(02, 05, 2022);
	Datum heute9(02, 05, 2022);
	Datum heute10(02, 05, 2022);
}