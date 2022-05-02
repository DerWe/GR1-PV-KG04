#include <iostream>
#include "Datum.h"

using namespace std;

void main() {
	Datum heute(2, 5, 2022);
	cout << heute.TagDesJahres() << endl;
	cout << Datum::IstSchaltjahr(2020);  //erwarteter Output: 1, da 2020 ein Schaltjahr war
}