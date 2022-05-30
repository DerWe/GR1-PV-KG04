#include <iostream>
#include <bitset>

using namespace std;

void main(){

	//Eingegebener Buchstabe einlesen und in char speichern
	char input;
	cout << "Bitte Gross- oder Kleinbuchstabe eingeben!\n";
	cin >> input;

	//Char zu bonär kontertieren
	bitset<8> input_binary(input);
	//cout << input_binary << endl;

	//Binäre Maske hinterlegen
	bitset<8> mask{ 0b0010'0000 };

	// Verknüpfung per xor
	input_binary ^= mask;
	//cout << input_binary << endl;

	//Konvertiere Binär zu int und caste int to char
	char output = (char)input_binary.to_ulong();

	cout << output << endl;

}