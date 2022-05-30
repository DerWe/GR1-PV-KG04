#include <iostream>
#include <bitset>

using namespace std;

void main(){

	//Eingegebener Buchstabe einlesen und in char speichern
	char input;
	cout << "Bitte Gross- oder Kleinbuchstabe eingeben!\n";
	cin >> input;

	//Char zu bon�r kontertieren
	bitset<8> input_binary(input);
	//cout << input_binary << endl;

	//Bin�re Maske hinterlegen
	bitset<8> mask{ 0b0010'0000 };

	// Verkn�pfung per xor
	input_binary ^= mask;
	//cout << input_binary << endl;

	//Konvertiere Bin�r zu int und caste int to char
	char output = (char)input_binary.to_ulong();

	cout << output << endl;

}