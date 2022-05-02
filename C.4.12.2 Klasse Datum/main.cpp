#include <iostream>
#include "Datum.h"

using namespace std;

unsigned int Datum::anzahl_instanzen{ 0 };

void main() {
	Datum heute(02, 05, 2022);
	cout << heute.TagDesJahres() << endl; //erwarteter Output: 122 
	cout << Datum::IstSchaltjahr(2020);  //erwarteter Output: 1, da 2020 ein Schaltjahr war
}