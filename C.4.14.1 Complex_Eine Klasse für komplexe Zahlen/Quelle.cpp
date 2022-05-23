#include "Complex.h"
#include <iostream>

using namespace std;

void main() {

	Complex a = Complex(12, 23);
	Complex b = Complex(-3, -4);

	cout << "Zahl A Realteil: " << a.get_realteil() << " Imaginaerteil: " << a.get_imaginaerteil() << "\n";
	cout << "Zahl B Realteil: " << b.get_realteil() << " Imaginaerteil: " << b.get_imaginaerteil() << "\n";

	cout << "Nun werden die beiden Zahlen addiert\n";
	Complex c = a + b;
	cout << "Zahl C Realteil: " << c.get_realteil() << " Imaginaerteil: " << c.get_imaginaerteil() << "\n";

	cout << "Nun werden die beiden Zahlen subtrahiert\n";
	c = a - b;
	cout << "Zahl C Realteil: " << c.get_realteil() << " Imaginaerteil: " << c.get_imaginaerteil() << "\n";

	cout << "Nun werden die beiden Zahlen dividiert\n";
	c = a / b;
	cout << "Zahl C Realteil: " << c.get_realteil() << " Imaginaerteil: " << c.get_imaginaerteil() << "\n";

	cout << "Nun wird per Setter die Zahl a veraendert\n";
	a.set_realteil(20);
	a.set_imaginaerteil(-2);
	cout << "Zahl A Realteil: " << a.get_realteil() << " Imaginaerteil: " << a.get_imaginaerteil() << "\n";

	cout << "Test des ostream: " << c << "\n";

	cout << "Test des istream, bitte zuerst real, dann imaginaerteil eingeben: \n";
	Complex d = Complex(0, 0);
	cin >> d;
	cout << "Zahl D Realteil: " << d.get_realteil() << " Imaginaerteil: " << d.get_imaginaerteil() << "\n";





}