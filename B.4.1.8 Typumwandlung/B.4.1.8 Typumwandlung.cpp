#include <iostream>

int main()
{
	int l;
	double laenge{ 100.05 };
	char zeichen;
	l = laenge;
	zeichen = laenge;
	cout << laenge << " " << l << " " << zeichen << endl;
	string messlatte{ "777.77" };
	laenge = static_cast<double>(messlatte);
	return 1;
}