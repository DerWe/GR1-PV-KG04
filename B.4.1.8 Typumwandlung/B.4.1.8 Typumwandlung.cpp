#include <iostream>
using namespace std;

int main()
{
	int l;
	double laenge{ 100.05 };
	char zeichen;
	// Es wird eine Zahl von double in int konvertiert, Double ist eine Kommazahl, die von Int nicht unterstützt wird. Nachkommastellen werden gerundet und weggelassen.
	l = laenge;
	// Es wird eine Zahl von Double in Char konvertiert. Die Ersten 8 Bit werden übernommen. Allerdings wird dadurch der Sinn verfälscht. Es handelt sich nicht mehr um die 1. Stelle der Zahl
	zeichen = laenge;
	cout << laenge << " " << l << " " << zeichen << endl;
	string messlatte{ "777.77" };
	// Die Zahl 777.77 wurde als string gespeichert und soll in double konvertiert werden. Allerdings gehört string nicht zu den elementaren Datentypen und wird daher von static_cast nicht unterstützt
	laenge = static_cast<double>(messlatte);
	return 1;
}