#include <iostream>
#include "Datum.h"

using namespace std;

unsigned int Datum::anzahl_instanzen{ 0 };
bool Datum::plappermodus{ false };

void main() {
	cout << endl << "Testen der klassenmethoden ohne Plappermodus" << endl;

	//Durchlaufen sämtlicher Tests (Instanziren, TagDesJahres und IstSchaltjahr
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

	cout << endl << "Testen des Plappermodus" << endl;

	//Aktivieren des Plappermodus
	Datum::Plappern(true);

	//Durchlaufen sämtlicher Tests (Instanziren, TagDesJahres und IstSchaltjahr
	Datum morgen(03, 05, 2022);
	cout << morgen.TagDesJahres() << endl; //erwarteter Output: 122 
	cout << Datum::IstSchaltjahr(2020) << endl;  //erwarteter Output: 1, da 2020 ein Schaltjahr war
	//9 weitere Instanzen des Typs Datum um die Warnung zu testen
	Datum morgen1(03, 05, 2022);
	Datum morgen2(03, 05, 2022);
	Datum morgen3(03, 05, 2022);
	Datum morgen4(03, 05, 2022);
	Datum morgen5(03, 05, 2022);
	Datum morgen6(03, 05, 2022);
	Datum morgen7(03, 05, 2022);
	Datum morgen8(03, 05, 2022);
	Datum morgen9(03, 05, 2022);
	Datum morgen10(03, 05, 2022);
}