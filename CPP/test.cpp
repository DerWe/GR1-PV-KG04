#include <iostream>

using namespace std;

int get_int() {
	int input;

	cout << "Bitte eine Zahl eingeben\n";
	cin >> input;

	while (cin.fail()) {
		cout << "Meep, das war leine Zahl, Bitte nochmal\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}
	return input;
}

long long calc_fakultaet(int zahl) {
	int i = 1;
	long long fakultaet = 1;
	while (i <= zahl) {
		fakultaet *= i;
		i++;
	}
	return fakultaet;
}

long long calc_fakultaet_recursive(int zahl) {
	if (zahl == 1) {
		return 1;
	}
	else {
		return zahl * calc_fakultaet_recursive(zahl - 1);
	}
}

int main_a()
{
	int input = get_int();;

	while (input != 0) {

		if (input > 0) {
			cout << calc_fakultaet_recursive(input) << " Ist die Fakultaet von der Zahl !\n";
		}
		else if (input < 0) {
			cout << calc_fakultaet_recursive(abs(input)) << " Ist die Rekursive Fakultaet von der Zahl !\n";
		}
		else {
			cout << "Is mir egal wie die Zahl war!\n";
		}
		cin.ignore(256, '\n');
		input = get_int();
	}
	return 0;
}