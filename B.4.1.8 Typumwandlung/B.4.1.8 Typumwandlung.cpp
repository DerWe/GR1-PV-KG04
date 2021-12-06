#include <iostream>
using namespace std;

int main()
{
	int l;
	double laenge{ 100.05 };
	char zeichen;
	// Es wird eine Zahl von double in int konvertiert, Double ist eine Kommazahl, die von Int nicht unterstützt wird. Nachkommastellen werden gerundet und weggelassen
	l = laenge;
	// Es wird eine Zahl von Double in Char konvertiert. Die Ersten 8 Bit werden übernommen.
	zeichen = laenge;
	cout << laenge << " " << l << " " << zeichen << endl;
	string messlatte{ "777.77" };
	laenge = static_cast<double>(messlatte);
	return 1;
}