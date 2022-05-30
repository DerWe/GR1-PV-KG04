#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {

	//Zu Debug Zwecken
	//cout << argc << *argv[1] << endl;

	//Liest Kommandozeilenparameter ein und legt ihn in input
	char input = *argv[1];

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